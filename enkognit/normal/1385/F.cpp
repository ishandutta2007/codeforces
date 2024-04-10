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

ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, T, k, kl[200001];
ll ans=0;
vector<pair<pii, int> > a[200001];
vector<ll> c[200001];
bool tt[200001];

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
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

void dfs(int h,int p=-1)
{
    kl[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]] && c[h][i]!=p)
        {
            dfs(c[h][i], h);
            kl[h]+=kl[c[h][i]];
        }
}

ll get_centroid(int h,int k,int p=-1)
{
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p && kl[c[h][i]]*2>=k && !tt[c[h][i]]) return get_centroid(c[h][i],k,h);
    return h;
}

pair<pii, int> dfs2(int h,int p)
{
    if (tt[h])
    {
        ll l=0, r=a[h].size()-1;
        while (l<r)
        {
            int w=(l+r+1)/2;
            if (a[h][w].se>p) r=w-1; else l=w;
        }
        return a[h][l];
    }
    a[h].pb(mp(mp(1,0), p));
    ll q=0, y=0;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            pair<pii,int> o=dfs2(c[h][i],h);
            q+=o.fi.fi;
            y|=(o.fi.fi==0);
            a[h].back().fi.se+=o.fi.se;
        }
    a[h].back().fi.fi&=(!y && q%k==0);
    a[h].back().fi.se+=q/k*k;
    pair<pii, int> qq=a[h].back();
    a[h].clear();
    return qq;
}

bool cmp(pair<pii,int> x,pair<pii,int> y)
{
    return x.se<y.se;
}

void rec(int h)
{
    dfs(h);
    h=get_centroid(h, kl[h]);
    vector<pair<pii, int> > v;
    vector<int> q;
    //cout << h << ":\n";
    for (int i = 0; i < c[h].size(); i++)
    {
        v.pb(dfs2(c[h][i], h));
        q.pb(c[h][i]);
    }
    ll k0=0, k1=0, sm=0;
    for (int i = 0; i < v.size(); i++)
    {
        dfs2(c[h][i],h);
        k0+=(v[i].fi.fi==0);
        k1+=(v[i].fi.fi==1);
        sm+=v[i].fi.se;
    }
    ans=max(ans, sm+k1/k*k);
    /*cout << "- " << k0 << " " << k1 << " " << sm+k1/k*k << "\n";
    cout << " " << h << " " << ans << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << " " << v[i].fi.fi << " " << v[i].fi.se << " " << c[h][i] << "\n";
    }*/
    a[h].clear();
    for (int i = 0; i < v.size(); i++)
    {
        ll kk0=k0-(v[i].fi.fi==0), kk1=k1-(v[i].fi.fi==1), ssm=sm-v[i].fi.se;
        a[h].pb(mp(mp((kk0==0 && kk1%k==0), ssm+kk1/k*k), c[h][i]));
    }
    sort(all(a[h]), cmp);
    /*for (int i = 0; i < v.size(); i++)
    {
        cout << a[h][i].fi.fi << " " << a[h][i].fi.fi << " " << a[h][i].se << "\n";
    }*/
    tt[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]]) rec(c[h][i]);
}

ll lst=0;

void solve()
{
    cin >> n >> k;
    //n=199999, k=99999;
    ans=0;
    for (int i = 1; i <= n; i++) c[i].clear(), tt[i]=0, a[i].clear(), kl[i]=0;
    for (int i = 1; i < n; i++)
    {
        ll x=1, y=i+1;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    //for (int i = 1; i <= n; i++)
    //    if (c[i].size()==1) a[i].pb(mp(mp(0,0), c[i][0]));
    rec(1);
    cout << ans/k << "\n";
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
    cin >> t;
    while(t--)
    {
        solve();
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