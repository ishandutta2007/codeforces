#include <bits/stdc++.h>
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
#define all(a) a.begin(),a.end()

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, T, i, kl, j, x, y, ans[1000001], dp[200001][2];
vector<pll> c[200001];vector<ll> vv;
bool tt[100001];

void dfs(int h,int y,int k)
{
    tt[h]=1;
    if (h==y)
    {
        for (int i = 0; i < vv.size(); i++) ans[vv[i]]=max(ans[vv[i]],(ll)k);
        return;
    }
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i].fi])
        {
            vv.pb(c[h][i].se);
            dfs(c[h][i].fi,y,k);
            vv.pop_back();
        }
}

void dfs2(int h,int y,int mx,int k)
{
    tt[h]=1;
    if (h==y)
    {
        if (mx!=k) {T=1;}
        return;
    }
    for (int i = 0 ;i < c[h].size(); i++)
        if (!tt[c[h][i].fi])
    {
        dfs2(c[h][i].fi,y,min((ll)mx,ans[c[h][i].se]),k);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(mp(y,i));
        c[y].pb(mp(x,i));
    }
    cin >> m;
    vector <pair<ll,pll> >  v;
    for (int i = 1; i <= m; i++)
    {
        ll x, y, h;
        cin >> x >> y >> h;
        v.pb(mp(h,mp(x,y)));
    }
    sort(all(v));
    for (int i = 0; i < m; i++)
    {
        ll x=v[i].se.fi, y=v[i].se.se, k=v[i].fi;
        for (int j = 1;j <= n; j++) tt[j]=0;
        vv.clear();
        dfs(x,y,k);
    }
    for (int i = 0; i < m; i++)
    {
        ll x=v[i].se.fi, y=v[i].se.se, k=v[i].fi;
        for (int j = 1 ;j <= n; j++) tt[j]=0;
        vv.clear();
        dfs2(x,y,1e9,k);
    }
    //for (int i = 1; i < n; i++) cout << ans[i] << " ";
    if (T) cout << "-1\n";else
    for (int i = 1; i < n; i++) cout << max(ans[i],1ll) << " ";
    return 0;
}
/*
6 4
1 2
6 5
3 2
4 5
*/