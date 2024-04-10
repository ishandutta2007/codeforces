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

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, a[1000001];

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
    //cout << l << "\n";
    return l;
}

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll o1=0, o2=0, z1=0, z2=0, k=0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i%2!=s[i]-'0')
        {
            k++;
        }else
        {
            if (k>0) o1++;
            k=0;
        }
       //cout << i%2 << " " << s[i] << "\n";
       // cout << i << " - " << o1 << "\n";
    }
    if (k) o1++;
    k=0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i%2==s[i]-'0')
        {
            k++;
        }else
        {
            if (k>0) o2++;
            k=0;
        }
       // cout << i%2 << " " <<s[i] << "\n";
       // cout << i << "  -- "  << o2 << "\n";
    }
    if (k) o2++;
    //cout << o1 << " " << o2 << "\n";
    cout << min(o1,o2) << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("document.in","r",stdin);
    //freopen("document.out","w",stdout);
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

3
1 4
4 3
8 1
3
1
3
2
*/