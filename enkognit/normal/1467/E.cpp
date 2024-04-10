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
#define all(v) v.begin(),v.end()

using namespace std;

const ll MOD=1e9+7;

int n, m, k, q, T, ans=0, a[200005], in[200005], out[200005], kk, nw[200005], lc[200005], bn[200005][20];
vector<int> c[200005];
bool tl[200005];
vector<int> v[200005];

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

void dfs(int h,int p=0)
{
    T++;
    in[h]=T;
    v[a[h]].pb(in[h]);
    bn[h][0]=p;
    for (int i = 1; i < 19; i++) bn[h][i]=bn[bn[h][i-1]][i-1];
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i], h);
        }
    T++;
    out[h]=T;
    v[a[h]].pb(out[h]);
}

bool is_ancestor(int x,int y)
{
    return in[x]<=in[y] && out[x]>=out[y];
}

ll lca(int x,int y)
{
    if (is_ancestor(x, y)) return x;
    if (is_ancestor(y, x)) return y;
    for (int i = 18; i > -1; i--)
        if (!is_ancestor(bn[x][i], y)) x=bn[x][i];
    return bn[x][0];
}

void dfs2(int h,int p=0)
{
    if (lc[a[h]]==0) lc[a[h]]=h; else lc[a[h]]=lca(lc[a[h]], h);
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs2(c[h][i], h);
        }
}

void dfs3(int h,int k=0,int p=-1)
{
    k+=nw[h];
    if (k==kk) ans++;
    //cout << k << "\n";
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs3(c[h][i], k, h);
        }
}

void solve()
{
    cin >> n;
    out[0]=1e9;
    vector<pii> zz;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        zz.pb(mp(a[i], i));
    }
    sort(all(zz));
    kk=0;
    for (int i = 0; i < zz.size(); i++)
    {
        if (i==0 || zz[i].fi!=zz[i-1].fi) kk++;
        a[zz[i].se]=kk;
    }
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs(1);
    dfs2(1);
    for (int i = 1; i <= kk; i++)
        if (a[lc[i]]==i)
        {
            tl[lc[i]]=1;
            if (v[i].size()>2)
            {
                ll h=lc[i];
                ll t=0;
                for (int j = 0; j < c[h].size(); j++)
                    if (v[i][1]>=in[c[h][j]] && v[i][v[i].size()-2]<=out[c[h][j]] && in[c[h][j]]>=in[h]) t=j+1;
                if (!t)
                {
                    cout << "0\n";
                    exit(0);
                }
                nw[c[h][t-1]]++;
            } else nw[1]++;
        }else nw[1]++;
    for (int i = 1; i <= n; i++)
        if (!tl[i])
        {
            ll z=upper_bound(all(v[a[i]]), in[i])-v[a[i]].begin();
            nw[i]--;
            if (v[a[i]][z]<out[i])
            {
                cout << "0\n";
                exit(0);
            }
        }
    dfs3(1);
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
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