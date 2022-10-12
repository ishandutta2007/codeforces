#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

// templated version of the KACTL LineContainer data structure.
// see https://github.com/kth-competitive-programming/kactl/blob/master/content/data-structures/LineContainer.h

template<typename T>
struct lineset {

    struct line {
        mutable T m, b, p;
        bool operator<(const line& o) const { return m < o.m; }
        bool operator<(T x) const { return p < x; }
    };

    multiset<line, less<>> hull;
    using it = decltype(hull.end());
    constexpr static T max_T = numeric_limits<T>::max();
    constexpr static T min_T = numeric_limits<T>::min();

    static T div(T x, T y) {
        if constexpr (!is_integral<T>::value) return x/y;
        else return x/y - ((x^y) < 0 && x%y);
    }

    bool isect(it x, it y) {
        if (y == hull.end())
            return x->p = max_T, 0;
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

vector<vector<int>> adj;
vector<ll> s, dp;
lineset<ll> l;
ll n, ans = inf_ll;

void dfs(int i, int k) {
    for (int j : adj[i])
        if (j != k) {
            dfs(j, i);
            s[i] += s[j];
        }
    dp[i] = s[i]*(s[i]-1)/2;
    l.clear();
    for (int j : adj[i])
        if (j != k) {
            cmin(dp[i], dp[j]+(s[i]-s[j])*(s[i]-s[j]-1)/2);
            ll x = dp[j]-n*s[j]+(s[j]+1)*s[j]/2;
            debug(x);
            if (!l.hull.empty()) {
                debug(n*(n-1)/2, x, -l.query(s[j]));
                cmin(ans, n*(n-1)/2+x-l.query(s[j]));
                debug(i, j, ans);
            }
            debug(j, s[j], x);
            l.insert(-s[j], -x);
        }
    debug(i, dp[i]);
    // dp[x]+dp[y]+(s[i]-s[x]-s[y])*(s[i]-s[x]-s[y]-1)/2;
    // + s[x]*s[y]
    // a[i]+a[j]+b[i]*b[j]
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n == 2) {
        cout << "2\n";
        exit(0);
    }
    adj.resize(n);
    dp.assign(n, 0);
    s.assign(n, 1);
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    for (int i = 0; i < n; i++)
        if (adj[i].size() > 1) {
            dfs(i, i);
            break;
        }
    debug(ans);
    cout << n*(n-1)-ans << "\n";
}