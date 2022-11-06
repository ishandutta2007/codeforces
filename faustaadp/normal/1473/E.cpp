#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 2e5 + 5;
ll n, m;
vector<ll> v[NN];
vector<ll> w[NN];
ll dis[NN][4];
ll b[NN][4];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= m; i++)
    {
        ll ta, tb, tc;
        cin >> ta >> tb >> tc;
        v[ta].pb(tb);
        w[ta].pb(tc);
        v[tb].pb(ta);
        w[tb].pb(tc);
    }
    priority_queue<pair<ll, pair<ll, ll> > > pq;
    pq.push(mp(0, mp(1, 0)));
    for(ll i = 1; i <= n; i++)
        for(ll j = 0; j < 4; j++)
            dis[i][j] = 1e18;
    dis[1][0] = 0;
    while(!pq.empty())
    {
        ll jar = -pq.top().fi;
        ll pos = pq.top().se.fi;
        ll jen = pq.top().se.se;
        pq.pop();
        if(b[pos][jen])
            continue;
        b[pos][jen] = 1;
        for(ll i = 0; i < v[pos].size(); i++)
        {
            ll nx = v[pos][i];
            ll nx2 = jen;
            if(dis[nx][nx2] > jar + w[pos][i])
            {
                dis[nx][nx2] = jar + w[pos][i];
                pq.push(mp(-dis[nx][nx2], mp(nx, nx2)));
            }
            if(jen == 0)
            {
                nx2 = 3;
                if(dis[nx][nx2] > jar + w[pos][i])
                {
                    dis[nx][nx2] = jar + w[pos][i];
                    pq.push(mp(-dis[nx][nx2], mp(nx, nx2)));
                }
            }
            if((jen & 1)== 0)
            {
                nx2 = jen | 1;
                if(dis[nx][nx2] > jar)
                {
                    dis[nx][nx2] = jar;
                    pq.push(mp(-dis[nx][nx2], mp(nx, nx2)));
                }
            }
            if((jen & 2) == 0)
            {
                nx2 = jen | 2;
                if(dis[nx][nx2] > jar + w[pos][i] + w[pos][i])
                {
                    dis[nx][nx2] = jar + w[pos][i] + w[pos][i];
                    pq.push(mp(-dis[nx][nx2], mp(nx, nx2)));
                }
            }
        }
    }
    for(ll i = 2; i <= n; i++)
        cout << dis[i][3] << " ";
    cout << "\n";
}