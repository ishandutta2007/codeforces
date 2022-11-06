#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e6 + 5;
const ll mo = 998244353;
ll n, m, k, x[NN], y[NN];
ll ax[NN];
ll ay[NN];
vector<ll> isix[NN];
vector<ll> isiy[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        for(ll i = 1; i <= n; i++)
        {
            cin >> x[i];
            ax[x[i]] = i;
        }
        for(ll i = 1; i <= m; i++)
        {
            cin >> y[i];
            ay[y[i]] = i;
        }
        vector<pll> ox;
        vector<pll> oy;
        for(ll i = 1; i <= k; i++)
        {
            ll ta, tb;
            cin >> ta >> tb;
            if((ax[ta] > 0) && (ay[tb] > 0))
                continue;
            else
            if(ax[ta] > 0)
                ox.pb(mp(ax[ta], tb));
            else
            if(ay[tb] > 0)
                oy.pb(mp(ay[tb], ta));
        }
        sort(ox.begin(), ox.end());
        ll sz = ox.size();
        for(ll i = 0; i < sz; i++)
        {
            ll L = 0;
            ll R = m;
            ll pos = ox[i].se;
            ll lok;
            while(L <= R)
            {
                ll C = (L + R) / 2;
                if(y[C] < pos)
                {
                    lok = C;
                    L = C + 1;
                }
                else
                    R = C - 1;
            }
            isiy[lok].pb(ox[i].fi);
        }

        sort(oy.begin(), oy.end());
        sz = oy.size();
        for(ll i = 0; i < sz; i++)
        {
            ll L = 0;
            ll R = n;
            ll pos = oy[i].se;
            ll lok;
            while(L <= R)
            {
                ll C = (L + R) / 2;
                if(x[C] < pos)
                {
                    lok = C;
                    L = C + 1;
                }
                else
                    R = C - 1;
            }
            isix[lok].pb(oy[i].fi);
        }

        ll has = 0;

        for(ll i = 0; i <= n; i++)
        {
            vector<pll> tmp;
            ll jum = 0;
            ll szz = isix[i].size();
            for(ll j = 0; j < szz; j++)
            {
                jum++;
                if((j + 1 == szz) || (isix[i][j] != isix[i][j + 1]))
                {
                    tmp.pb(mp(isix[i][j], jum));
                    jum = 0;
                }
            }
            ll zz = 0;
            for(ll j = 0; j < tmp.size(); j++)
            {
                // cout << tmp[j].se << " " << (szz - tmp[j].se) << "@\n";
                has += tmp[j].se * zz;
                zz += tmp[j].se;
            }
            // cout << "_\n";
        }

        for(ll i = 0; i <= m; i++)
        {
            vector<pll> tmp;
            ll jum = 0;
            ll szz = isiy[i].size();
            for(ll j = 0; j < szz; j++)
            {
                jum++;
                if((j + 1 == szz) || (isiy[i][j] != isiy[i][j + 1]))
                {
                    tmp.pb(mp(isiy[i][j], jum));
                    jum = 0;
                }
            }
            ll zz = 0;
            for(ll j = 0; j < tmp.size(); j++)
            {
                // cout << tmp[j].se << " " << (szz - tmp[j].se) << "@\n";
                has += tmp[j].se * zz;
                zz += tmp[j].se;
            }
            // cout << "_\n";
        }
        cout << has << "\n";
        for(ll i = 1; i <= n; i++)
            ax[x[i]] = 0;
        for(ll i = 1; i <= m; i++)
            ay[y[i]] = 0;
        for(ll i = 0; i <= n; i++)
            isix[i].clear();
        for(ll i = 0; i <= m; i++)
            isiy[i].clear();
    }
}