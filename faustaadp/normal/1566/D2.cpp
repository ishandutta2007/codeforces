#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld; 
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll n, m;
ll a[330][330];
ll BIT[330][330];
pll lok[NN];
pll A[NN];
pll pos[NN];
void upd(ll z, ll idx)
{
    for(ll i = z; i <= m; i += (i & -i))
        BIT[idx][i]++;
}
ll que(ll z, ll idx)
{
    ll ret = 0;
    for(ll i = z; i > 0; i -= (i & -i))
        ret += BIT[idx][i];
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        // for(ll i = 1; i <= n; i++)
            // BIT[i] = 0;
        ll te = 0;
        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= m; j++)
                BIT[i][j] = 0;
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                te++;
                A[te] = mp(a[i][j], te);
                lok[te] = mp(i, j);
            }
        }
        sort(A + 1, A + 1 + (n * m));
        for(ll i = 1; i <= (n * m); i++)
        {
            ll R = i;
            vector<ll> y;
            vector<pll> z;
            for(ll j = i; j <= (n * m); j++)
            {
                if(A[j].fi != A[i].fi)
                    break;
                y.pb(A[j].se);
                z.pb(mp(lok[j].fi, -lok[j].se));
                R = j;
            }
            sort(y.begin(), y.end());
            sort(z.begin(), z.end());
            ll sz = z.size();
            for(ll j = 0; j < sz; j++)
            {
                // cout << y[i] << "@\n";
                pos[y[j]] = mp(z[j].fi, -z[j].se);
            }
            // cout << i << " " << R <<  "_\n";
            i = R;
        }
        ll has = 0;
        for(ll i = 1; i <= n * m; i++)
        {
            // cout << "(" << pos[i].fi << "," << pos[i].se << ")\n";
            has += que(pos[i].se, pos[i].fi);
            upd(pos[i].se, pos[i].fi);
        }
        cout << has << "\n";
    }
}