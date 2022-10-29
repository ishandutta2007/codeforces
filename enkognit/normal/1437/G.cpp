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

ll n, m, k, T, nm[300001], zn[300001], ps[300001], lst[300001];
vector<ll> V;
pll a[300001];
vector<ll> v[300001];

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

struct node{
    vector<int> to, go;
    int link, p;
    int c;
    node():link(-1),p(-1),c(0){for (int i = 0; i < 26; i++) to.pb(-1), go.pb(-1);};
};

vector<node> g;
ll sz=0;

void add_string(string &s,int k)
{
    int nw=0;
    for (int i = 0; i < s.size(); i++)
    {
        if (g[nw].to[s[i]-'a']==-1)
        {
            sz++;
            g.pb(node());
            g[sz].p=nw;
            g[sz].c=s[i]-'a';
            g[nw].to[s[i]-'a']=sz;
        }
        nw=g[nw].to[s[i]-'a'];
    }
    v[nw].pb(k);
    nm[k]=nw;
}

int nxt(int h,int c);

int get_link(int h)
{
    if (g[h].link!=-1) return g[h].link; else
        if (h==0 || g[h].p==0) return g[h].link=0; else
            return g[h].link=nxt(get_link(g[h].p), g[h].c);
}

int nxt(int h,int c)
{
    if (g[h].go[c]!=-1) return g[h].go[c]; else
    if (g[h].to[c]!=-1) return g[h].go[c]=g[h].to[c]; else
        if (h==0) return g[h].go[c]=0; else
            return g[h].go[c]=nxt(get_link(h), c);
}

ll d[1200001];

void upd(int h,int l,int r,int x,int k)
{
    if (l==r)
    {
        d[h]=k;
        return;
    }
    int w=(l+r)/2;
    if (x<=w) upd(h*2,l,w,x,k); else upd(h*2+1,w+1,r,x,k);
    d[h]=max(d[h*2],d[h*2+1]);
}

ll get(int h,int l,int r,int x,int y)
{
    if (x>y) return 0; else
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    return max(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
}

void solve()
{
    g.pb(node());
    ll Z=0;
    cin >> n >> m;
    Z=m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        add_string(s, i);
    }
    for (int i = 1; i <= sz; i++) zn[i]=-1;
    for (int i = 1; i <= sz; i++)
    {
        if (v[i].size())
        {
            a[i].fi=V.size();
            zn[i]=0;
            for (int j = 0; j < v[i].size(); j++)
            {
                ps[v[i][j]]=V.size();
                V.pb(v[i][j]);
            }
            a[i].se=V.size()-1;
        }
    }
    //cout << " :: " << V.size() << "\n";
    while (m--)
    {
        int t;
        cin >> t;
        T++;
        if (t==1)
        {
            ll x, p;
            cin >> x >> p;
            upd(1,0,V.size()-1,ps[x],p);
            //cout << " " << nm[x] << " " << ps[x] << " " << x << " " << p << " " << a[nm[x]].fi << " " << a[nm[x]].se << "\n";
            zn[nm[x]]=get(1,0,V.size()-1,a[nm[x]].fi,a[nm[x]].se);
            //cout << zn[nm[x]] << "\n";
        }else
        {
            /*if (Z==300000 && n==1000)
            {
                cout.precision(10);
                cout << T << " " << sz << " " <<fixed<< (ld)clock()/1e8 << "\n";
                exit(0);
            }*/
            string d;
            cin >> d;
            ll nw=0, ans=-1;
            //cout << "-----\n";
            for (int i = 0; i < d.size(); i++)
            {
                nw=nxt(nw, d[i]-'a');
                //cout << " " << i << " " << nw << "\n";
                ll u=nw;
                while (u>0 && lst[u]!=T)
                {
                    //cout << " " << u << "-\n";
                    ans=max(ans, zn[u]);
                    lst[u]=T;
                    u=get_link(u);
                }
            }
            cout << ans << "\n";
        }
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