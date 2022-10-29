#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, k, a[1000001];

void solve()
{
    ll a, b, c, p;
    cin >> p >>  a >> b >> c;
    cout << min(min((p/a)*a+((p/a)*a<p)*a-p, (p/b)*b+((p/b)*b<p)*b-p), (p/c)*c+((p/c)*c<p)*c-p) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
5
......
MMMC
......
CCCM
.X..X.
MMM
XXXXXX
CMMCM
......
MM

*/