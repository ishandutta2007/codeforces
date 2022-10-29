#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define se second
#define fi first
#define ld long double
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define pld pair<ld,ld>
#define OO 1000000000000000000

using namespace std;

ll n, m, k, l, r, a[150001];

void solve()
{
    ll x, y;
    cin >> x >> y;
    ll p=(y)*(y+1)-y;
    if (x<p) cout << "NO\n"; else
    if ((x-p)%2) cout << "NO\n"; else cout << "YES\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}