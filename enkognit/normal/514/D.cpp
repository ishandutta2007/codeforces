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
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 29, p3 = 7, p4=rnd()%100+1, md1 = MOD, md2 = 998244353, md3=998244357, md4=rnd()%1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, q, a[5][100001];
pll b[100001];

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

struct sparse_table
{
    ll d[100001][21];

    void build(int h)
    {
        for (int i = n; i > 0; i--)
        {
            d[i][0]=a[h][i];
            for (int j = 1; j < 20; j++)
            {
                if (i+binpow(2,j)-1>n) break;
                d[i][j]=max(d[i][j-1],d[i+binpow(2,j-1)][j-1]);
            }
        }
    }

    ll get(int l,int r)
    {
        pll p=b[r-l+1];
        //cout << l << " " << r << " " << max(d[l][p.se], d[r-p.fi+1][p.se]) << " " << p.fi << " " << p.se << "\n";
        return max(d[l][p.se], d[r-p.fi+1][p.se]);
    }
};

sparse_table g[5];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll o=0, u=-1;
    for (int i = 1; i <= 1e5; i++)
    {
        if (i/2==o) o=i, u++;
        //cout << i << " " << o << " " << u << "\n";
        b[i]=mp(o,u);
    }
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll x;
            cin >> x;
            a[j][i]=x;
        }
    }
    for (int i = 0; i < m; i++) g[i].build(i);
    ll l=0, r=n;
    while (l<r)
    {
        int w=(l+r+1)/2;
        bool tt=0;
        for (int i = 1; i <= n-w+1; i++)
        {
            ll o=0;
            for (int j = 0; j < m; j++)
            {
                o+=g[j].get(i,i+w-1);
            }
            if (o<=k) {tt=1;break;}
        }
        if (tt) l=w; else r=w-1;
    }
    //cout << l << "\n";
    for (int i = 1; i <= n-l+1; i++)
    {
        vector<ll> v;
        ll o=0;
        for (int j = 0; j < m; j++)
        {
            ll p=g[j].get(i,i+l-1);
            v.pb(p);
            o+=p;
        }
        if (o<=k)
        {
            for (int j = 0; j < m; j++) cout << v[j] << " ";
            cout << "\n";
            exit(0);
        }
    }
    return 0;
}

/*
7 6
2 1 1
3 1 2
1 4 0
4 5 1
5 6 3
5 7 4
1 3
4 1
2 4
2 5
3 5
3 7
*/