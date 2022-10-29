#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, T, a[1000005], lf[100005], rg[100005];

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

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

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i-1]<a[i]) lf[i]=lf[i-1]+1; else lf[i]=0;
    }

    for (int i = n-1; i > 0; i--)
    {
        if (a[i+1]<a[i]) rg[i]=rg[i+1]+1; else rg[i]=0;
    }
    ll k=0, mx=-1;
    for (int i = 1; i <= n; i++)
    {
        if (mx<max(lf[i], rg[i])) k=1, mx=max(mx, max(lf[i], rg[i])); else
        if (mx==max(lf[i], rg[i])) k++;
    }
    if (k>1)
    {
        cout << "0\n";
        exit(0);
    }
    for (int i = 1; i <= n; i++)
        if (max(lf[i], rg[i])==mx)
        {
            //cout << i << "\n";
            ll p1=max(lf[i], rg[i]), p2=min(lf[i], rg[i]);
            if (p1-(p1%2==0)>=p2)
            {
                cout << "0\n";
            }else
            {
                cout << "1\n";
            }
            exit(0);
        }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
01000000
10100000
31100000
00020000
00000000
00000000
00000000
00000000

01100000
10100000
01100000
00100000
00100000
00100000
13112101
00011111
*/