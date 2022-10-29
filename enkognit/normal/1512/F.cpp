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

ll n, m, k, sz, ost[200005], a[200005], b[200005], mn[200005];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h;
        h*=h;
        r/=2;
    }
    return l;
}

void solve()
{
    ll c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        cin >> b[i];
    }
    ll sm=0, kol=0, ans=1e18;
    for (int i = 1; i <= n; i++)
    {
        mn[i]=kol;
        ost[i]=sm;
        //cout << i << " : " << mn[i] << " " << ost[i] << "\n";
        //cout << mn[i]+max((c-ost[i])/a[i], 0ll) << "\n";
        //cout << i << " " << mn[i] << " " << ost[i] << " " << a[i] << " " << (b[i]-sm)/a[i] << " " << b[i]-sm << "\n";
        ans=min(ans, mn[i]+max((c-ost[i]+a[i]-1)/a[i], 0ll));
        kol+=max((b[i]-sm)/a[i],0ll);
        sm+=max((b[i]-sm)/a[i],0ll)*a[i];
        //cout << " " << sm << " " << kol << "\n";
        while (sm<b[i])
        {
            sm+=a[i];
            kol++;
        }
        kol++;
        sm-=b[i];
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