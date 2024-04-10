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
#define all(v) v.begin(),v.end()

using namespace std;

const ll MOD=1e9+7;

ll n, m, k, q, T, a[300005];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%MOD;
        h=(h*h)%MOD;
        r/=2;
    }
    return l;
}

void solve()
{
    cin >> n;
    ll k=8;
    if (n==1)
    {
        cout << "9\n";
        return;
    }
    cout << "98";
    n-=2;
    while (n)
    {
        n--;
        k++;
        if (k>9) k-=10;
        cout << k;
    }
    cout << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
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