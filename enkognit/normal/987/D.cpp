#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fr front()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

const ll mod=1e9+7;

ll n, m, k, s;
queue <pll> q[101];
vector <ll> v[100001], c[100001];
bool t[101][100001];

int main()
{
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m >> k >> s;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        q[x].push(mp(i+1,0));
    }
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    for (int i = 1; i <= k; i++)
    {
        while (!q[i].empty())
        {
            ll x=q[i].fr.fi, h=q[i].fr.se;
            q[i].pop();
            if (t[i][x]) continue;
            t[i][x]=1;
            v[x].pb(h);
            for (int j = 0; j < c[x].size(); j++)
                if (!t[i][c[x][j]])
                {
                    q[i].push(mp(c[x][j],h+1));
                }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(),v[i].end());
        ll ans=0;
        for (int j = 0; j < s; j++) ans+=v[i][j];
        cout << ans << " ";
    }
    return 0;
}