#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e6 + 5;
ll n, hz;
vector<pair<ll, ll> > isi;
vector<ll> v[NN], w[NN];
void dfs1(ll pos, ll par)
{  
    for(ll i = 0; i < v[pos].size(); i++)
        if(v[pos][i] != par)
        {
            hz += (w[pos][i] == 0);
            dfs1(v[pos][i], pos);
        }
}
void dfs2(ll pos, ll par)
{  
    // cout << pos << "  " << hz << "\n";
    isi.pb(mp(hz, pos));
    for(ll i = 0; i < v[pos].size(); i++)
        if(v[pos][i] != par)
        {
            hz += w[pos][i];
            hz -= (w[pos][i] == 0);
            dfs2(v[pos][i], pos);
            hz -= w[pos][i];
            hz += (w[pos][i] == 0);
        }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i < n; i++)
    {
        ll ta, tb;
        cin >> ta >> tb;
        v[ta].pb(tb);
        w[ta].pb(1);
        v[tb].pb(ta);
        w[tb].pb(0);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    sort(isi.begin(), isi.end());
    cout << isi[0].fi << "\n";
    for(ll i = 0; i < isi.size(); i++)
    {
        if(isi[i].fi != isi[0].fi)
            break;
        cout << isi[i].se << " ";
    }
    cout << "\n";
}