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
#define y1 Enkognit

using namespace std;

const ll MOD = 1000000007;

ll n, k, l, m, r, i, j, x, y, ans, dp[1500001], tt[1500001];
string s;


ll func(string s)
{
    ll n=s.size();
    s=' '+s;
    //for (int i = 1; i <= n; i++)
    for (ll i = 1; i <= n; i++)
    {
        ll x=0;
        //cout << i << ": ";
        for (int j = i; j <= min(i+19,n); j++)
        {
            ll p=(1<<(s[j]-'a'));
            if (x&p) break;
            x|=(1<<(s[j]-'a'));
            dp[x]=max(dp[x],j-i+1);
            tt[x]=j-i+1;
            //cout << d[i][j-i+1] << " ";
        }
        //cout << "\n";
    }
    for (int i = 1; i < 1<<20; i++)
    {
        for (int j = 0; j < 20; j++)
            if ((i&(1<<j))==0) dp[i|(1<<j)]=max(dp[i],dp[i|(1<<j)]);
    }
    ll ans=0;
    for (int i = 1; i < 1<<20; i++)
        if (tt[i])
            ans=max(ans,tt[i]+dp[((1<<20)-1)^i]);
    return ans;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s;
    ll p=func(s);
    cout << p;
    return 0;
}
/*
6 15
E 5
V 9
M 3
V 2
M 5
V 6
*/