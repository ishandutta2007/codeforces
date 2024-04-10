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

ll n, m, T, a[1000001], b[1000001], pos[1000001];

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


struct segment_tree
{
    ll d[1000001];

    void build(int h,int l,int r)
    {
        if (l==r) {d[h]=a[l];return;}
        int w=(l+r)/2;
        build(h*2,l,w);
        build(h*2+1,w+1,r);
        d[h]=max(d[h*2],d[h*2+1]);
    }

    ll get(int h,int l,int r,int x,int y)
    {
        if (x>y) return 0;
        if (l==x && y==r) return d[h];
        int w=(l+r)/2;
        return max(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
    }
};

segment_tree g;

void solve()
{
    ll n, m, k, x, y;
    cin >> n >> m;
    cin >> x >> k >> y;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]]=i;
    }
    g.build(1,1,n);
    ll l=0, ans=0;
    for (int i = 1; i <= m+1; i++)
    {
        ll q;
        if (i==m+1) q=0, pos[0]=n+1; else cin >> q;
        if (pos[q]<l){cout << "-1\n";return;}
        ll o=pos[q]-l-1, u=g.get(1,1,n,l+1,pos[q]-1), nw=0;
        //cout << o << " " << u << "\n";
        if (o==0); else
        if (o<k)
        {
            nw+=(o-1)*y;
            if (max(a[l],q)<u) {cout << "-1\n";return;} else nw+=y;
        }else
        {
            nw+=o%k*y;
            o=o-o%k;
            nw+=min((o-k)/k*x,(o-k)*y);
            if (u<max(a[l],q)) nw+=min(k*y,x); else nw+=x;
        }
        ans+=nw;
        l=pos[q];
    }
    cout << ans << "\n";
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