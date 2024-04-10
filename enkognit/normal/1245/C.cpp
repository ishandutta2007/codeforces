#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, dp[1000001];
pll b[100001];
string s, d;
vector <ll> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    ll l=0, r=0;
    s+=' ';
    vector <ll> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='w' || s[i]=='m') {cout << 0;exit(0);}
        if (s[i]=='u') l++; else {if (l!=0)v.pb(l),l=0;}
        if (s[i]=='n') r++; else {if (r!=0)v.pb(r),r=0;}
    }
    dp[0]=1;
    for (int i = 0; i <= 1e6; i++)
    {
        dp[i]%=MOD;
        dp[i+1]+=dp[i];
        dp[i+2]+=dp[i];
    }
    ll ans=1;
    for (int i = 0; i < v.size(); i++)
    {
        //cout << v[i] << "\n";
        ans*=dp[v[i]];
        ans%=(ll)(1e9+7);
    }
    cout << ans << "\n";
    return 0;
}