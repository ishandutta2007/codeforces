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

ll n, m, k, T, Z, a[200005], cl[200005];
string s[1001], f[1001];
bool tt[3001];

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

void dfs(int h)
{
    tt[h]=1;
    if (h>n)
    {
        for (int i = 1; i <= n; i++)
            if (!tt[i])
            {
                cl[i]=(cl[h]^(s[i][h-n]!=f[i][h-n]));
                dfs(i);
            }else
            {
                if (cl[i]!=(cl[h]^(s[i][h-n]!=f[i][h-n]))) T=1;
            }
    }else
    {
        for (int i = 1; i <= n; i++)
            if (!tt[i+n])
            {
                cl[i+n]=cl[h]^(s[h][i]!=f[h][i]);
                dfs(i+n);
            }else
            {
                if (cl[i+n]!=cl[h]^(s[h][i]!=f[h][i])) T=1;
            }
    }
}

void solve()
{
    cin >> n;
    T=0;
    for (int i = 1; i <= n*2; i++) tt[i]=0, cl[i]=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i]=' '+s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
        f[i]=' '+f[i];
    }
    dfs(1);
    if (T) cout << "NO\n"; else cout << "YES\n";
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