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

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

ll n, m, k, a[200005], pr[200005], tt[200005];

void solve()
{
    ll q;
    cin >> n >> q >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        //tt[i]=tt[i-1];
        //if (a[i]<=a[i-1]) tt[i]++;
        if (i>2) pr[i]=pr[i-1]+(a[i]-a[i-2]-2);
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        if (l==r)cout << k-1 << "\n"; else
        {
            //cout << pr[r] << " " << pr[l+1] << "\n";
            cout << (l+2<=r?pr[r]-pr[l+1]:0)+(a[l+1]-2)+(k-a[r-1]-1) << "\n";
        }
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
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*

10
4 1 7 6 5 5 4 2 3 1
*/