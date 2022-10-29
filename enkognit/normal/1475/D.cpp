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

ll n, m, k, T, Z, a[200005], b[200005], pr[200005];

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
    cin >> n >> m;
    ll sm=0;
    vector<ll> v1, v2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sm+=a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if (b[i]==1)
        {
            v1.pb(a[i]);
        }else
        {
            v2.pb(a[i]);
        }
    }
    if (sm<m)
    {
        cout << "-1\n";
        return;
    }
    sort(all(v1));
    sort(all(v2));
    reverse(all(v1));
    reverse(all(v2));
    sm=0;
    ll kol=v1.size();
    ll ans=1e18;
    for (int i = 0; i < v1.size(); i++)
        sm+=v1[i];
    for (int i = 0; i <= v2.size(); i++)
    {
        while (v1.size() && sm-v1.back()>=m) sm-=v1.back(), v1.pop_back(), kol--;
        if (sm>=m)
        {
            ans=min(ans, kol);
        }
        if (i<v2.size()) sm+=v2[i], kol+=2;
    }
    cout << ans << "\n";
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