#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, dd, m, k, T, jj, zz[400001], in[400001], hh[400001], out[400001], ans, a[400001], bn[400001][20];
vector<ll> c[400001], v[400001];
vector<pll> vv[400001];

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

void dfs(int h,int p=0)
{
    hh[h]=hh[p]+1;
    bn[h][0]=p;
    in[h]=++T;
    for (int i = 1; i < 20; i++) bn[h][i]=bn[bn[h][i-1]][i-1];
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i], h);
        }
    out[h]=++T;
}

bool is_ancestor(int x,int y)
{
    return in[x]<=in[y] && out[x]>=out[y];
}

ll lca(ll x,ll y)
{
    if (is_ancestor(x,y)) return x;
    if (is_ancestor(y,x)) return y;
    for (int i = 19; i >-1; i--)
        if (!is_ancestor(bn[x][i], y)) x=bn[x][i];
    return bn[x][0];
}

void dfs1(int h,int p=0)
{
    sort(all(v[h]));
    sort(all(vv[h]));
    ans+=zz[h]*((ll)vv[h].size()) + zz[h]*(zz[h]-1)/2;
    ll o=((ll)vv[h].size())*((ll)vv[h].size()-1)/2;
    ll k=1;
    for (int i = 1; i < v[h].size(); i++)
    {
        if (v[h][i]!=v[h][i-1])
        {
            if (v[h][i-1]!=-1) o-=k*(k-1)/2;
            k=1;
        }else k++;
        //cout << " - " << v[h][i] << " " << k << "\n";
    }
    if ((int)v[h].size()>0 && v[h].back()!=-1)
    {
        o-=k*(k-1)/2;
        //cout << " - " << k << "\n";
    }
    k=0;
    for (int i = 0; i < vv[h].size(); i++)
    {
        if (i==0 || (i>0 && !(vv[h][i-1].fi==vv[h][i].fi && vv[h][i-1].se==vv[h][i].se)))
        {
            if (i==0 || !(vv[h][i-1].fi==-1 || vv[h][i-1].se==-1)) o+=k*(k-1)/2;
            k=1;
        }else k++;
        //cout << " " << vv[h][i].fi << " " << vv[h][i].se << " " << k << " " << "\n";
    }
    //cout << h << " " << zz[h] << " " << vv[h].size() << " " << o << "\n";
    if ((int)vv[h].size()>0 && !(vv[h].back().fi==-1 || vv[h].back().se==-1)) o+=k*(k-1)/2;
    ans+=o;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs1(c[h][i], h);
        }
}

ll dfs2(int h,int p=0)
{
    ll k=a[h];
    vector<ll> u;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            ll z=dfs2(c[h][i], h);
            k+=z;
            u.pb(z);
        }else u.pb(0);
    ans+=zz[h]*k;
    //cout << h << " " << k << " " << zz[h] << "\n";
    for (int i = 0; i < vv[h].size(); i++)
    {
        ll x=vv[h][i].fi, y=vv[h][i].se, z=k;
        if (x!=-1)
        {
            ll e=lower_bound(all(c[h]), x)-c[h].begin();
            u[e]--;
        }
        if (y!=-1)
        {
            ll e=lower_bound(all(c[h]), y)-c[h].begin();
            u[e]--;
        }
    }
    for (int i = 0; i < vv[h].size(); i++)
    {
        ll x=vv[h][i].fi, y=vv[h][i].se, z=k;
        //cout << " " << vv[h][i].fi << " " << vv[h][i].se << "\n";
        if (x!=-1)
        {
            ll e=lower_bound(all(c[h]), x)-c[h].begin();
            z-=u[e];
        }
        if (y!=-1)
        {
            ll e=lower_bound(all(c[h]), y)-c[h].begin();
            z-=u[e];
        }
        //cout << "  " << z << "\n";
        ans+=z;
    }
    return k;
}

void solve()
{
    cin >> n;
    out[0]=1e9;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    for (int i = 1; i <= n; i++) sort(all(c[i]));
    dfs(1);
    cin >> m;
    for (int it = 0; it < m; it++)
    {
        ll x, y;
        cin >> x >> y;
        ll p=lca(x, y);
        ll xx=x, yy=y;
        for (int i = 19; i > -1; i--)
            if (!is_ancestor(bn[xx][i], p)) xx=bn[xx][i];
        for (int i = 19; i > -1; i--)
            if (!is_ancestor(bn[yy][i], p)) yy=bn[yy][i];
        if (xx==p) xx=-1;
        if (yy==p) yy=-1;
        if (xx==-1 && yy==-1)
        {
            //cout << x << " " << y << "\n";
            zz[p]++;
            continue;
        }
        v[p].pb(xx);
        v[p].pb(yy);
        vv[p].pb(mp(min(xx,yy), max(xx, yy)));
        a[x]++;
        a[y]++;
        a[p]-=2;
    }
    //cout << "----\n";
    dfs1(1);
    //cout << ans << "\n";
    //cout << "----\n";
    dfs2(1);
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
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

10
4 1 7 6 5 5 4 2 3 1
*/