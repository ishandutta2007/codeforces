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

ll md1=1e9+7, md2=998244357, p1=31, p2=127;

ll n, m, k, a, b, c, d, e, f, l, r, i, j;
bool tt[1000001];


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> a >> b >> c >> d >> e >> f;
    ll ans=0;
    for (ll i = 0; i <= d; i++)
    {
        ll o1=e*min(a,i), o2=f*min(min(b,c),d-i);
        ans=max(ans,o1+o2);
    }
    cout << ans;
    return 0;
}
/*
6 5 2
5 1 3 6 2 4
1 3
1 6
3 5
4 5
2 2

3 3 5
1 12 6
1 3
2 3
1 2

7 6 1
1 8 9 3 12 5 2
3 5
4 6
1 3
2 2
2 6
3 5
*/