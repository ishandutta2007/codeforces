#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = (ll) 3e5 + 7;
const ll INF = (ll) 1e18;

ll n;
ll q;
ll a[N];
ll t[4 * N][2][2];

void join(ll v)
{
    for (ll a = 0; a <= 1; a++)
    {
        for (ll b = 0; b <= 1; b++)
        {
            t[v][a][b] = max(t[2 * v][a][b], t[2 * v + 1][a][b]);
            for (ll k = 0; k <= 1; k++)
            {
                t[v][a][b] = max(t[v][a][b], t[2 * v][a][k] + t[2 * v + 1][k ^ 1][b]);
            }
        }
    }
}

void upd(ll v, ll tl, ll tr, ll i, ll x)
{
    if (tr < i || i < tl)
    {
        return;
    }
    if (tl == tr)
    {
        t[v][0][1] = 0;
        t[v][1][0] = 0;
        t[v][0][0] = x;
        t[v][1][1] = -x;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        upd(2 * v, tl, tm, i, x);
        upd(2 * v + 1, tm + 1, tr, i, x);
        join(v);
    }
}

void upd(ll i, ll x)
{
    upd(1, 1, n, i, x);
}

ll get()
{
    return max(t[1][0][0], t[1][0][1]);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            upd(i, a[i]);
        }
        cout << get() << "\n";
        for (ll i = 1; i <= q; i++)
        {
            ll p1, p2;
            cin >> p1 >> p2;
            swap(a[p1], a[p2]);
            upd(p1, a[p1]);
            upd(p2, a[p2]);
            cout << get() << "\n";
        }
    }
}