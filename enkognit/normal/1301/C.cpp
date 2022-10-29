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
vector<ll> v;

void solve()
{
    cin >> n >> m;
    ll p=n-m;
    ll o=p/(m+1), u=p%(m+1);
    //cout << n*(n+1)/2 << " " << u*(o+2)*(o+1)/2 << " " << (m+1-u)*(o+1)*o/2 << "\n";
    cout << n*(n+1)/2-u*(o+2)*(o+1)/2-(m+1-u)*(o+1)*o/2 << "\n";
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