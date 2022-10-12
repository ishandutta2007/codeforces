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

// call randint() for a random integer
mt19937 randint(chrono::steady_clock::now().time_since_epoch().count());

// returns a random integer over [a, b] inclusive
inline int uniform_randint(const int a, const int b) {
    return uniform_int_distribution<int>(a, b)(randint);
}

// returns a random double from 0 to 1
inline double rand01() {
    return uniform_randint(0, INT_MAX)/double(INT_MAX);
}

// randomly and uniformly select k distinct integers in the range [0..n-1]
// runs in O(klog(n/k))
vector<int> random_sample(int k, int n) {
    vector<int> r(k);
    std::iota(r.begin(), r.end(), 0);
    double w = exp(log(rand01())/k);
    int i = k-1;
    while (i < n) {
        i += 1+floor(log(rand01())/log(1-w));
        if (i < n) {
            r[uniform_randint(0, k-1)] = i;
            w *= exp(log(rand01())/k);
        }
    }
    return r;
}

vector<ll> subsets(ll x) {
    vector<ll> v;
    for (ll i = x; i > 0; i = (i-1)&x)
        v.pb(i);
    v.pb(0);
    return v;
}

#define pc __builtin_popcountll

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m, p; cin >> n >> m >> p;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        string s; cin >> s;
        for (ll k = 0; k < m; k++)
            if (s[k] == '1') a[i] |= 1ll<<k;
    }
    debug(a);
    unordered_map<ll, ll> s;
    debug(subsets(9));
    for (ll k = 0; k < 30; k++)
        for (ll x : subsets(a[uniform_randint(0, n-1)]))
            s[x]++;
    vector<ll> c;
    for (auto& [x, f] : s) 
        if (f >= 10) c.pb(x);
    sort(all(c), [&](ll x, ll y){
        return pc(x) > pc(y);
    });
    for (auto& x : c) {
        debug(pc(x));
        ll f = 0;
        for (ll y : a)
            if ((x&~y) == 0) f++;
        debug(x, f);
        if (f >= (n+1)/2) {
            for (ll k = 0; k < m; k++)
                cout << (x&(1ll<<k) ? '1' : '0');
            cout << "\n";
            return 0;
        }
    }
}