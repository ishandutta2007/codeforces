#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,tune=native")

typedef long long ll;
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
vector<T> divisors(T n) {
    vector<T> s, e;
    for (T i = 1; i <= (T)(sqrt(n)); i++)
        if (n%i == 0) {
            s.push_back(i);
            if (i*i != n) e.push_back(n/i);
        }
    for (int i = e.size()-1; i >= 0; i--)
        s.push_back(e[i]);
    return s;
}

mt19937 randint(chrono::steady_clock::now().time_since_epoch().count());

// returns a random integer over [a, b] inclusive
inline int uniform_randint(const int a, const int b) {
    return uniform_int_distribution<int>(a, b)(randint);
}

const int N = 1e6+5;
ll a[N];
map<ll, int> g;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    auto start = chrono::steady_clock::now();
    while (1) {
        ll x = a[uniform_randint(0, n-1)];
        g.clear();
        for (int j = 0; j < n; j++)
            g[__gcd(a[j], x)]++;
        for (auto& d : divisors(x)) {
            int r = 0;
            for (auto& [y, f] : g)
                if (y%d == 0) r += f;
            if (r >= (n+1)/2)
                ans = max(ans, d);
        }
        auto end = chrono::steady_clock::now();
        if (chrono::duration_cast<chrono::milliseconds>(end-start).count() > 3000)
            break;
    }
    cout << ans << "\n";
}