#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, T, dtr[300001];
bool tt[300001];
pll b[300001];
ll a[300001], mx[300001];
vector<ll> c[300001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h;
        h *= h;
        //h %= md;
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

struct dsu
{
    ll d[300001];

    void make_set(int h)
    {
        d[h]=h;
    }

    ll find_set(int h)
    {
        if (h==d[h]) return h; else return d[h]=find_set(d[h]);
    }

    void unite_sets(int x,int y)
    {
        x=find_set(x);
        y=find_set(y);
        d[x]=y;
    }
};

dsu g;
#define dies_from_cringe exit(0)

void dfs(int h,int p=-1)
{
    mx[h]=0;
    tt[h]=1;
    if (p!=-1) g.unite_sets(h,p);
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i],h);
            mx[h]=max(mx[h], mx[c[h][i]]+1);
        }
}

void dfs2(int h,ll k=0,int p=-1)
{
    pll o=mp(0,0);
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            if (mx[c[h][i]]+1>o.fi)
                swap(o.fi,o.se), o.fi=mx[c[h][i]]+1; else
            if (mx[c[h][i]]+1>o.se) o.se=mx[c[h][i]]+1;
        }
    dtr[g.find_set(h)]=max(max(k,o.se)+o.fi, dtr[g.find_set(h)]);
    if (max(o.fi,k)<b[g.find_set(h)].se) b[g.find_set(h)]=mp(h, max(o.fi, k));
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            ll u=o.fi;
            if (u==mx[c[h][i]]+1) u=o.se;
            dfs2(c[h][i],max(u,k)+1,h);
        }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) g.make_set(i);
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    for (int i = 1; i <= n; i++)
        if (!tt[i])
        {
            dfs(i);
            b[g.find_set(i)]=mp(0,1e18);
            dfs2(i);
            //cout << g.find_set(i) << " " << b[g.find_set(i)].fi << " " << b[g.find_set(i)].se << "\n";
        }
    while (q--)
    {
        ll t;
        cin >> t;
        //cout << q << "\n";
        if (t==1)
        {
            ll x;
            cin >> x;
            cout << dtr[g.find_set(x)] << "\n";
        }else
        {
            ll x, y;
            cin >> x >> y;
            x=g.find_set(x);
            y=g.find_set(y);
            if (x==y) continue;
            ll q=max(dtr[x],dtr[y]);
            ll p1=b[x].se;
            ll p2=b[y].se;
            x=b[x].fi;
            y=b[y].fi;
            //cout << x << " " << y << " " << p1 << " " << p2 << "\n";
            g.unite_sets(x,y);
            dtr[g.find_set(x)]=max(p1+p2+1, q);
            if (p1>p2)
            {
                b[g.find_set(x)]=mp(x,p1);
            }else
            {
                b[g.find_set(y)]=mp(y,p2+(p1==p2));
            }
        }
    }
    return 0;
}

/*
3
4 2
1 1
1 0
3 2
2 2

3 1
1 1
1 0
3 2

3 2
1 1
1 0
3 2
*/