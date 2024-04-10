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

ll n, m, k, a[1000001];

void solve()
{
    ll a, b;
    cin >> a >> b;
    ll ans=1e18;
    for (int i = b+(b==1); i <= b+1000; i++)
    {
        ll j=i-b, x=a;
        while (x) x/=i, j++;
        ans=min(ans, j);
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
    ll t;
    cin >> t;
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