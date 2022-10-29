#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
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

const ll MOD=1e9+7;

ll n, m, k, a[1000001], pp[10000001];
vector<ll> c[1000001];
string s;

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

void upd(int h)
{
    if (s[h-(1<<(n-1))]=='?') a[h]=a[c[h][0]]+a[c[h][1]]; else
    if (s[h-(1<<(n-1))]=='0') a[h]=a[c[h][0]]; else a[h]=a[c[h][1]];
}

void dfs(int h,int p=-1)
{
    if (h<=(1<<(n-1)))
    {
        a[h]=1;
        return;
    }
    pp[h]=p;
    //cout << h << " " << p << "\n";
    for (int i = 0; i < c[h].size(); i++)
        dfs(c[h][i], h);
    upd(h);
}

void solve()
{
    cin >> n;
    cin >> s;
    s=' '+s;
    n++;
    ll o=(1<<(n-1)), u=(1<<(n-1));
    for (int i = 1; i < (1<<n); i++)
    {
        c[(i-(u-o)-1)/2+u+1].pb(i);
        //cout << (i-(u-o)-1)/2+u+1 << " " << i << " " << (1<<n) << " " << u << "\n";
        if (i==u)
        {
            o/=2;
            u+=o;
        }
    }
    ll p=(1<<n)-1;
    dfs(p);
    ll q;
    cin >> q;
    while (q--)
    {
        ll x;
        char c;
        cin >> x >> c;
        s[x]=c;
        x+=(1<<(n-1));
        while (x!=-1)
        {
            //cout << x << "\n";
            upd(x);
            //cout << x << "\n";
            x=pp[x];
        }
        cout << a[p] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //cin >> t;
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
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
*/