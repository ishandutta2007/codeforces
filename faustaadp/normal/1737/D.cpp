#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
const ll mo = 1e9 + 7;
ll n, m, dis[550][550];
ll Z[550][550];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= n; j++)
            {
                Z[i][j] = 1e18;
                if(i == j)
                    dis[i][j] = 0;
                else
                    dis[i][j] = 1e18;
            }
        for(ll i = 1; i <= m; i++)
        {
            ll ta, tb, tc;
            cin >> ta >> tb >> tc;
            Z[ta][tb] = min(Z[ta][tb], tc);
            Z[tb][ta] = min(Z[tb][ta], tc);
            dis[ta][tb] = 1;
            dis[tb][ta] = 1;
        }
        ll has = 1e18;
        for(ll k = 1; k <= n; k++)
            for(ll i = 1; i <= n; i++)
                for(ll j = 1; j <= n; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        for(ll i = 1; i <= n; i++)
            for(ll j = i + 1; j <= n; j++)
            {
                if(Z[i][j] == 1e18)
                    continue;
                ll jar = 1e18;
                // if(i == 1)
                //     jar = dis[j][n];
                // else
                // if(j == n)
                //     jar = dis[i][1];
                // else
                {
                    for(ll k = 1; k <= n; k++)
                    {
                        jar = min(jar, min(dis[i][k], dis[j][k]) + dis[1][k] + dis[n][k] + 1);
                        jar = min(jar, dis[1][j] + dis[n][i]);
                        jar = min(jar, dis[1][i] + dis[n][j]);
                    }
                }
                // cout << i << " " << j << " " << jar << "_\n";
                jar++;
                jar *= Z[i][j];
                has = min(has, jar);
            }
        cout << has << "\n";
    }
}