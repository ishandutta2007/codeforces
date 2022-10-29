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

ll ans, n, m, k, h, T, sum, a[300001], pr[300001], pr2[300001];

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


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    ll sum=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum+=a[i];
        pr[i]=pr[i-1]+a[i];
        pr2[i]=pr2[i-1]+(a[i]*(a[i]+1))/2;
    }
    ll p=sum-m, ans=0;
    for (int i = 1; i <= n; i++)
    {
        ll u=p, z=0;
        if (pr[n]-pr[i-1]<u)
        {
            z=pr2[n]-pr2[i-1];
            u-=pr[n]-pr[i-1];
            ll l=1, r=i-1;
            while (l<r)
            {
                int w=(l+r)/2;
                if (pr[w]>=u) r=w; else l=w+1;
            }
            z+=pr2[l-1];
            u-=pr[l-1];
            z+=u*(u+1)/2;
        }
         else
        {
            ll l=i, r=n;
            while (l<r)
            {
                int w=(l+r)/2;
                //if (i==1) cout << w << " " << pr[l] << " " << pr[i-1] << " " << u << "\n";
                if (pr[w]-pr[i-1]>=u) r=w; else l=w+1;
            }
            //cout << " " << l << " " << i << " " << u << " " << pr[l-1] << " " << pr[i-1] << "\n";
            z+=(pr2[l-1]-pr2[i-1]);
            u-=(pr[l-1]-pr[i-1]);
            z+=u*(u+1)/2;
        }
        //cout << i << " : " << pr2[n] << " - " << z << "\n";
        ans=max(ans,pr2[n]-z);
    }
    cout << ans << "\n";
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