#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll n, k, i, has;
ll sub[202020];
vector<ll> v[202020], isi;
void dfs(ll pos, ll par, ll dep)
{
    sub[pos] = 1;
    for(ll i = 0; i < v[pos].size(); i++)
        if(v[pos][i] != par)
        {
            dfs(v[pos][i], pos, dep + 1);
            sub[pos] += sub[v[pos][i]];
        }
    isi.pb(dep - sub[pos]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n >> k;
    for(ll i = 1; i < n; i++)
    {
        ll ta, tb;
        cin >> ta >> tb;
        v[ta].pb(tb);
        v[tb].pb(ta);
    }
    dfs(1, 1, 1);
    sort(isi.begin(), isi.end());
    reverse(isi.begin(), isi.end());
    for(ll i = 0; i < k; i++)
        has += isi[i];
    cout << has << "\n";
}