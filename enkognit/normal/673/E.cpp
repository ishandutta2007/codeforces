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

int n, m, T, k;
ld a[200001], pr[200001], pr2[200001], pr3[200001], dp[200001][51];

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

void rec(int l,int r,int lr,int rr)
{
    if (l>r) return;
    int w=(l+r)/2, wr=0;
    dp[w][T]=1e18;
    for (int i = lr; i <= min(w-1,rr); i++)
        if (dp[w][T]>dp[i][T-1]+(pr2[w]-pr2[i]-(pr3[w]-pr3[i])*pr[i]))
        {
            dp[w][T]=dp[i][T-1]+(pr2[w]-pr2[i]-(pr3[w]-pr3[i])*pr[i]);
            wr=i;
        }
    rec(l,w-1,lr,wr);
    rec(w+1,r,wr,rr);
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        a[i]=x;
        pr[i]=pr[i-1]+a[i];
        pr2[i]=pr2[i-1]+pr[i]/a[i];
        pr3[i]=pr3[i-1]+1./a[i];
    }
    for (int i = 1; i <= n; i++) dp[i][1]=pr2[i];
    for (T=2;T<=m;T++) rec(1,n,1,n);
    cout.precision(10);
    cout <<fixed<< dp[n][m] << "\n";
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
4
3 2
1 2 2
4 3
1 2 3 4
2 2
1 2
11 4
66 152 7 89 42 28 222 69 10 54 99
*/