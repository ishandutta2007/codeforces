#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

ll n, m, x;
ll a[999], b[999], d[999];
ll c[99][99], f[99][99], h[99], e[99];

void push(ll u, ll v) {
    ll d = min(e[u], c[u][v] - f[u][v]);
    f[u][v] += d;
    f[v][u] = -f[u][v];
    e[u] -= d;
    e[v] += d;
}

void lift(ll u) {
    ll d = 9e18;
    for (ll i = 0; i < n; ++i) {
        if (c[u][i] - f[u][i] > 0) d = min(d, h[i]);
    }
    if (d != (ll)9e18) h[u] = d + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> x;
    for (ll i = 0; i < m; ++i)
        cin >> a[i] >> b[i] >> d[i];

    ld L = 0, R = 1e9;
    for (ll ttt = 0; ttt <= 100; ++ttt) {
        ld mid = (L + R) / 2;
        for (ll i = 0; i < 99; ++i) {
            h[i] = e[i] = 0;
            for (ll j = 0; j < 99; ++j) {
                c[i][j] = f[i][j] = 0;
            }
        }
        for (ll i = 0; i < m; ++i) {
            c[a[i] - 1][b[i] - 1] += min(x, ll(d[i] / mid + 1e-9));
        }
        for (ll i = 1; i < n; ++i) {
            f[0][i] = c[0][i];
            f[i][0] = -c[0][i];
        }
        h[0] = n;
        for (ll i = 1; i < n; ++i)
            e[i] = f[0][i];

        while (1) {
            ll i;
            for (i = 1; i < n - 1; ++i) {
                if (e[i] > 0) break;
            }
            if (i == n - 1) break;

            ll j;
            for (j = 0; j < n; ++j) {
                if (c[i][j] - f[i][j] > 0 && h[i] == h[j] + 1) break;
            }

            if (j < n)
                push(i, j);
            else lift(i);
        }

        ll ans = 0;
        for (ll i = 0; i < n; ++i)
            ans += f[0][i];
        if (ans >= x) L = mid;
        else R = mid;
    }
    cout << setprecision(17) << fixed << L * x;

    return 0;
}