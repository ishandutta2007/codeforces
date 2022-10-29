#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#include "testlib.h"
//#pragma GCC optimize("popcnt")
#include <random>
#include <time.h>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

mt19937_64 rnd(time(0));

ll MOD=998244353;
const ld E=1e-10;

ll n, m, k, T;

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%md;
        h=(h*h)%md;
        r/=2;
    }
    return l;
}

ll read()
{
    char c=getchar();
    while (!isdigit(c))
    {
        c=getchar();
    }
    ll res=0;
    while (isdigit(c))
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

ll gcd(ll x,ll y)
{
    while (x && y)
    {
        if (x<y) swap(x, y);
        x%=y;
    }
    return x+y;
}

struct ft
{
    ll f[600005];

    void upd(int x,ll k)
    {
        for (int i = x; i <= 600000; i+=(i&-i)) f[i]+=k;
    }

    ll get(int h)
    {
        ll ans=0;
        for (int i = h; i > 0; i-=(i&-i)) ans+=f[i];
        return ans;
    }
} f1, f2;

ll ans=0, kol=0;

bool tt[1000001];

void add(int x)
{

    ll o1=f1.get(x), o2=f2.get(x);

    ans+=o2;
    ans+=x*(kol-o1);

    for (ll i = x*2-1; i <= 600000; i+=x)
    {
        ll p2=f2.get(i), p1=f1.get(i);
        ans+=(p2-o2)-(p1-o1)*(i-x+1);
        o1=p1;
        o2=p2;
    }

    ll p=sqrt(x), z=x/(p+1);
    ll lst=x;
    for (ll i = 1; i <= z; i++)
        if (tt[i])
        {
            ans+=x%i;
        }

    for (ll i = 1; i <= p; i++)
    {
        ll nxt=x/(i+1);
        ll sum=f2.get(lst)-f2.get(nxt), kl=f1.get(lst)-f1.get(nxt);
        ans+=x*kl-sum*i;

        lst=nxt;
    }

    kol++;
    tt[x]=1;
    f1.upd(x,1);
    f2.upd(x,x);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        add(x);
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}