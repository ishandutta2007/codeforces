#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, l, r, a, b, ans, dp[1000001];
string s, d;

template<typename T>
T sqr(T x)
{
    return x*x;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> a >> b;
    cin >> s;
    for (int i = 0; i <= n; i++) dp[i]=i*a;
    ll pos=0;
    for (int pos = 0; pos < n; pos++)
    {
        string u=s.substr(pos,s.size()-pos)+"@"+s.substr(0,pos);
        ll p[u.size()+10]={}, an=0;
        for (int i = 1; i < u.size(); i++)
        {
            ll j=p[i-1];
            while (j>0 && u[i]!=u[j]) j=p[j-1];
            //cout << u[i] << " " << u[j] << "\n";
            if (u[i]==u[j]) j++;
            p[i]=j;
            if (i>s.size()-pos)dp[pos+j]=min(dp[pos+j],dp[pos]+b);
        }
        dp[pos+1]=min(dp[pos+1],dp[pos]+a);
    }
    cout << dp[n];
    return 0;
}