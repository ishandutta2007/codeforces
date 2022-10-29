#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-7;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, a[200001];
int pos[200001];
vector<pii> zp, edges, pt;
vector<pii> c[200001];
vector<int> qq[2][200001];
vector<int> v[200001], nw, vr;
bool tl[300001], qw[200001], tt[200001], zz[200001], ha[500001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l%=md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x==0 || y==0) return x+y;
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
    int d[200001], kl[200001];

    void make_set(int h)
    {
        d[h]=h;
        kl[h]=1;
        return;
    }

    int find_set(int h)
    {
        if (h==d[h]) return h; else return find_set(d[h]);
    }

    void unite_sets(int x,int y)
    {
        x=find_set(x);
        y=find_set(y);
        //cout << " - " << x << " " << y << "\n";
        if (x==y) return;
        if (kl[y]>kl[x]) swap(x,y);
        d[y]=x;
        kl[x]+=kl[y];
    }
};

dsu st;

void dfs(int h)
{
    if (nw.size()) st.unite_sets(nw.back(), h);
    nw.pb(h);
    tt[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!tl[c[h][i].se] && !tt[c[h][i].fi])
        {
            dfs(c[h][i].fi);
        }
}

void rec(int h)
{
    if (qq[0][h].size()==0)
    {
        //if (v[h][0]!=h) while(1);
        for (int i = 0; i < v[h].size(); i++)
        {
            pos[v[h][i]]=vr.size();
            vr.pb(v[h][i]);
        }
        return;
    }
    ll y=qq[0][h].back();
    qq[0][h].pop_back();
    rec(h);
    rec(y);
}

pii d[1000001];

void build(int h,int l,int r)
{
    if (l==r)
    {
        d[h]=mp(a[vr[l]], l);
        return;
    }
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    pii o1=d[h*2], o2=d[h*2+1];
    if (o1.fi<o2.fi) d[h]=o2; else d[h]=o1;
}

pii get(int h,int l,int r,int x,int y)
{
    if (x>y) return mp(0,-1);
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    pii o1=get(h*2,l,w,x,min(y,w)), o2=get(h*2+1,w+1,r,max(x,w+1),y);
    if (o1.fi>o2.fi) return o1; else return o2;
}

void update(int h,int l,int r,int x)
{
    if (l==r)
    {
        d[h].fi=0;
        return;
    }
    int w=(l+r)/2;
    if (x<=w) update(h*2,l,w,x); else update(h*2+1,w+1,r,x);
    pii o1=d[h*2], o2=d[h*2+1];
    if (o1.fi<o2.fi) d[h]=o2; else d[h]=o1;
}

void solve()
{
    ll q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(mp(y, i));
        c[y].pb(mp(x, i));
        edges.pb(mp(x, y));
    }
    for (int i = 1; i <= n; i++) st.make_set(i);
    for (int i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (x==2) tl[y]=1;
        pt.pb(mp(x, y));
    }
    for (int i = 1; i <= n; i++)
        if (!tt[i])
        {
            nw.clear();
            dfs(i);
            //cout << nw.size() << "\n";
            //for (int i = 0; i < nw.size(); i++)
            //    cout << nw[i] << " ";
            //cout << "\n";
            zz[i]=1;
            v[i]=nw;
        }
    //for (int i = 1; i <= n; i++) if (zz[i]) cout << i << " ";
    //cout << "\n";
    //cout << "-----\n";
    for (int i = pt.size()-1; i > -1; i--)
    {
        if (pt[i].fi==2)
        {
            ll x=edges[pt[i].se-1].fi;
            ll y=edges[pt[i].se-1].se;
            x=st.find_set(x);
            y=st.find_set(y);
            if (x==y)
            {
                ha[i]=1;
                continue;
            }
            if (st.kl[x]<st.kl[y]) swap(x, y);
            //cout << st.kl[x] << " " << x << " " << st.kl[y] << " " << y << "\n";
            st.unite_sets(x,y);
            zz[y]=0;
            qq[0][x].pb(y);
            qq[1][x].pb(y);
        }
    }
    //for (int i = 1; i <= n; i++) reverse(all(qq[0][i])), reverse(all(qq[1][i]));
    for (int i = 1; i <= n; i++)
        if (zz[i])
        {
            rec(i);
        }
    build(1,0,vr.size()-1);
    //cout << "-----\n";
    //for (int i = 0; i < vr.size(); i++) cout << vr[i] << " ";
    //cout << "\n";
    //cout << "-\n";
    for (int i = 0; i < pt.size(); i++)
        if (!ha[i])
    {
        pll o=pt[i];
        //cout << i << " " << o.fi << " " << o.se << "\n";
        if (o.fi==1)
        {
            int u=st.find_set(o.se);
            //cout << u << " " << pos[u] << " " << pos[u]+st.kl[u]-1 << "\n";
            pii e=get(1,0,vr.size()-1,pos[u],pos[u]+st.kl[u]-1);
            cout << e.fi << "\n";
            if (e.se>-1)update(1,0,vr.size()-1,e.se);
        }else
        {
            int u=st.find_set(edges[o.se-1].se);
            //cout << u << " " << qq[1][u].size() << " - " << qq[1][u].back() << "\n";
            st.d[qq[1][u].back()]=qq[1][u].back();
            st.kl[u]-=st.kl[qq[1][u].back()];
            qq[1][u].pop_back();
        }
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
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1
4
1 2 9 13
5 6 10 14
3 7 11 15
4 8 12 16
*/