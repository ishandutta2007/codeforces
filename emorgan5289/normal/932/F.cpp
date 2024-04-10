#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<typename T>
struct lineset {

    struct line {
        mutable T m, b, p;
        bool operator<(const line& o) const { return m < o.m; }
        bool operator<(T x) const { return p < x; }
    };

    multiset<line, less<>> hull;
    using it = decltype(hull.end());
    const static T max_T = numeric_limits<T>::max();
    const static T min_T = numeric_limits<T>::min();

    static T div(T x, T y) {
        return x/y - (is_integral<T>::value ? ((x^y) < 0 && x%y) : 0);
    }

    bool isect(it x, it y) {
        if (y == hull.end())
            return (x->p = max_T, 0);
        if (x->m == y->m)
            x->p = x->b > y->b ? max_T : min_T;
        else
            x->p = div(y->b - x->b, x->m - y->m);
        return x->p >= y->p;
    }

    // remove all lines from the set
    void clear() {
        hull.clear();
    }

    // insert the line mx+b into the set, runs in O(logn).
    void insert(T m, T b) {
        it z = hull.insert({m, b, 0}), y = z++, x = y;
        while (isect(y, z)) z = hull.erase(z);
        if (x != hull.begin() && isect(--x, y))
            isect(x, y = hull.erase(y));
        while ((y = x) != hull.begin() && (--x)->p >= y->p)
            isect(x, hull.erase(y));
    }

    // returns the maximum value of mx+b over all lines in the set, runs in O(logn).
    T query(T x) const {
        auto [m, b, _] = *hull.lower_bound(x);
        return m*x + b;
    }
};

const int N = 1e5+5;
ll a[N], b[N], s[N], dp[N];
vector<int> adj[N];
lineset<ll> l[N];

void ins(int i, int p, int r) {
    l[r].insert(-b[i], -dp[i]);
    for (auto& j : adj[i])
        if (j != p) ins(j, i, r);
}

void dfs(int i, int p) {
    int k = -1;
    s[i] = 1;
    for (auto& j : adj[i])
        if (j != p) {
            dfs(j, i);
            s[i] += s[j];
            if (k == -1 || s[j] > s[k]) k = j;
        }
    if (k != -1) l[i].hull = move(l[k].hull);
    for (auto& j : adj[i])
        if (j != p && j != k)
            ins(j, i, i);
    if (k != -1) dp[i] = -l[i].query(a[i]);
    else dp[i] = 0;
    l[i].insert(-b[i], -dp[i]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(0, 0);
    for (int i = 0; i < n; i++)
        cout << dp[i] << " \n"[i == n-1];
}