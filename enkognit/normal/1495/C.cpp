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

const ll MOD=998244353;

ll n, m, k, T, a[505][505], len=0;
string s[505];
bool tt[505];

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
    cin >> n >> m;
    ll x=0, y=0;
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i]=' '+s[i];
        for (int j = 1; j <= m; j++)
        {
            a[i][j]=0;
            if (s[i][j]=='X') a[i][j]=1;
        }
    }
    if (m%3==0)
    {
        for (int i = 2; i <= m; i+=3)
        {
            for (int j = 1; j <= n; j++) a[j][i]=1;
            if (i>2)
            {
                bool t=0;
                for (int j = 1; j <= n && !t; j++)
                    if (s[j][i-1]=='X')
                    {
                        t=1;
                        a[j][i-2]=1;
                    }else
                    if (s[j][i-2]=='X')
                    {
                        t=1;
                        a[j][i-1]=1;
                    }
                if (!t)
                {
                    a[1][i-2]=1;
                    a[1][i-1]=1;
                }
            }
        }
    }else
    if (m%3==1)
    {
        for (int i = 1; i <= m; i+=3)
        {
            for (int j = 1; j <= n; j++) a[j][i]=1;
            if (i>1)
            {
                bool t=0;
                for (int j = 1; j <= n && !t; j++)
                    if (s[j][i-1]=='X')
                    {
                        t=1;
                        a[j][i-2]=1;
                    }else
                    if (s[j][i-2]=='X')
                    {
                        t=1;
                        a[j][i-1]=1;
                    }
                if (!t)
                {
                    a[1][i-2]=1;
                    a[1][i-1]=1;
                }
            }
        }

    }else
    if (m%3==2)
    {
        for (int i = 2; i <= m; i+=3)
        {
            for (int j = 1; j <= n; j++) a[j][i]=1;
            if (i>2)
            {
                bool t=0;
                for (int j = 1; j <= n && !t; j++)
                    if (s[j][i-1]=='X')
                    {
                        t=1;
                        a[j][i-2]=1;
                    }else
                    if (s[j][i-2]=='X')
                    {
                        t=1;
                        a[j][i-1]=1;
                    }
                if (!t)
                {
                    a[1][i-2]=1;
                    a[1][i-1]=1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cout << (a[i][j]?'X':'.');
        cout << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
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