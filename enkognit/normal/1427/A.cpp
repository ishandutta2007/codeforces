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

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, a[1000001];

ll binpow(ll h, ll r, ll md = MOD)
{
    bool t = 0;
    if (h < 0) t = 1, h = -h;
    if (r % 2 == 0) t = 0;
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    if (t) l = -l;
    //cout << l << "\n";
    return l;
}

ll gcd(int x, int y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

void solve()
{
    cin >> n;
    ll sm=0, p=0;
    vector<ll> v1, v2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sm+=a[i];
        if (a[i]!=0)
        {
            if (a[i]<0) v1.pb(a[i]); else v2.pb(a[i]);
        }else p++;
    }
    if (sm==0) {cout << "NO\n";return;}
    ll kl=0;
    cout << "YES\n";
    if (sm>0)
    {
        for (int i = 0; i < v2.size(); i++) cout << v2[i] << " ";
        for (int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
        for (int i = 0; i <p; i++) cout << "0 ";
        cout << "\n";
    }else
    {
        for (int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
        for (int i = 0; i < v2.size(); i++) cout << v2[i] << " ";
        for (int i = 0; i <p; i++) cout << "0 ";
        cout << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*

1
5 3
5 2 2 3 1
1 4 4
3 5 4
3 4 1
*/