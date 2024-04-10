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

ll n, m, T, k, l, r, i, j, sum, kol=0, a[1000001];
pll b[100001];
string s;
vector <pll> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, k;
        cin >> a >> b >> k;
        if (a>b) swap(a,b);
        ll p=__gcd(a,b);
        if (a-p>a*k-b) {cout << "REBEL\n";} else cout << "OBEY\n";
    }
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