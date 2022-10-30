#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second
#define y1 Enkognit
#define ld long double
#define pii pair<int,int>

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll INF=1e18;
const ll MOD=1e9+7;

template<typename T>
using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, l, r;
pll a[200001], b[200001];
pair<pll,ll> c[200001];
string s;

struct node
{
    node *l, *r;
    ll kl=0;
    node(int p=0):l(nullptr),r(nullptr),kl(p){};
};

struct segment_tree
{
    ll d[1000001];
    ll tt[1000001];
    bool leaf[1000001];

    void push(int h)
    {
        if (!leaf[h] && tt[h])
        {
            d[h*2]+=tt[h];
            d[h*2+1]+=tt[h];
            tt[h*2]+=tt[h];
            tt[h*2+1]+=tt[h];
            tt[h]=0;
        }
    }

    void build(int h,int l,int r)
    {
        if (l==r) {d[h]=-b[l].se;leaf[h]=1;return;}
        int w=(l+r)/2;
        build(h*2,l,w);
        build(h*2+1,w+1,r);
        d[h]=max(d[h*2],d[h*2+1]);
    }

    void update(int h,int l,int r,int x,int y,int k)
    {
        //cout << l << " " << r << "\n";
        push(h);
        if (x>y) return;
        if (l==x && y==r)
        {
            d[h]+=k;
            tt[h]+=k;
            push(h);
            return;
        }
        int w=(l+r)/2;
        update(h*2,l,w,x,min(y,w),k);
        update(h*2+1,w+1,r,max(x,w+1),y,k);
        d[h]=max(d[h*2],d[h*2+1]);
    }

};

segment_tree g;

ll binpow(ll h,ll r,ll md=MOD)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}


void solve()
{
    cin >> n >> m >> k;
//cout << 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i].fi >> b[i].se;
    }

    for (int i = 1; i <= k; i++)
    {
        cin >> c[i].fi.fi >> c[i].fi.se >> c[i].se;
    }
    sort(c+1,c+k+1);

    sort(a+1,a+n+1);

    sort(b+1,b+m+1);

    g.build(1,1,m);

    ll l=0, ans=-1e18;
    for (int i = 1; i <= n; i++)
    {
        while (l<k && c[l+1].fi.fi<a[i].fi)
        {
            l++;
            ll lr=1, rr=m;
            while (lr<rr)
            {
                int w=(lr+rr)/2;
                if (b[w].fi<=c[l].fi.se) lr=w+1; else rr=w;
            }
            if (b[lr].fi>c[l].fi.se)
            g.update(1,1,m,lr,m,c[l].se);
        }
        ans=max(ans,-a[i].se+g.d[1]);
    }
    cout << ans;
}

int main()
{
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