#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

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
#define sqr(a) ((a)*(a))
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;
const ll N=1e6+1;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

const ll md1=1e9+7, md2=998244357, md3=rnd()%(ll)(1e8), p1=31, p2=37, p3=41;

//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, ans, TT, l, T, i, j, h, pp=0;
ll d[20000001];
bool tt[2000001];
vector <int> c[1000001], vv;
vector <pii> v, a;
vector <pair<pii,int> > z;
map<int,int> w;

void build(int h,int l,int r)
{
    if (l==r) {d[h]=0;return;}
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=d[h*2]+d[h*2+1];
}

void update(int h,int l,int r,int x,ll k)
{
    if (l==r) {d[h]=k;return;}
    int w=(l+r)/2;
    if (x<=w) update(h*2,l,w,x,k); else
    update(h*2+1,w+1,r,x,k);
    d[h]=d[h*2]+d[h*2+1];
}

ll get(int h,int l,int r,int x,int y)
{
    if (x>y) return 0;
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    return get(h*2,l,w,x,min(y,w))+get(h*2+1,w+1,r,max(x,w+1),y);
}

void get2(int h,int l,int r,int x,int y,int k)
{
    if (d[h]==0 || x>y) return;
    //cout << x << " " << y << "\n";
    if (l==r) {c[l].pb(k);c[k].pb(l);return;}
    int w=(l+r)/2;
    get2(h*2,l,w,x,min(y,w),k);
    get2(h*2+1,w+1,r,max(x,w+1),y,k);
}

void dfs(ll h)
{
    pp++;
    tt[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]]) dfs(c[h][i]);
}

int main()
{
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        a.pb(mp(x,y));
        v.pb(mp(x,y));
        z.pb(mp(mp(x,0),i-1));
        z.pb(mp(mp(y,1),i-1));
    }
    sort(v.begin(),v.end());
    ll p=v[0].se;
    bool t=0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].fi>p) {t=1;break;}
        p=max(p,(ll)v[i].se);
    }
    if (t) {cout << "NO\n";exit(0);}
    sort(z.begin(),z.end());
    build(1,1,n*2);
    //cout << a.size() << "\n";
    ll kol=0;
    for (int i = 0; i < z.size(); i++)
    {
        //cout <<z[i].fi.fi << " " << z[i].fi.se << " " << z[i].se << "\n";
        if (z[i].fi.se==0) update(1,1,n*2,z[i].fi.fi,1);else
        if (z[i].fi.se==1)
        {
            update(1,1,n*2,a[z[i].se].fi,0);
            kol+=get(1,1,n*2,a[z[i].se].fi,a[z[i].se].se);
            if (kol>n-1) {cout << "NO\n";exit(0);}
            //cout << a[z[i].se].fi << "\n";
            get2(1,1,n*2,a[z[i].se].fi,a[z[i].se].se,a[z[i].se].fi);
        }
    }
    dfs(1);
    //cout << kol << "\n";
    //cout << pp << "\n";
    if (kol!=n-1 || pp!=n) {cout << "NO\n";exit(0);} else {cout << "YES\n";exit(0);}
    //exit(0);
    return 0;
}