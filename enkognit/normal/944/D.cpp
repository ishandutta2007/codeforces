#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef double ld;
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

ll n, m, k, T, sm;

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

ll tt[5005][30][30];
ll kl[30];

void solve()
{
    string s;
    cin >> s;
    n=s.size();
    s=s+s;
    s=' '+s;
    for (int i = 1; i <= n; i++)
    {
        kl[s[i]-'a']++;
        for (int j = i; j < i+n; j++)
            tt[j-i][s[i]-'a'][s[j]-'a']++;
    }

    ld ans=0;

    for (int c = 0; c < 26; c++)
        if (kl[c])
    {
        ld o=(ld)kl[c]/(ld)n;
        ll mx=0;
        for (int i = 0; i < n; i++)
        {
            ll p=0;
            for (int j = 0; j < 26; j++)
            {
                if (tt[i][c][j]==1) p++;
            }
            mx=max(mx, p);
        }
        o=o*((ld)mx/(ld)kl[c]);
        ans+=o;
    }

    cout.precision(15);
    cout <<fixed<< ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
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
12 19

8104756243030 6378153829074 7864481946698 7989644292977 6203792744877 7139461054198 7417193946416 6746398916257 7921954925499 8164742799871 6117430537523 7832265773212

2 7832265773212

1 8085437996816

2 7139461054198

1 6093518998518

2 7864481946698

2 7417193946416

2 6203792744877

2 6746398916257

1 7739700243907

2 7739700243907

1 7086445635445

1 6598712266235

2 6598712266235

1 6669032332134

2 7921954925499

1 6390459948701

2 7989644292977

2 8164742799871

1 5687905455139

*/