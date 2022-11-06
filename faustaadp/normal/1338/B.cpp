#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll n, D[101010], x[2];
vector<ll> v[101010];
void dfs(ll pos, ll par, ll dpt)
{
    if(D[pos] == 1)
    {
        x[dpt] = 1;
    }
    else
    {
        for(ll i = 0; i < v[pos].size(); i++)
            if(v[pos][i] != par)
                dfs(v[pos][i], pos, 1 - dpt);
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
        D[ta]++;
        D[tb]++;
    }
    ll kan = n - 1; 
    ll R;
    for(ll i = 1; i <= n; i++)
        if(D[i] > 1)
        {
            R = i;
            ll hz = 0;
            for(ll j = 0; j < v[i].size(); j++)
                if(D[v[i][j]] == 1)
                    hz++;
            if(hz > 1)
                kan -= (hz - 1);
        }
    dfs(R, R, 0);
    ll kir = 1;
    if(x[0] > 0 && x[1] > 0)
        kir = 3;
    cout << kir << " " << kan << "\n";
}