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

const ll MOD=1e9+7;

ll n, m, k, T, TT, a[1000000];

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

bool tt[100001];

void solve()
{
    cin >> n >> k;
    string s;
    cin >> s;
    string d;
    string ans="";
    for (int i = 0; i < n; i++)
    {
        d+=s[i];
        string u="";
        while (u.size()<k) u+=d;
        while (u.size()>k) u.pop_back();
        if (ans.size()!=k || ans>u) ans=u;
    }
    cout << ans << "\n";
    /*s=' '+s;
    ll r=0, l=1;
    for (int i = 2; i <= n; i++)
    {
        if (i<=r)
        {
            a[i]=a[i-l+1];
        }

        while (i+a[i]<=n && s[i+a[i]]==s[a[i]+1]) a[i]++;

        if (i+a[i]-1>r)
        {
            l=i;
            r=i+a[i]-1;
        }
    }

    ll p=n+1;
    for (int i = 2; i <= n; i++)
    {
        //cout << i << " " << a[i] << " " << s[i+a[i]] << " " << s[a[i]+1] << "\n";
        if (i+a[i]<=n && s[i+a[i]]>s[1+a[i]])
        {
            p=i;
            break;
        }
    }
    cout << p << "\n";
    while (s.size()>p) s.pop_back();
    s.erase(s.begin());
    while (s.size()<k) s=s+s;
    while (s.size()>k) s.pop_back();
    cout << s << "\n";*/
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin>> t;
    while (t--)
    {
        solve();
    }
    return 0;
}