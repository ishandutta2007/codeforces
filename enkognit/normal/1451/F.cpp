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
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, a[1000001], kl[100001];
bool tt[1001];

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
    return l;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n+m; i++) kl[i]=0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            ll x;
            cin >> x;
            kl[i+j]^=x;
        }
    bool t=0;
    for (int i = 1; i <= n+m; i++)
    {
        if (kl[i]!=0) t=1;
    }
    cout << (t?"Ashish\n":"Jeel\n");
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    cin >> t;
    T=t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
5
4
4 4
1 1
2 2
3 3
4
4 4
4 1
1 4
2 2
6
3 2
2 1
1 2
3 3
3 4
3 1
5
1 1
1 2
1 3
1 4
5 5
4
1000000000 1000000000
1000000000 1
2 2
1000000000 999999999


1
4
1 1
2 1
33 3
2 2
*/