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
        ll n, m;
        cin >> n >> m;
        if (n>m) swap(n,m);
        if ((m+n)%3!=0) {cout << "NO\n";continue;}
        if (m>n*2) {cout << "NO\n";continue;}
        cout << "YES\n";
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