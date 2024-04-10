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
const ll INF = 1e18;
const ld E = 1e-8;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll ans, n, m, k, h, T, x, sum, a[300001], pr[300001], pr2[300001];

ll binpow(ll h, ll r)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h;// l %= md;
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

struct segment_tree
{
    ll d[5000001];
    ll tt[5000001];

    void push(int h)
    {
        if (tt[h])
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
        if (l==r) {d[h]=pr2[l];return;}
        int w=(l+r)/2;
        build(h*2,l,w);
        build(h*2+1,w+1,r);
        d[h]=max(d[h*2],d[h*2+1]);
    }

    ll get(int h,int l,int r,int x,int y)
    {
        if (x>y) return -1e18;
        push(h);
        if (l==x && y==r) return d[h];
        int w=(l+r)/2;
        return max(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
    }
};

segment_tree g;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll sum=0;
    for (int i = 1; i <= (n+1)/2; i++)
    {
        cin >> a[i];
        pr[i]=pr[i-1]+a[i];
        sum+=a[i];
    }
    cin >> x;
    sum+=(n/2)*x;
    m=(n+1)/2;
    for (int i = 1; i <= (n+1)/2; i++)
    {
        pr2[i]=pr[i]-i*x;
    }
    g.build(1,0,m);
    //cout << g.get(1,1,m,2,2) << "\n";
    for (int i = 0; i <= n/2; i++)
    {
        ll o=g.get(1,0,m,0,i);
        if (i==0) o=0;
        //cout << i << " : ";
        //for (int j = 0; j <= i; j++) cout << pr2[j]+i*x << " ";
        //cout << "\n";
        //cout << o << "\n";
        if (o<sum) {cout << n-i << "\n";exit(0);}
        g.d[1]+=x;
        g.tt[1]+=x;
    }
    cout << "-1\n";
    return 0;
}
/*
7 4
9 20
6 2
20 12
5 17
1 11
5 9
14 19
*/