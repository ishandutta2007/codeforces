#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 shue_ppsh
#define all(a) a.begin(),a.end()

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, T, i, kl, j, x, a[1000001];
string s;

void solve()
{
    ll n, g, b;
    cin >> n >> g >> b;
    ll p=(n+1)/2;
    ll o=p/g, l=p%g;
    if (l==0) cout << max((o-1)*(g+b)+g,n) << "\n"; else
    cout << max(o*(g+b)+l,n) << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
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
6 4
1 2
6 5
3 2
4 5
*/