#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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
#define cringe exit(0)
#define y1 Enkognit

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ll md = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-10;
mt19937_64 rnd(time(0));
ll p1 = 29, p2 = 17, p3 = 13, md1 = MOD, md2 = md, md3 = 998244353;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, sz, Z, ans;
ll a[1000001], pr[1000001], sf[2][1000001];

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

ll binpow(ll h, ll r)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h;
        h*=h;
        r /= 2;
    }
    return l;
}

void solve()
{
    cin >> n;
    ll sm1=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i%2) sm1+=a[i]; else sm1-=a[i];
    }
    ll p=1e18;
    for (int i = 1; i <= n; i++)
    {
        pr[i]=-pr[i-1]+a[i];
        if (pr[i]<0) p=min(p, (ll)i);
    }
    if (sm1==0 && p>n)
    {
        cout << "YES\n";
        return;
    }
    sf[0][n+1]=1e18;
    sf[1][n+1]=1e18;
    for (int i = n; i > 0; i--)
    {
        if (i%2==0)
        {
            sf[0][i]=min(sf[0][i+1],pr[i]);
            sf[1][i]=sf[1][i+1];
        }else
        {
            sf[1][i]=min(sf[1][i+1],pr[i]);
            sf[0][i]=sf[0][i+1];
        }
    }
    for (int i = 1; i <= min(n-1,p); i++)
    {
        if (sm1+(i%2?-1:1)*(a[i]-a[i+1])*2!=0) continue;
        if (pr[i]-a[i]+a[i+1]<0) continue;
        if (pr[i+1]+a[i]*2-a[i+1]*2<0) continue;
        if (i+2>n || (sf[i%2][i+2]-a[i]*2+a[i+1]*2>=0 && sf[(i+1)%2][i+2]+a[i]*2-a[i+1]*2>=0))
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("oddeven.in","r",stdin);
    //freopen("oddeven.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
15 6
xzxyyzxxzxyyzyx
a 2 10
a 15 4
q 3
a 12 2
q 14
q 2
*/