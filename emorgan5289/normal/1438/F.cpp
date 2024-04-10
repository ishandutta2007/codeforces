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

ll query(ll x, ll y, ll z) {
    cout << "? " << x+1 << " " << y+1 << " " << z+1 << endl;
    ll r; cin >> r;
    if (r == -1) exit(0);
    return r-1;
}

void submit(ll x) {
    cout << "! " << x+1 << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll h; cin >> h;
    ll n = (1ll<<h)-1;
    map<array<ll, 2>, map<ll, ll>> m;
    for (int i = 0; i < 20; i++) {
        ll x = 0, y = 0;
        while (x == y || m.count({x, y})) {
            x = uniform_randint(0, n-1);
            y = uniform_randint(0, n-1);
            if (x > y) swap(x, y);
        }
        for (int j = 0; j < 20; j++) {
            ll p = x;
            set<ll> vis;
            while (p == x || p == y || vis.count(p)) {
                p = uniform_randint(0, n-1);
            }
            vis.insert(p);
            m[{x, y}][query(x, y, p)]++;
        }
    }
    vector<array<ll, 3>> score;
    for (auto& [v, p] : m) {
        auto& [x, y] = v;
        ll s = 0;
        for (auto& [q, r] : p)
            cmax(s, r);
        score.pb({s, x, y});
    }
    auto& [s, x, y] = *min_element(all(score));
    map<ll, ll> c;
    for (int i = 0; i < n; i++)
        if (i != x && i != y) {
            c[query(x, y, i)]++;
        }
    for (int i = 0; i < n; i++)
        if (i != x && i != y && c[i] == 1)
            submit(i);
    // while (1) {}
}