#include <bits/stdc++.h>
//#include <random>
//#include <ctime>
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
//mt19937_64 rnd(time(0));
ll p1 = 29, p2 = 17, p3 = 13, md1 = MOD, md2 = md, md3 = 998244353;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, Z, lf[300005], rg[300005];

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
    string s;
    cin >> s;
    s=' '+s;
    for (int i = 0; i <= n; i++) lf[i]=0, rg[i]=0;
    for (int i = 0; i <= n; i++)
    {
        if (i>0)
        {
            if (s[i]=='L')
            {
                lf[i]++;
                if (i>1 && s[i-1]=='R')
                {
                    lf[i]+=lf[i-2]+1;
                }
            }
        }
    }
    for (int i = n; i > -1; i--)
    {
        if (i<n)
        {
            if (s[i+1]=='R')
            {
                rg[i]++;
                if (i+2<=n && s[i+2]=='L')
                {
                    rg[i]+=rg[i+2]+1;
                }
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        //cout << i << " " << lf[i] << " " << rg[i] << "\n";
        cout << lf[i]+rg[i]+1 << " ";
    }
    cout << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("stones.in","r",stdin);
    //freopen("stones.out","w",stdout);
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
6 4 13
1 2
2 3
3 4
4 5
*/