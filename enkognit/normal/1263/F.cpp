#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

ll n, m, T, k, l, r, i, j, sum, kol=0, a[1000001], g[1000001], an1[1000001], an2[1000001];
pll d1[10000001], d2[1000001];
ll tt1[1001][1001], tt2[1001][1001];
ll dp[10001];
map<string,bool> w;
vector <ll> c[300001];
vector <ll> b[300001];
bool t1[1000001], t2[1000001];

void dfs1(ll h)
{
    ll mn=1e18, mx=0;
    if (a[h]) mn=a[h], mx=a[h];
    an1[h]=(h!=1);
    for (int i = 0; i < c[h].size(); i++)
    {
        dfs1(c[h][i]);
        an1[h]+=an1[c[h][i]];
        mn=min(mn,d1[c[h][i]].fi);
        mx=max(mx,d1[c[h][i]].se);
    }
    d1[h]=mp(mn,mx);
    tt1[mn][mx]=max(tt1[mn][mx],an1[h]);
}

void dfs2(ll h)
{
    ll mn=1e18, mx=0;
    if (g[h]) mn=g[h], mx=g[h];
    an2[h]=(h!=1);
    for (int i = 0; i < b[h].size(); i++)
    {
        dfs2(b[h][i]);
        an2[h]+=an2[b[h][i]];
        mn=min(mn,d2[b[h][i]].fi);
        mx=max(mx,d2[b[h][i]].se);
    }
    d2[h]=mp(mn,mx);
    //if (h==6) cout << mn << " " << mx << " " << an2[h] << "\n";
    tt2[mn][mx]=max(tt2[mn][mx],an2[h]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> m;
    for (int i = 1; i < m; i++) {ll x;cin >> x;c[x].pb(i+1);}
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[x]=i+1;
    }
    dfs1(1);
    cin >> k;
    for (int i = 1; i < k; i++) {ll x;cin >> x;b[x].pb(i+1);}
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        g[x]=i+1;
    }
    dfs2(1);
    for (int i = 0; i < n; i++)
    {
        //cout << dp[i] << "\n";
        for (int j = i+1; j <= n; j++)
        {
            dp[j]=max(dp[j],dp[i]+max(tt1[i+1][j],tt2[i+1][j]));
        }
    }
    cout << dp[n];
    return 0;
}
/*
5 6
X...XX
XX...X
......
..XX..
XXX..X
*/