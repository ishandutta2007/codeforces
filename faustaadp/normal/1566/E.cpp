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
ll n, has;
ll b[NN];
ll D[NN];
vector<ll> v[NN];
ll hei[NN];
void dfs(ll pos, ll par)
{
    ll ada = 0;
    for(ll i = 0; i < v[pos].size(); i++)
    {
        if(v[pos][i] != par)
        {
            dfs(v[pos][i], pos);
            if(b[v[pos][i]] == 0)
                ada = 1;
        }
    }
    if(ada == 1 && pos > 1)
        b[pos] = 1;
    else
    if(pos > 1 && D[pos] > 1)
    {
        // cout << "hai\n";
        ll ade = 0;
        for(auto nx : v[pos])
        {
            if(nx == par)
                continue;
            if(b[nx] == 0)
                ade = 1;
        }
        if(!ade)
        {
            hei[pos] = 1;
            // gla = 1;
            // cout << pos << "_\n";
            has++;
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        // gla = 0;
        cin >> n;
        for(ll i = 1; i <= n; i++)
        {
            b[i] = 0;
            D[i] = 0;
            hei[i] = 0;
            v[i].clear();
        }
        for(ll i = 1; i < n; i++)
        {
            ll ta, tb;
            cin >> ta >> tb;
            v[ta].pb(tb);
            v[tb].pb(ta);
            D[ta]++;
            D[tb]++;
        }
        ll leaf = 0;
        ll ada = 0;
        for(ll i = 0; i < v[1].size(); i++)
            if(D[v[1][i]] == 1)
                ada = 1;
        for(ll i = 2; i <= n; i++)
            if(D[i] == 1)
                leaf++;
        has = leaf;
        dfs(1, 1);
        for(ll i = 2; i <= n; i++)
            if(b[i])
                has--;
        for(ll i = 0; i < v[1].size(); i++)
            if(hei[v[1][i]] == 1)
                ada = 1;
        if(ada == 0)
            has++;
        cout << has << "\n";
    }
}