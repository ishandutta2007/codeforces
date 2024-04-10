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

ll MOD = 1e9+7;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, T, a[300001], dp[300001];
pll b[300001];
bool tt[300001];

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


struct sparse_table_1
{
    ll d[300001][20];

    void build(int n)
    {
        for (int i = n; i > 0; i--)
        {
            d[i][0]=a[i];
            for (int j = 1, u = 2; j < 20; j++, u*=2)
            {
                if (i+u-1>n) break;
                d[i][j]=min(d[i][j-1],d[i+u/2][j-1]);
            }
        }
    }

    ll get(int x,int y)
    {
        return min(d[x][b[y-x+1].se], d[y-b[y-x+1].fi+1][b[y-x+1].se]);
    }
};

struct sparse_table_2
{
    ll d[300001][20];

    void build(int n)
    {
        for (int i = n; i > 0; i--)
        {
            d[i][0]=a[i];
            for (int j = 1, u = 2; j < 20; j++, u*=2)
            {
                if (i+u-1>n) break;
                d[i][j]=max(d[i][j-1],d[i+u/2][j-1]);
            }
        }
    }

    ll get(int x,int y)
    {
        return max(d[x][b[y-x+1].se], d[y-b[y-x+1].fi+1][b[y-x+1].se]);
    }
};

sparse_table_1 g1;
sparse_table_2 g2;

struct segment_tree
{
    ll d[2000001];

    void build(int h,int l,int r)
    {
        if (l==r)
        {
            d[h]=1e18;
            return;
        }
        int w=(l+r)/2;
        build(h*2,l,w);
        build(h*2+1,w+1,r);
        d[h]=1e18;
    }

    void update(int h,int l,int r,int x,ll k)
    {
        if (l==r)
        {
            d[h]=k;
            return;
        }
        int w=(l+r)/2;
        if (x<=w) update(h*2,l,w,x,k); else update(h*2+1,w+1,r,x,k);
        d[h]=min(d[h*2],d[h*2+1]);
    }

    ll get(int h,int l,int r,int x,int y)
    {
        if (x>y) return 1e18;
        if (l==x && y==r)
        {
            return d[h];
        }
        int w=(l+r)/2;
        return min(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
    }
};

segment_tree q1, q2;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    g1.build(n);
    g2.build(n);
    q1.build(1,1,n);
    q2.build(1,1,n);
    dp[1]=0;
    set<pii> s1, s2;
    s1.insert(mp(a[1], 1));
    s2.insert(mp(a[1], 1));
    q1.update(1,1,n,1,0);
    q2.update(1,1,n,1,0);
    for (int i = 2; i <= n; i++)
    {
        ll o=1e18;
        ll l=1, r=i;
        //cout << i << "\n";
        while (l<r)
        {
            int w=(l+r)/2;
            if (g1.get(w,i-1)<=a[i]) l=w+1; else r=w;
        }
        //cout << " " << l << "\n";
        o=min(o, q1.get(1,1,n,max(l-1,1ll),i)+1);
        l=1, r=i;
        while (l<r)
        {
            int w=(l+r)/2;
            if (g2.get(w,i-1)>=a[i]) l=w+1; else r=w;
        }
        o=min(o, q2.get(1,1,n,max(l-1,1ll),i)+1);
        dp[i]=o;
        //cout << " - " << q2.get(1,1,n,1,1) << "\n";
        //cout << " " << l << "\n";
        //cout << dp[i] << "\n";
        while (s1.size())
        {
            auto u=s1.end();
            u--;
            if ((*u).fi>=a[i])
            {
                q1.update(1,1,n,(*u).se,1e18);
                s1.erase(u);
            }else break;
        }

        while (s2.size())
        {
            if ((*s2.begin()).fi<=a[i])
            {
                q2.update(1,1,n,(*s2.begin()).se,1e18);
                s2.erase(s2.begin());
            }else break;
        }
        s1.insert(mp(a[i], i));
        s2.insert(mp(a[i], i));
        q1.update(1,1,n,i,dp[i]);
        q2.update(1,1,n,i,dp[i]);
    }
    cout << dp[n] << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll o=0, u=-1;
    for (int i = 1; i <= 3e5; i++)
    {
        if (i/2==o) o=i, u++;
        b[i]=mp(o, u);
    }
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