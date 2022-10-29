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

ll n, m, k, f, l, r, i, j, ML, MR, T, O, num, kol[2000001], ANS=1e18;
vector <pll> a[1000001];
vector <ll> c[1000001];
ll nm[1000001];
ll rast[1000001];
bool tt[1000001];
vector <pll> vv;

void solve()
{
    ll x, y;
    cin >> x >> y;
    ll p=__gcd(x,y), o=y/p;
    ld ans=o;
    for (ll i = 2; i*i <= o; i++)
        if (o%i==0)
    {
        while (o%i==0) o/=i;
        ans-=ans/(ld)i;
    }
    if (o>1) ans-=ans/(ld)o;
    cout.precision(0);
    cout <<fixed<< ans << "\n";
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
3 2
0 1
1 2
1 2
2 3
2 3
3 4
1 2
2 3

3 4
0 0 0 0
1 1 1 1
1 1 1 1
2 2 2 2
0 0 0 0
2 3 2 3
1 3
2 3
*/
/*

}


*/