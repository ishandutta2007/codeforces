#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e6 + 5;
ll n, m, k;
vector<pair<ll, pair<ll, ll> > > isi1, isi2;
vector<pair<ll, ll > > isi3;
ll a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(ll i = 0; i < m; i++)
    {
        ll ta, tb, tc, td;
        cin >> ta >> tb >> tc >> td;
        if(tc == 0)
            isi1.pb(mp(ta, mp(tb, td)));
        else
            isi2.pb(mp(ta, mp(tc, td)));
    }
    sort(isi1.begin(), isi1.end());
    sort(isi2.begin(), isi2.end());
    reverse(isi2.begin(), isi2.end());
    ll hz = 0, ban = 0, h1 = 1e18;
    for(ll i = 0; i < isi1.size(); i++)
    {
        ll idx = isi1[i].se.fi;
        hz -= a[idx];
        if(a[idx] == 0)
        {
            ban++;
            a[idx] = isi1[i].se.se;
        }
        a[idx] = min(a[idx], isi1[i].se.se);
        hz += a[idx];
        if(ban == n)
        {
            h1 = min(h1, hz);
            isi3.pb(mp(isi1[i].fi, h1));
            // cout << isi1[i].fi << " " << h1 << "\n";
        }
    }
    for(ll i = 1; i <= n; i++)
        a[i] = 0;
    hz = 0, ban = 0;
    ll h2 = 1e18;
    ll has = 1e18;
    for(ll i = 0; i < isi2.size(); i++)
    {
        ll idx = isi2[i].se.fi;
        hz -= a[idx];
        if(a[idx] == 0)
        {
            ban++;
            a[idx] = isi2[i].se.se;
        }
        a[idx] = min(a[idx], isi2[i].se.se);
        hz += a[idx];
        if(ban == n)
        {
            h2 = min(h2, hz);
            ll L = 0, R = isi3.size();
            R--;
            while(L <= R)
            {
                ll C = (L + R) / 2;
                if(isi3[C].fi + k + 1<= isi2[i].fi)
                {
                    has = min(has, h2 + isi3[C].se);
                    L = C + 1;
                }
                else
                    R = C - 1;
            }
        }
    }
    if(has == 1e18)
        has = -1;
    cout << has << "\n";
}