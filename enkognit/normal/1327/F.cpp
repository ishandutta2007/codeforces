#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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

const ll MOD = 998244353;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

vector<pii> v[2][31];

ll n, m, k, d, T, Q, a[600001], pr[600001];
bool tt[600001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
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

ll solve(int h)
{
    //cout << h << " :\n";
    vector<pii> v0=v[0][h], v1=v[1][h];
    ll mx=0;
    for (int i = 1; i <= n; i++) a[i]=0, tt[i]=0;
    for (int i = 0; i < v1.size(); i++)
        a[v1[i].fi]=max((ll)v1[i].se, a[v1[i].fi]);
    ll p=0;
    for (int i = 1; i <= n; i++)
    {
        p=max(p,a[i]);
        //if (i==7) cout << p << "\n";
        if (i>p) tt[i]=1;
    }

    for (int i = 1; i <= n; i++) a[i]=0;
    //cout << "---\n";
    for (int i = 0; i < v0.size(); i++)
    {
        a[v0[i].se+1]=max((ll)v0[i].fi,a[v0[i].se+1]);
        mx=max(mx,(ll)v0[i].fi);
    }
    for (int i = 1; i <= n; i++) a[i]=max(a[i],a[i-1]);
    //for (int i = 1; i <= n; i++) cout << (!tt[i]) << " ";
    //cout << "\n";
      //cout << " " << mx << "\n";
    pr[0]=1;
    ll l=0;
    if (mx==0) l=1;
    for (int i = 1; i <= n; i++)
    {
        if (tt[i])
        {
            //cout << "-" << i << " " << pr[a[i]-1] << " " << pr[i-1] << " " << a[i] << "\n";
            ll o=0;
            if (a[i]==0) o=pr[i-1]; else o=pr[i-1]-pr[a[i]-1];
            if (o<0) o+=MOD;
            pr[i]=pr[i-1]+o;
            pr[i]%=MOD;
            if (i>=mx) l+=o, l%=MOD;
        } else pr[i]=pr[i-1], pr[i]%=MOD;
    }
    //cout << " ans: " << l << "\n";
    //cout << "---\n";
    return l;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   // freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        ll j=0;
        while (j<k)
        {
            v[z%2][j].pb(mp(x,y));
            j++;
            z/=2;
        }
    }

    ll ans=1;

    for (int i = 0; i < k; i++) {ans*=(solve(i));ans%=MOD;}
    cout << ans << "\n";
    return 0;
}
/*8

10
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb

*/