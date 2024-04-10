#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 2e5 + 5;
ll n, mx, R, jaw1, jaw2, jaw3;
ll dep[NN], dalam[NN];
vector<ll> v[NN];
void dfs(ll pos, ll par, ll jar)
{
    if(jar > mx)
    {
        mx = jar;
        R = pos;
    }
    for(ll i = 0; i < v[pos].size(); i++)
        if(v[pos][i] != par)
            dfs(v[pos][i], pos, jar + 1);
}
void dfs2(ll pos, ll par)
{
    dalam[pos] = pos;
    dep[pos] = dep[par] + 1;
    vector<pair<ll, ll > > z; 
    for(ll i = 0; i < v[pos].size(); i++)
        if(v[pos][i] != par)
        {
            dfs2(v[pos][i], pos);
            if(dep[dalam[pos]] < dep[dalam[v[pos][i]]])
                dalam[pos] = dalam[v[pos][i]];
            z.pb(mp(dep[dalam[v[pos][i]]], dalam[v[pos][i]]));
        }
    // cout << pos << " __ " << dalam[pos] << "\n";
    sort(z.begin(), z.end());
    reverse(z.begin(), z.end());
    if(z.empty())
        return ;
    ll ban;
    if(pos != R && (z.size() == 1))
    {
        ban = z[0].fi;
        if(ban > mx)
        {
            mx = ban;
            jaw1 = R;
            jaw2 = pos;
            jaw3 = z[0].se;
        } 
        
    }
    if(z.size() == 1)
        return ;
    // cout << pos << " " << z[0].fi << " " << z[1].fi << "\n";
    ban = dep[pos] + (z[0].fi - dep[pos]) + (z[1].fi - dep[pos]);
    if(ban > mx)
    {
        mx = ban;
        jaw1 = R;
        jaw2 = z[0].se;
        jaw3 = z[1].se;
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
        v[tb].pb(ta);
    }
    dfs(1, 1, 0);
    mx = 0;
    dep[R] = -1;
    dfs2(R, R);
    cout << mx << "\n" << jaw1 << " " << jaw2 << " " << jaw3 << "\n";
    
}