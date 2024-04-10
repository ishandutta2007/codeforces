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
#define ld double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, T, dp[500005], a[500005], b[500005];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l%=md;
        h *= h;
        h %= md;
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

void solve()
{
    ll q;
    cin >> n >> q;
    dp[0]=1;
    string ss;
    for (int i = 0; i <= n; i++) dp[i+1]=(dp[i+1]+dp[i]*2)%MOD, dp[i+2]=(dp[i+2]+dp[i]*8)%MOD;
    cin >> ss;
    for (int i = 1; i <= n; i++)
        a[i]=ss[i-1]-48;
    ll k=0;
    set<int> s;
    ll ans=1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i]==1) k++; else
        {
            b[i]=k;
            ll p=((a[i]+1)*dp[k])%MOD;
            if (k>0) p=(p+(19-(10+a[i]))*dp[k-1])%MOD;
            ans=(ans*p)%MOD;
            s.insert(i);
            k=0;
        }
    }
    if (k) ans=(ans*dp[k])%MOD, k--, b[n]=k, s.insert(n);
    //cout << ans << "\n";
    while (q--)
    {
        ll x, d;
        cin >> x >> d;
        if (a[x]==d) {cout << ans << "\n";continue;}
        auto u=s.lower_bound(x);
        ll o=*u;
        //cout << o << "\n";
        if (o==x)
        {
            if (d==1)
            {
                if (x!=n)
                {
                    s.erase(u);
                    auto q=s.lower_bound(x);
                    //cout << *q << "\n";
                    ll p=0;
                    p=(a[*q]+1)*dp[b[*q]]%MOD;
                    if (b[*q]>0)
                        p=(p+((19-(10+a[*q]))*dp[b[*q]-1])%MOD)%MOD;
                    ans=ans*binpow(p,MOD-2,MOD)%MOD;
                    p=(a[x]+1)*dp[b[x]]%MOD;
                    if (b[x]>0)
                        p=(p+((19-(10+a[x]))*dp[b[x]-1])%MOD)%MOD;
                    ans=ans*binpow(p,MOD-2,MOD)%MOD;
                    a[x]=d;
                    b[*q]+=b[x]+1;
                    b[x]=0;
                    p=0;
                    p=(a[*q]+1)*dp[b[*q]]%MOD;
                    if (b[*q]>0)
                        p=(p+((19-(10+a[*q]))*dp[b[*q]-1])%MOD)%MOD;
                    ans=(ans*p)%MOD;
                }else
                {
                    ll p=0;
                    p=(a[x]+1)*dp[b[x]]%MOD;
                    if (b[x]>0)
                        p=(p+((19-(10+a[x]))*dp[b[x]-1])%MOD)%MOD;
                    ans=ans*binpow(p,MOD-2,MOD)%MOD;
                    a[x]=d;
                    p=(a[x]+1)*dp[b[x]]%MOD;
                    if (b[x]>0)
                        p=(p+((19-(10+a[x]))*dp[b[x]-1])%MOD)%MOD;
                    ans=(ans*p)%MOD;
                }
            }else
            {
                ll p=(a[x]+1)*dp[b[x]]%MOD;
                if (b[x]>0)
                    p=(p+((19-(10+a[x]))*dp[b[x]-1])%MOD)%MOD;
                ans=ans*binpow(p,MOD-2,MOD)%MOD;
                a[x]=d;
                p=(a[x]+1)*dp[b[x]]%MOD;
                if (b[x]>0)
                    p=(p+((19-(10+a[x]))*dp[b[x]-1])%MOD)%MOD;
                ans=(ans*p)%MOD;
            }
        }else
        {
            if (d==1)
            {

            }else
            {
                s.insert(x);
                ll p=(a[o]+1)*dp[b[o]]%MOD;
                if (b[o]>0)
                    p=(p+((19-(10+a[o]))*dp[b[o]-1])%MOD)%MOD;
                ans=ans*binpow(p,MOD-2,MOD)%MOD;

                ll e=o-1-x;

                b[x]=b[o]-e-1;

                b[o]=e;

                p=(a[o]+1)*dp[b[o]]%MOD;
                if (b[o]>0)
                    p=(p+((19-(10+a[o]))*dp[b[o]-1])%MOD)%MOD;
                ans=ans*p%MOD;
                a[x]=d;
                p=(a[x]+1)*dp[b[x]]%MOD;
                if (b[x]>0)
                    p=(p+((19-(10+a[x]))*dp[b[x]-1])%MOD)%MOD;
                ans=ans*p%MOD;
            }
        }
        cout << ans << "\n";
        //for (int i = 1; i <= n; i++) cout << a[i];
        //cout << "\n";
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
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
3
4 2
1 1
1 0
3 2
2 2

3 1
1 1
1 0
3 2

3 2
1 1
1 0
3 2
*/