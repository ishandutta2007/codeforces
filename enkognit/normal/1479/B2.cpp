#include <bits/stdc++.h>
//#include <random>
//#include <ctime>
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
#define cringe exit(0)
#define y1 Enkognit

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;

//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, Z, a[200005], lst[200005], nxt[200005];

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
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        lst[a[i]]=1e18;
    }
    for (int i = n; i > 0; i--)
    {
        nxt[i]=lst[a[i]];
        lst[a[i]]=i;
    }
    //for (int i = 1; i <= n; i++) cout << i << " : " << nxt[i] << "\n";
    vector<ll> v1, v2;
    nxt[0]=1e18;
    v1.pb(0);
    v2.pb(0);
    for (int i = 1; i <= n; i++)
    {
        if (a[v1.back()]==a[i])
        {
            v1.back()=i;
            //continue;
        } else
        if (a[v2.back()]==a[i])
        {
            v2.back()=i;
        }else
        {
            if (nxt[v1.back()]>nxt[v2.back()]) v1.pb(i); else v2.pb(i);
        }
        //cout << v1.back() << " " << v2.back() << "\n";
    }
    cout << (int)v1.size()+(int)v2.size()-2 << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("stones.in","r",stdin);
    //freopen("stones.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
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
37 29 8 5
13 118 86 6 1000

*/