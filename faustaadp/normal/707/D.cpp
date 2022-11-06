#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll n, m, q, banyak, jaw[NN];
ll a[1010][1010];
ll x[NN], y[NN], tipe[NN];
vector<ll> v[NN];
void dfs(ll pos)
{
    jaw[pos] = banyak;
    for(ll i = 0; i < v[pos].size(); i++)
    {
        if(tipe[v[pos][i]] < 4)
        {
            if(tipe[pos + 1] == 1)
            {
                if(a[x[pos + 1]][y[pos + 1]] == 1)
                    dfs(v[pos][i]);
                else
                {
                    banyak++;
                    a[x[pos + 1]][y[pos + 1]] = 1;
                    dfs(v[pos][i]);
                    a[x[pos + 1]][y[pos + 1]] = 0;
                    banyak--;
                }
            }
            else
            if(tipe[pos + 1] == 2)
            {
                if(a[x[pos + 1]][y[pos + 1]] == 0)
                    dfs(v[pos][i]);
                else
                {
                    banyak--;
                    a[x[pos + 1]][y[pos + 1]] = 0;
                    dfs(v[pos][i]);
                    a[x[pos + 1]][y[pos + 1]] = 1;
                    banyak++;
                }
            }
            else
            {
                for(ll j = 1; j <= m; j++)
                {
                    if(a[x[pos + 1]][j])
                        banyak--;
                    else
                        banyak++;
                    a[x[pos + 1]][j] ^= 1;
                }
                dfs(v[pos][i]);
                for(ll j = 1; j <= m; j++)
                {
                    if(a[x[pos + 1]][j])
                        banyak--;
                    else
                        banyak++;
                    a[x[pos + 1]][j] ^= 1;
                }
            }
        }
        else
            dfs(v[pos][i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    for(ll i = 1; i <= q; i++)
    {
        cin >> tipe[i];
        cin >> x[i];
        if(tipe[i] <= 2)
            cin >> y[i];
        if(tipe[i] == 4)
            v[x[i]].pb(i);
        else
            v[i - 1].pb(i);
    }
    dfs(0);
    for(ll i = 1; i <= q; i++)
        cout << jaw[i] << "\n";
}