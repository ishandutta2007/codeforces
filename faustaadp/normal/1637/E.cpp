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
ll n, a[NN], m, x[NN], nil[NN], y2[NN];
vector<ll> v[NN];
vector<ll> g[NN];
vector<ll> dil[NN];
ll boo[NN], bote;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        ll k = 0;
        map<ll, ll> me2;
        map<ll, ll> y;
        for(ll i = 1; i <= n; i++)
        {
            y[i] = 0;
            y2[i] = 0;
            g[i].clear();
            v[i].clear();
        }
        vector<ll> zz;
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            y[a[i]]++;
            if(y[a[i]] == 1)
            {
                k++;
                zz.pb(a[i]);
            }
        }
        sort(zz.begin(), zz.end());
        for(ll i = 0; i < zz.size(); i++)
            me2[zz[i]] = i + 1;
        for(ll i = 1; i <= n; i++)
        {
            x[i] = me2[a[i]];
            nil[me2[a[i]]] = a[i];
        }
        for(ll i = 1; i <= n; i++)
        {
            if(y[a[i]])
            {
                v[y[a[i]]].pb(x[i]);
                y2[x[i]] = y[a[i]];
                y[a[i]] = 0;
            }
        }
        for(ll i = 1; i <= k; i++)
            g[i].pb(i);
        for(ll i = 1; i <= m; i++)
        {
            ll ta, tb;
            cin >> ta >> tb;
            ta = me2[ta];
            tb = me2[tb];
            g[ta].pb(tb);
            g[tb].pb(ta);
        }
        vector<ll> isi;
        for(ll i = 1; i <= n; i++)
            if(!v[i].empty())
            {
                sort(v[i].begin(), v[i].end());
                reverse(v[i].begin(), v[i].end());
                isi.pb(i);
            }
        ll has = 0;
        // for(ll i = 1; i <= k; i++)
            // cout << i << " " << nil[i] << " " << y2[i]<< " __\n";
        for(ll i = 1; i <= k; i++)
        {
            bote++;
            for(auto z : g[i])
            {
                // cout << i << " " << y2[z] << " " << z << "@@\n";
                if(boo[y2[z]] != bote)
                    dil[y2[z]].clear();
                boo[y2[z]] = bote;
                dil[y2[z]].pb(z);
            }
            for(auto z : isi)
            {
                ll Z = 0;
                if(boo[z] == bote)
                {
                    if(dil[z].size() == v[z].size())
                        continue;
                    // cout << dil[z].size() << " serta " << v[z].size() << "\n";
                    // cout << z << " hai\n";
                    sort(dil[z].begin(), dil[z].end());
                    reverse(dil[z].begin(), dil[z].end());
                    ll sz = dil[z].size();
                    Z = sz;
                    for(ll j = 0; j < sz; j++)
                    {
                        // cout << dil[z][j] << " dan " << v[z][j] << "_\n";
                        if(dil[z][j] != v[z][j])
                        {
                            Z = j;
                            break;
                        }
                    }
                }
                // cout << nil[i] << " " << nil[v[z][Z]] << " " << Z << "   " << y2[i] << " " << z << "\n";    
                has = max(has, (y2[i] + z) * (nil[i] + nil[v[z][Z]]));
            }
            // cout << i << " " << nil[i] << " " << me2[nil[i]] << "\n";
        }
        cout << has << "\n";
        // cout << "\n";
    }
}