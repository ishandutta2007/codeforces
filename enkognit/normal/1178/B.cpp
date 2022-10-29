#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

const ll MOD = 998244353;

ll n, m, k, q, p, ans, l, r, i, j, g0, x, y, z;
pll a[100001];
string s;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s;
    ll l=0, r=0, n=s.size(), q=0;
    for (int i = 1; i < n; i++)
        if (s[i]=='v' && s[i-1]=='v')
        {
            r++;
            ans+=q;
            //cout << i << " " <<  "\n";
        }else
        if (s[i]=='o') l+=r, q+=l, r=0;
    cout << ans;
    return 0;
}


/*

| 1 5 13 29 | 2 7 17 37 | 18 39 22 47 |


*/