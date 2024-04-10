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
string s;

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
    cin >> n >> m;
    cin >> s;
    ll sm=0, lst=0, k=0, u=0, zz=0, ls=0, kol=0;
    vector<ll> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='W')
        {
            if (k)
            {
                if (!u) zz=k; else
                v.pb(k);
            }
            sm+=lst+1;
            kol++;
            u=1;
            k=0;
        }else
        {
            k++;
        }
        if (s[i]=='W') lst=1; else lst=0;
    }
    if (k)
    {
        if (!u) zz=k; else
        ls=k;
    }
    sort(all(v));
    for (int i = 0; i < v.size(); i++)
    {
        if (m>=v[i])
        {
            m-=v[i];
            sm+=v[i]*2+1;
        }else
        {
            sm+=m*2;
            m=0;
        }
    }
    //cout << zz << " " << ls << "\n";
    if (m>0)
    {
        ll p=min(ls, m);
        sm+=p*2;
        m-=p;
    }
    if (m>0)
    {
        ll p=min(zz, m);
        sm+=p*2-(p>0)+(u && p>0);
        m-=p;
    }
    cout << sm << "\n";
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