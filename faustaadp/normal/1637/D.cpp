#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e5 + 5;
const ll mo = 998244353;
const ll inf = (ll)1e18 + 1;
ll n, a[NN], b[NN];
ll d[10110][110];
ll p[NN];
ll depe(ll sisa, ll pos)
{
    if(pos > n)
        return 0;
    ll &ret = d[sisa][pos];
    ll A = sisa;
    ll B = p[pos] - A;
    ll h1 = A * a[pos] + B * b[pos] + depe(sisa + a[pos], pos + 1);
    ll h2 = A * b[pos] + B * a[pos] + depe(sisa + b[pos], pos + 1);
    ret = min(h1, h2);
    // cout << A << " " << B << "\n";
    // cout << sisa << " " << pos << " " << ret << "\n";
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll has = 0;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        for(ll i = 1; i <= n; i++)
            cin >> b[i];
        for(ll i = 1; i <= n; i++)
        {
            has += a[i] * a[i] * (n - 1LL);
            has += b[i] * b[i] * (n - 1LL);
        }
        for(ll i = 1; i <= n; i++)
            p[i + 1] = p[i] + a[i] + b[i];
        for(ll sisa = 0; sisa <= 10100LL; sisa++)
            d[sisa][n + 1] = 0;
        for(ll pos = n; pos >= 1; pos--)
        {
            for(ll sisa = 0; sisa <= 10000LL; sisa++)
            {
                d[sisa][pos] = min(sisa * a[pos] + (p[pos] - sisa) * b[pos] + d[sisa + a[pos]][pos + 1], 
                                   sisa * b[pos] + (p[pos] - sisa) * a[pos] + d[sisa + b[pos]][pos + 1]);
            }
            for(ll sisa = 10001LL; sisa <= 10100LL; sisa++)
                d[sisa][pos] = 1e18;
        }
        has += d[0][1] * 2LL;
        cout << has << "\n";
    }
}