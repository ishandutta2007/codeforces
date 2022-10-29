#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

ll n, m, T, k, l, r, i, j, o, kol=0, a[2000001], b[2000001];map<ll,bool> tt;
vector <ll> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> o;
    ll l1=0, r1=0, l2=0, r2=0;
    for (int i = 1; i <= n; i++) {cin >> a[i];tt[a[i]]=1;}
    ll ans=1;
    cin >> m >> o;
    for (int i = 1; i <= m; i++) {cin >> b[i];if (tt[b[i]]) ans=2;}
    for (ll j = 2; j <= 2e9; j*=2)
    {
        map<ll,ll> w, p;
        for (int i = 1; i <= n; i++) {w[a[i]%j]++;ans=max(ans,w[a[i]%j]);}
        for (int i = 1; i <= m; i++) {p[b[i]%j]++;ans=max(p[b[i]%j]+w[(b[i]%j+j/2)%j],ans);}
    }
    cout << ans;
    return 0;
}
/*
5 6
X...XX
XX...X
......
..XX..
XXX..X
*/