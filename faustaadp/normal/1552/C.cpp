#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll t;
ll n, k;
ll d[220][220];
ll x[220];
ll y[220];
ll z[220];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(ll i = 1; i <= 2 * n; i++)
            z[i] = 0;
        vector<pair<ll, ll> > f;
        for(ll i = 1; i <= k; i++)
        {
            cin >> x[i] >> y[i];
            if(x[i] > y[i])
                swap(x[i], y[i]);
            z[x[i]] = 1;
            z[y[i]] = 1;
            f.pb(mp(x[i], y[i]));
        }
        vector<ll> o;
        for(ll i = 1; i <= 2 * n; i++)
            if(!z[i])
                o.pb(i);
        for(ll i = 0; i < n - k; i++)
            f.pb(mp(o[i], o[i + n - k]));
        // cout << f.size() << "\n";   
        ll has = 0; 
        for(ll i = 0; i < n; i++)
            for(ll j = i + 1; j < n; j++)
            {
                if(f[i].fi < f[j].fi && f[i].se > f[j].fi && f[j].se > f[i].se)
                    has++;
                if(f[j].fi < f[i].fi && f[j].se > f[i].fi && f[i].se > f[j].se)
                    has++;
            }
        cout << has << "\n";

    }
}