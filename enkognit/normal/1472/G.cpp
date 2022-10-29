#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit
#define all(v) v.begin(),v.end()

using namespace std;
using namespace __gnu_pbds;

const ll MOD=1e9+7;

ll n, m, k, q, T, dist[200005], ans[200005];
vector<ll> c[200005];
bool tt[200001];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%MOD;
        h=(h*h)%MOD;
        r/=2;
    }
    return l;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1 ;i <= n; i++) c[i].clear();
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
    }
    queue<ll> q;
    for (int i = 1; i <= n; i++) dist[i]=1e9;
    dist[1]=0;
    q.push(1);
    while (!q.empty())
    {
        ll h=q.front();
        q.pop();
        for (int i = 0; i < c[h].size(); i++)
            if (dist[c[h][i]]>dist[h]+1)
            {
                dist[c[h][i]]=dist[h]+1;
                q.push(c[h][i]);
            }
    }
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        v.pb(mp(dist[i], i));
    }
    sort(all(v));
    reverse(all(v));
    for (int i = 0; i < v.size(); i++)
    {
        ll h=v[i].se;
        ans[h]=dist[h];
        for (int j = 0; j < c[h].size(); j++)
            if (dist[c[h][j]]>dist[h]) ans[h]=min(ans[h], ans[c[h][j]]); else ans[h]=min(ans[h], dist[c[h][j]]);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
3 2
0 1
1 2
1 2
2 3
2 3
3 4
1 2
2 3

3 4
0 0 0 0
1 1 1 1
1 1 1 1
2 2 2 2
0 0 0 0
2 3 2 3
1 3
2 3
*/
/*

}


*/