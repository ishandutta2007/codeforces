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
#define y1 Enkognit

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, T, i, j, kl, x, y, a[1000001], p[1000001];
vector <ll> v;
map<pair<char,char>, char> w;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {cin >> a[i];p[a[i]]=i;}
    ll mn=1e18, mx=0;
    for (int i = 1; i <= n; i++)
    {
        mn=min(mn,p[i]);
        mx=max(mx,p[i]);
        if (mx-mn+1==i) cout << 1; else cout << 0;
    }
    cout << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}