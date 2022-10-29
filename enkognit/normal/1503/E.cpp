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

const ll MOD=998244353;

ll n, T, m, e, ans, fact[5050], infact[5050];

ll C(ll n,ll k)
{
    //cout << " " << n << " " << k << " " << fact[n]*infact[k]%MOD*infact[n-k]%MOD << "\n";
    return fact[n]*infact[k]%MOD*infact[n-k]%MOD;
}

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%MOD;
        h=(h*h)%MOD;
        r/=2;
    }
    return l;
}

ll get(int n,int m)
{
    ll an=0;

    for (int i = 1; i < m; i++)
    {
        ll sm=0, lst=0;
        for (int j = 1; j <= n; j++)
        {
            ll o=C((n-j)+(i), (i))*C((j-1)+(i-1), i-1)%MOD;
            an=(an+o*sm%MOD)%MOD;
            if (T==0)
            {
                e=(e+lst*o%MOD)%MOD;
                //if (ans<0) ans+=MOD;
            }
            lst=(C(j-1+(m-i), (m-i)) * C((n-j)+(m-i-1), (m-i-1)))%MOD;
            sm=(sm+lst)%MOD;
        }
    }

    an=an*2%MOD;

    T=1;

    return an;
}

void solve()
{
    cin >> n >> m;

    /*for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            pr[i][j]=C((i-1)+j, j)*C(n-i-1+(j-1), j-1);
            if (j>0) pr[i][j]=pr[i][j-1];
        }*/


    ans=(get(n, m)+get(m, n))%MOD;

    //cout << e << "\n";

    ans-=e*2;
    while (ans<0) ans+=MOD;

    //ans=(ans*2)%MOD;
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    fact[0]=1;
    infact[0]=1;
    for (ll i = 1; i <= 5000; i++)
    {
        fact[i]=fact[i-1]*i%MOD;
        infact[i]=binpow(fact[i],MOD-2);
    }
    //cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*

*/