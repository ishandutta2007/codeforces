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

mt19937 randint(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 300005;
__int128_t f[maxn];
vector<ll> s;
map<__int128_t, ll> m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    for (ll i = 0; i < maxn; i++)
        f[i] = ((__int128_t)randint()<<32ll) + (__int128_t)randint();
    while (t--) {
        ll n; cin >> n;
        m.clear(); m[0]++;
        __int128_t h = 0, x = f[maxn-1];
        for (ll i = 0; i < n; i++) {
            ll a; cin >> a;
            if (s.empty() || a != s.back()) {
                s.pb(a); h = (h^x)+f[a];
            } else {
                s.pop_back(); h = (h-f[a])^x;
            }
            m[h]++;
        }
        ll r = 0;
        for (auto& [_, c] : m)
            r += c*(c-1)/2;
        cout << r << "\n";
    }
}