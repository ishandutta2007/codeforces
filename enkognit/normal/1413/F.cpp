#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

int n, m, k, T, in1[1100001], in2[1100001], out1[1100001], out2[1100001];
pii zn[500001];
vector<int> c[500001], z1, z2;

ll binpow(ll h, ll r, ll md)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    //cout << l << "\n";
    return l;
}

struct segment_tree
{
    pii d[5000001];
    bool leaf[5000001], tt[5000001];

    void push(int h)
    {
        if (tt[h] && !leaf[h])
        {
            tt[h*2]^=tt[h];
            swap(d[h*2].fi, d[h*2].se);
            tt[h*2+1]^=tt[h];
            swap(d[h*2+1].fi, d[h*2+1].se);
        }
        tt[h]=0;
    }

    void build(int h,int l,int r,vector<int>& v)
    {
        if (l==r)
        {
            leaf[h]=1;
            d[h]=mp(v[l],0);
            return;
        }
        int w=(l+r)/2;
        build(h*2,l,w,v);
        build(h*2+1,w+1,r,v);
        d[h].fi=max(d[h*2].fi,d[h*2+1].fi);
        d[h].se=max(d[h*2].se,d[h*2+1].se);
    }

    void update(int h,int l,int r,int x,int y)
    {
        if (x>y) return;
        push(h);
        if (l==x && y==r)
        {
            tt[h]=1;
            swap(d[h].fi, d[h].se);
            push(h);
            return;
        }
        int w=(l+r)/2;
        update(h*2,l,w,x,min(y,w));
        update(h*2+1,w+1,r,max(x,w+1),y);
        d[h].fi=max(d[h*2].fi,d[h*2+1].fi);
        d[h].se=max(d[h*2].se,d[h*2+1].se);
    }
};

segment_tree g1, g2;

ll mx, p1, p2;

void dfs(int h,int p=-1)
{
    pii o1=mp(0, h), o2=mp(0, h);
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i], h);
            if (zn[c[h][i]].fi+1>o1.fi) swap(o1, o2), o1=zn[c[h][i]], o1.fi++; else
            if (zn[c[h][i]].fi+1>o2.fi) o2=zn[c[h][i]], o2.fi++;
        }
    //cout << h << " " << o1.fi << " " << o2.fi << "\n";
    if (o1.fi+o2.fi>mx)
        mx=o1.fi+o2.fi, p1=o1.se, p2=o2.se;
    zn[h]=o1;
}

void dfs1(int h,int k=0,int p=-1)
{
    in1[h]=z1.size();
    z1.pb(k);
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs1(c[h][i], k+1, h);
        }
    out1[h]=z1.size();
    z1.pb(k);
}

void dfs2(int h,int k=0,int p=-1)
{
    in2[h]=z2.size();
    z2.pb(k);
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs2(c[h][i], k+1, h);
        }
    out2[h]=z2.size();
    z2.pb(k);
}

void solve()
{
    cin >> n;
    ll tt=0;
    vector<pii> v, zpr;
    for (int i = 1; i < n; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        c[x].pb(y);
        c[y].pb(x);
        v.pb(mp(x, y));
        if (z) zpr.pb(mp(x, y));
        tt=z;
    }
    if (n==2)
    {
        ll q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            ll x;
            cin >> x;
            tt^=1;
            cout << (tt?0:1) << "\n";
        }
        exit(0);
    }
    dfs(1);
    dfs1(p1);
    dfs2(p2);
    //c/out << p1 << " " << p2 << "\n";
    //for (int i = 0; i < z1.size(); i++) cout << z1[i] << " ";
    g1.build(1,0,z1.size()-1,z1);
    g2.build(1,0,z2.size()-1,z2);
    for (int i = 0; i < zpr.size(); i++)
    {
        int x=zpr[i].fi, y=zpr[i].se;
        if (in1[x]>in1[y]) swap(x, y);
        g1.update(1,0,z1.size()-1,in1[y],out1[y]);
        if (in2[x]>in2[y]) swap(x, y);
        g2.update(1,0,z2.size()-1,in2[y],out2[y]);
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll h;
        cin >> h;
        h--;
        int x=v[h].fi, y=v[h].se;
        if (in1[x]>in1[y]) swap(x, y);
        g1.update(1,0,z1.size()-1,in1[y],out1[y]);
        if (in2[x]>in2[y]) swap(x, y);
        g2.update(1,0,z2.size()-1,in2[y],out2[y]);
        cout << max(g1.d[1].fi, g2.d[1].fi) << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("document.in","r",stdin);
    //freopen("document.out","w",stdout);
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

3
1 4
4 3
8 1
3
1
3
2
*/