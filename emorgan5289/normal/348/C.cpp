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

const ll N = 100005, s = 350;
ll a[N], b[N], c[N], p[N];
int o[s+5][N];
vector<int> v[N], h, w[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, q; cin >> n >> m >> q;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++) {
        ll k; cin >> k;
        v[i].resize(k);
        for (ll j = 0; j < k; j++) {
            cin >> v[i][j], v[i][j]--;
            c[i] += a[v[i][j]];
        }
        if (k > s)
            h.pb(i), p[i] = h.size()-1;
    }
    fill(a, a+N, 0);
    for (ll i = 0; i < h.size(); i++) {
        for (auto& j : v[h[i]])
            w[j].pb(i);
    }
    for (ll i = 0; i < m; i++) {
        for (auto& j : v[i])
            for (auto& k : w[j])
                o[k][i]++;
    }
    while (q--) {
        char t; cin >> t;
        if (t == '+') {
            ll k, x; cin >> k >> x; k--;
            if (v[k].size() > s) {
                b[k] += x;
            } else {
                for (auto& i : v[k])
                    a[i] += x;
                for (ll i = 0; i < h.size(); i++)
                    c[h[i]] += x*o[i][k];
            }
        } else {
            ll k; cin >> k; k--;
            ll out = c[k];
            debug(v[k]);
            if (v[k].size() <= s)
                for (auto& i : v[k])
                    out += a[i];
            for (ll i = 0; i < h.size(); i++)
                out += b[h[i]]*o[i][k];
            cout << out << "\n";
        }
    }
}