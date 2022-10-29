#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("popcnt")
#include <random>
#include <time.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

mt19937_64 rnd(time(0));

ll n, m, k, f;
bitset<100001> dp;
vector<pll> v, u;
ll a[100001];

void solve()
{
    cin >> n;
    ll o=1;
    while (o*2<=n)
    {
        o*=2;
    }
    cout << o-1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
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
1000000000000000 4523 3
456 23
4562 78
456239 456
*/