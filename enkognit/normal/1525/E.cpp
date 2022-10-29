#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
#define ld long double
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

const ld E=1e-12;
const ll MOD=998244353;

ll n, m, a[21][50001], kol[50], fact[50], infact[50];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1)  l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    fact[0]=1;
    infact[0]=1;
    for (int i = 1; i <= n; i++)
    {
        fact[i]=fact[i-1]*i%MOD;
        infact[i]=binpow(fact[i], MOD-2, MOD);
    }

    ll ans=0;

    for (int i = 1; i <= m; i++)
    {
        for (int i = 1; i <= n+1; i++) kol[i]=0;

        for (int j = 1; j <= n; j++)
        {
            kol[a[j][i]]++;
        }
        ll kl=kol[n+1], o=1;
        for (int j = n; j > 0; j--)
        {
            if (kl==0)
            {
                o=0;
                break;
            }
            o=o*kl%MOD;
            kl--;
            kl+=kol[j];
        }

        //cout <<

        o=fact[n]-o;

        //cout << o << "\n";
        if (o<0) o+=MOD;
        ans=(ans+o)%MOD;
    }

    cout << ans*infact[n]%MOD << "\n";
    return 0;
}
/*
v.pb(mp(399, -313));
v.pb(mp(-414, -333));
v.pb(mp(-722, -693));
v.pb(mp(-743, 266));
v.pb(mp(476, -456));
v.pb(mp(-583, -22));
v.pb(mp(-362, 613));
v.pb(mp(-912, 321));
v.pb(mp(-724, -854));
v.pb(mp(-1, 410));
v.pb(mp(-210, 720));
v.pb(mp(-22, 798));
v.pb(mp(26, 731));
v.pb(mp(-931, 831));
v.pb(mp(972, 432));
v.pb(mp(-382, -240));
v.pb(mp(-333, 367));
v.pb(mp(657, 304));
v.pb(mp(936, 842));
v.pb(mp(-112, 702));
v.pb(mp(-689, -552));
v.pb(mp(372, -518));
v.pb(mp(904, 754));
v.pb(mp(428, 543));
v.pb(mp(-231, -343));
v.pb(mp(172, 595));
v.pb(mp(665, 491));
v.pb(mp(739, 917));
v.pb(mp(-122, 668));
v.pb(mp(-1000, -995));
v.pb(mp(756, 839));
v.pb(mp(-1000, -990));
v.pb(mp(-1000, -798));
v.pb(mp(-1000, -785));
v.pb(mp(623, 737));
v.pb(mp(-1000, -677));
v.pb(mp(-1000, -560));
v.pb(mp(-1000, -520));
v.pb(mp(-999, 122));
v.pb(mp(-996, 34));
v.pb(mp(-901, -935));
v.pb(mp(-869, -322));
v.pb(mp(236, 981));
*/