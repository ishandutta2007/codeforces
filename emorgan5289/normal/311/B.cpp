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

    T div(T x, T y) {
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

const int maxn = 100005;
ll d[maxn], h[maxn], t[maxn], dp[maxn][105];
lineset<ll> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, p; cin >> n >> m >> p;
    p = min(p, m);
    for (int i = 1; i < n; i++) {
        cin >> d[i]; d[i] += d[i-1];
    }
    ll x = 0;
    for (int i = 0; i < m; i++) {
        cin >> h[i] >> t[i];
        t[i] -= d[h[i]-1];
        x -= t[i];
    }
    sort(t, t+m);
    debug(vector(t, t+m));
    for (int k = 0; k < p; k++) {
        s.insert(-1, -x);
        for (int i = 0; i < m; i++) {
            dp[i][k] = -s.query(t[i])+i*t[i];
            if (k != 0) s.insert(i, -dp[i][k-1]);
        }
        s.clear();
    }
    cout << dp[m-1][p-1] << "\n";
}

// dp[i][k] = max_j(-dp[j][k-1] + j*t[i]) - i*t[i];