#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
/*#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")*/
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, a[200005], b[200005];
pll p=mp(-1,-1);
vector<ll> qq;
vector<ll> v;
vector<pll> vv[200005];
bool tt[200005];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

struct segment_tree
{
    ll d[1000001];

    void update(int h,int l,int r,int x,int k)
    {
        if (l==r)
        {
            d[h]=k;
            return;
        }
        int w=(l+r)/2;
        if (x<=w)update(h*2,l,w,x,k); else
        update(h*2+1,w+1,r,x,k);
        if (d[h*2]>0) d[h]=d[h*2]; else
        if (d[h*2+1]>0) d[h]=d[h*2+1]; else d[h]=0;
    }

    ll get(int h,int l,int r,int x,int y)
    {
        if (x>y) return 0;
        if (l==x && y==r)
        {
            //cout << l << " " << r << " " << d[h] << "\n";
            return d[h];
        }
        int w=(l+r)/2;
        ll o1=max(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
        //cout << l << " " << r << " " << o1 << "\n";
        return o1;
    }
};

segment_tree g;

vector<ll> d[800001];

void update(int h,int l,int r,int x,int y,int k)
{
    if (x>y) return;
    if (l==x && y==r)
    {
        d[h].pb(k);
        return;
    }
    int w=(l+r)/2;
    update(h*2,l,w,x,min(y,w),k);
    update(h*2+1,w+1,r,max(x,w+1),y,k);
}

set<pair<int,int> > s;

void dfs(int h,int l,int r)
{
    //cout << h << " " << l << " " << r << " " << s.size() << "\n";
    for (int i = 0; i < d[h].size(); i++)
        if (!tt[d[h][i]])
    {
        s.insert(mp(v[d[h][i]], d[h][i]));
    }
    if (l==r)
    {
        qq.pb((*s.begin()).se);
        tt[(*s.begin()).se]=1;
        s.erase(s.begin());
        for (int i = 0; i < d[h].size(); i++)
            if (!tt[d[h][i]])
        {
            s.erase(mp(v[d[h][i]], d[h][i]));
        }
        return;
    }
    int w=(l+r)/2;
    dfs(h*2,l,w);
    dfs(h*2+1,w+1,r);
    for (int i = 0; i < d[h].size(); i++)
        if (!tt[d[h][i]])
    {
        s.erase(mp(v[d[h][i]], d[h][i]));
    }
}

void solve()
{
    cin >> n;
    vector<pll> ww;
    v.pb(0);
    ww.pb(mp(0,0));
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        ww.pb(mp(x,y));
        update(1,1,n,x,y,i);
        v.pb(y);
    }
    //cout << "----\n";
    qq.pb(0);
    dfs(1,1,n);
    for (int i = 1; i <= n; i++)
    {
        vv[ww[qq[i]].fi].pb(mp(i, i));
        vv[ww[qq[i]].se+1].pb(mp(i, 0));
    }
    //for (int i = 1; i <= n; i++) cout << qq[i] << " ";
    //cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < vv[i].size(); j++)
        {
            //cout << " " << vv[i][j].fi << " " << vv[i][j].se << "\n";
            g.update(1,1,n,vv[i][j].fi,vv[i][j].se);
        }
        ll o=g.get(1,1,n,ww[qq[i]].fi,i-1);
        //cout << ww[qq[i]].fi << " " << i-1 << " " << o << "\n";
        if (o!=0)
        {
            p=mp(o,i);
            break;
        }
        o=g.get(1,1,n,i+1,ww[qq[i]].se);
        //cout << i+1 << " " << ww[qq[i]].se << " " << o << "\n";
        if (o!=0)
        {
            p=mp(i,o);
            break;
        }
    }
    //cout << p.fi << " " << p.se << "\n";
    if (p.fi==-1)
    {
        cout << "YES\n";
        for (int i = 1; i < qq.size(); i++)
            a[qq[i]]=i;
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << "\n";
    }else
    {
        cout << "NO\n";
        for (int i = 1; i < qq.size(); i++)
            a[qq[i]]=i;
        swap(qq[p.fi],qq[p.se]);
        for (int i = 1; i < qq.size(); i++)
            b[qq[i]]=i;
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << "\n";
        for (int i = 1; i <= n; i++) cout << b[i] << " ";
        cout << "\n";
    }
    return;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        //cout << t << "\n";
        solve();
    }
    return 0;
}
/*
dp[]

*/