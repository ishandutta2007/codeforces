#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define se second
#define fi first
#define ld long double

using namespace std;

ll md1=1e9+9, md2=998244357, p1=8244357, p2=3131313;

ll n, m, k, i, j, h, a[101];
ll dp[1000001];
string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> s;
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        ll p=s[i]-'a';
        ll o=0;
        for (int i = p+1; i <= 'z'-'a'; i++)
            o=max(o,a[i]);
        dp[i]=o+1;
        a[p]=o+1;
        ans=max(ans,dp[i]);
    }
    cout << ans << "\n";
    for (int i = 0; i < s.size(); i++)  cout << dp[i] << " ";
    return 0;
}
/*
*/