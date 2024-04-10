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

const ll MOD = 999999001;
const ll md = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-10;
mt19937_64 rnd(time(0));
ll p1 = 29, p2 = 17, p3 = 13, md1 = MOD, md2 = md, md3 = 998244353;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, Z, a[300005];

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
    vector<vector<ll> > v;
    ll k=0, k0=0, k1=0, k2=0, kol=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    vector<ll> z;
    for (int i = 1; i <= n; i++)
    {
        ll x=a[i];
        z.clear();
        ll p=min((ll)sqrt(x), 105ll);
        for (int j = 2; j <= p && x>1; j++)
            if (x%j==0)
            {
                ll k=0;
                while (x%j==0) x/=j, k++;
                if (k%2) z.pb(j);
            }
        if (x>1)
        {
            ll u=sqrt(x);
            if (u*u!=x)
                z.pb(x);
        }
        if (z.size()==0)
        {
            kol++;
        }else
        v.pb(z);
    }
    sort(all(v));
    k0=max(k0, kol);
    k2+=kol;
    for (int i = 0; i < v.size(); i++)
    {
        if (i==0 || v[i]==v[i-1]) k++; else
        {
            if (k%2)
            {
                k0=max(k0, k);
                k1=max(k1, k);
            }else
            {
                k0=max(k0, k);
                k2+=k;
            }
            k=1;
        }
    }
    if (k%2)
    {
        k0=max(k0, k);
        k1=max(k1, k);
    }else
    {
        k0=max(k0, k);
        k2+=k;
    }
    k=0;
    ll q=0;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        ll w;
        cin >> w;
        if (w==0)
        {
            cout << k0 << "\n";
        }else
        {
            cout << max(k1, k2) << "\n";
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
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

*/