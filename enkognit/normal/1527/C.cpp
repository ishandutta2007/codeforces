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

ll n, m, k, a[1000001];

void solve()
{
    cin >> n;
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.pb(mp(a[i], i));
    }
    sort(all(v));
    ll l=0, ans=0;
    while (l<v.size())
    {
        ll r=l-1, sm1=0;
        while (r+1<v.size() && v[r+1].fi==v[l].fi)
        {
            r++;
            ans+=sm1*(n-v[r].se+1);
            sm1+=v[r].se;
        }
        l=r+1;
    }
    cout << ans << "\n";
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