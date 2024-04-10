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

ll n, m, k, T, sm, u[100005], a[100005], kol[100005], b[100005];
vector<ll> d[100005];
bool tt[100005];

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

ll kol_prime(ll h)
{
    ll ans=0;
    for (int i = 0; i < d[h].size(); i++)
    {
        ans+=u[d[h][i]]*kol[d[h][i]];
    }
    return ans;
}

void solve()
{
    cin >> n;
    ll ans=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans=max(ans, a[i]);
        ll p=sqrt(a[i]);
        /*for (int j = 1; j <= p; j++)
            if (a[i]%j==0)
            {
                g[j].pb(a[i]/j);
                if (a[i]/j>j) g[a[i]/j].pb(j);
            }*/
        tt[a[i]]=1;
    }

    for (int i = 1; i <= 1e5; i++)
    {
        for (int j = i; j <= 1e5; j+=i)
            d[j].pb(i);

        if (i==1) u[i]=1; else
        if ((i/d[i][1])%d[i][1]==0) u[i]=0; else
        u[i]=-u[i/d[i][1]];
    }
    ll len=0;
    for (ll i = 1; i <= 1e5; i++)
    {
        len=0;
        //if (i<3)cout << i << " : ";
        for (ll j = (ll)1e5/(ll)i; j > 0; j--)
            if (tt[i*j]==1)
            {
                ll o=kol_prime(j);
                //cout << " " << j*i << " " << tt[i*j] << " " << o << "\n";
                //system("pause");
                while (o>0)
                {
                    if (gcd(b[len], j)==1)
                    {
                        //cout << b[len] << " " << j << " " << i << "\n";
                        ans=max(ans, j*b[len]*(ll)i);
                        o--;
                    }
                    for (int u = 0; u < d[b[len]].size(); u++)
                        kol[d[b[len]][u]]--;
                    len--;
                }
                len++;
                for (int u = 0; u < d[j].size(); u++)
                    kol[d[j][u]]++;
                b[len]=j;
            }
        while (len)
        {
            for (int u = 0; u < d[b[len]].size(); u++)
                kol[d[b[len]][u]]--;
            len--;
        }
    }
    cout << ans << "\n";
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