#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("popcnt")
#include <random>
#include <time.h>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, T, mx, ans, in[300001], out[300001], nm[800001];
vector<ll> c[300001], g[300001];

void dfs(int h)
{
    in[h]=++T;
    nm[T]=h;
    for (int i = 0; i < g[h].size(); i++)
    {
        dfs(g[h][i]);
    }
    out[h]=++T;
}

pll d[3000001];

void build(int h,int l,int r)
{
    if (l==r)
    {
        d[h]=mp(1e18,0);
        return;
    }
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h].fi=min(d[h*2].fi, d[h*2+1].fi);
    d[h].se=max(d[h*2].se, d[h*2+1].se);
}

ll get_max(int h,int l,int r,int x,int y)
{
    if (x>y) return 0;
    if (l==x && y==r)
    {
        return d[h].se;
    }
    int w=(l+r)/2;
    return max(get_max(h*2,l,w,x,min(y,w)), get_max(h*2+1,w+1,r,max(x,w+1),y));
}

ll get_min(int h,int l,int r,int x,int y)
{
    if (x>y) return 1e18;
    if (l==x && y==r)
    {
        return d[h].fi;
    }
    int w=(l+r)/2;
    return min(get_min(h*2,l,w,x,min(y,w)), get_min(h*2+1,w+1,r,max(x,w+1),y));
}

void update(int h,int l,int r,int x,int y)
{
    if (l==r)
    {
        if (y!=-1) d[h]=mp(y,y); else d[h]=mp(1e18, 0);
        return;
    }
    int w=(l+r)/2;
    if (x<=w) update(h*2,l,w,x,y); else update(h*2+1,w+1,r,x,y);
    d[h].fi=min(d[h*2].fi, d[h*2+1].fi);
    d[h].se=max(d[h*2].se, d[h*2+1].se);
}

bool is_leaf(int h)
{
    //cout << get_min(1,1,n*2,in[h],out[h]) << "\n";
    return (get_min(1,1,n*2,in[h],out[h])>=out[h]);
}

ll _get(int h,int l,int r,int k)
{
    if (l==r) return l;
    int w=(l+r)/2;
    if (d[h*2+1].se>k) return _get(h*2+1,w+1,r,k); else return _get(h*2,l,w,k);
}

ll get(int h,int l,int r,int x,int y,int k)
{
    if (x>y) return 0;
    if (d[h].se<k) return 0;
    if (l==x && y==r)
    {
        return _get(h,l,r,k);
    }
    int w=(l+r)/2;
    ll o=get(h*2+1,w+1,r,max(x,w+1),y,k);
    if (o==0) return get(h*2,l,w,x,min(y,w),k); else return o;
}

ll find_ancestor(int h)
{
    return nm[get(1,1,n*2,1,in[h]-1,out[h])];
}

void ins(int h)
{
    ll o=find_ancestor(h);
    if (is_leaf(o)) ans--;
    update(1,1,n*2,in[h],out[h]);
    //cout << h << " " << o << " " << is_leaf(h) << "\n";
    if (is_leaf(h)) ans++;
    mx=max(mx, ans);
}

void ers(int h)
{
    ll o=find_ancestor(h);
    if (is_leaf(h)) ans--;
    update(1,1,n*2,in[h],-1);
    if (is_leaf(o)) ans++;
    mx=max(mx, ans);
}

void dfs2(int h)
{
    if (h!=1) ins(h);
    for (int i = 0; i < c[h].size(); i++)
    {
        dfs2(c[h][i]);
    }
    if (h!=1)ers(h);
}

void solve()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        c[x].pb(i);
    }
    for (int i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        g[x].pb(i);
    }
    T=0;
    dfs(1);
    build(1,1,n*2);
    //cout << get_min(1,1,n*2,1, n*2) << "\n";;
    update(1,1,n*2,in[1],out[1]);
    ans++;
    dfs2(1);
    cout << mx << "\n";
    ans=0;
    mx=0;
    for (int i = 1; i <= n*2; i++) nm[i]=0;
    for (int i = 1; i <= n; i++) in[i]=0, out[i]=0, c[i].clear(), g[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(0);
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
4 5
1 2 3 4
1 2
2 3
3 4
4 1
1 3
5
1 1
3 2
4 1
1 4
2 3
*/