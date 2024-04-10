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
    v.clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i]!=a[i-1] && i>1) v.pb(i);
    }
    v.pb(n);
    if (v.size()<3) {cout << "0 0 0\n";return;}
    ll l=0, r=0;
    for (int i = 1; i < v.size(); i++)
        if (v[i]-v[0]>v[0]-1) {l=i;break;}
    for (int i = l+1; i < v.size(); i++)
        if (v[i]-1<=n/2 && v[i]-v[l]>v[0]-1) r=i;
    if (l==0 || r==0) {cout << "0 0 0\n";return;}
    cout << v[0]-1 << " " << v[l]-v[0] << " " << v[r]-v[l] << "\n";
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