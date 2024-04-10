//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const int MOD=1e9+7;
int n,a,b,k;
ll dp[2][5111],pre[5111];
ll f(ll x)
{
    while(x<0)x+=MOD;
    return x%MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>a>>b>>k;dp[0][a]=1;
    for(int i=1;i<=n;i++)
    {
        pre[i]=f(pre[i-1]+dp[0][i]);
    }
    for(int i=1;i<=k;i++)
    {
        int p=i&1;
        for(int i=1;i<=n;i++)
        {
            if(i<b)
            {
                dp[p][i]=f(pre[i-1]+pre[i+(b-i-1)/2]-pre[i]);
            }
            else if(i>b)
            {
                dp[p][i]=f(pre[n]-pre[i]+pre[i-1]-pre[i-(i-b-1)/2-1]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            pre[i]=f(pre[i-1]+dp[p][i]);
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)ans=f(ans+dp[k&1][i]);
    cout<<ans;
    return 0;
}