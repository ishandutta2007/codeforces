#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

ll n, m, k, sz, k1, k2, a[300005], b[300005], pr[300005];
vector<ll> c[200005];
string s;

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
    ll l, r;
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) a[i]=0;
    for (int i = 1; i <= l; i++)
    {
        ll x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= r; i++)
    {
        ll x;
        cin >> x;
        a[x]--;
    }
    ll sl=0, sr=0, kl=0,kr=0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i]>0)
        {
            kl+=a[i];
            sl+=a[i]/2;
        }else
        if (a[i]<0)
        {
            a[i]=-a[i];
            kr+=a[i];
            sr+=a[i]/2;
        }
    }
    ll ans=0;
    //cout << kl << " " << kr << "\n";
    while (kl>kr && sl>0)
    {
        sl--;
        ans++;
        kl-=2;
    }
    while (kl<kr && sr>0)
    {
        sr--;
        ans++;
        kr-=2;
    }
    ans+=min(kl,kr)+abs(kl-kr)/2*2;
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
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
999999999
*/