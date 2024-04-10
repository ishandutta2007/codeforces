#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const ll N = 500005, S = 800;
ll a[S][S], c[S];
multiset<ll> f[S];

void inc(ll i, ll x) {
    ll& y = a[i/S][i%S];
    f[i/S].erase(f[i/S].find(y));
    y += x;
    f[i/S].insert(y);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    for (ll i = 0; i < n; i++) {
        cin >> a[i/S][i%S];
        f[i/S].insert(a[i/S][i%S]);
    }
    while (q--) {
        ll t; cin >> t;
        if (t == 1) {
            ll l, r, x; cin >> l >> r >> x; l--, r--;
            if (l/S == r/S)
                for (ll i = l; i <= r; i++)
                    inc(i, x);
            else {
                for (ll i = l/S+1; i < r/S; i++)
                    c[i] += x;
                for (ll i = l; i < (l/S+1)*S; i++)
                    inc(i, x);
                for (ll i = (r/S)*S; i <= r; i++)
                    inc(i, x);
            }
        } else {
            ll y; cin >> y;
            ll l = inf, r = -inf;
            debug(vector(a[0], a[0]+5));
            for (ll i = 0; i <= (n-1)/S; i++)
                if (f[i].find(y-c[i]) != f[i].end())
                    l = min(l, i*S), r = max(r, (i+1)*S-1);
            if (l == inf)
                cout << "-1\n";
            else {
                while (a[l/S][l%S] != y-c[l/S]) l++;
                while (a[r/S][r%S] != y-c[r/S]) r--;
                cout << r-l << "\n";
            }
        }
    }
}