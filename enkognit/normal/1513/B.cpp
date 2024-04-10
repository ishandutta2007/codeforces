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

ll n, m, k, sz, fact[200005], infact[200005];
ll a[200005];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}

void solve()
{
    cin >> n;
    ll mn=1e18, k=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (mn>a[i])
        {
            mn=a[i];
            k=1;
        }else
        if (mn==a[i])
        {
            k++;
        }
    }
    //cout << mn << " " << k << "\n";
    ll u=(1ll<<30)-1;
    bool t=1;
    for (int i = 1; i <= n; i++)
        if (!t && a[i]==mn) t=1; else u&=a[i];
    if (u!=mn || k<2)
    {
        cout << "0\n";
        return;
    }
    cout << fact[n-2]*fact[k]%MOD*infact[2]%MOD*infact[k-2]*2%MOD << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    fact[0]=1;
    infact[0]=1;
    for (int i = 1; i <= 200000; i++)
    {
        fact[i]=fact[i-1]*i%MOD;
        infact[i]=binpow(fact[i], MOD-2, MOD);
    }
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*
6 6 1 12
1 2 1 1 1
2 4 1 1 1
1 3 1 1 2
3 5 1 1 2
5 4 1 1 1
5 6 1 1 1
1 5
3
5
*/