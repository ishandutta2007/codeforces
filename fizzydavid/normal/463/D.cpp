//source:
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
const int INF=1<<28;
const long long LINF=1ll<<61;
int n,k,a[5][1011],dp[1011],p[5][1011];
int dfs(int x)
{
    if(dp[x])return dp[x];
    dp[x]=1;
    for(int j=1;j<=n;j++)
    {
        if(x==j)continue;
        bool ok=1;
        for(int t=0;t<k;t++)if(p[t][j]>p[t][x])ok=0;
        if(ok)dp[x]=max(dp[x],dfs(j)+1);
    }
    return dp[x];
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            p[i][a[i][j]]=j;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dfs(i));
//      cout<<dfs(i)<<" ";
    }
    cout<<ans;
    return 0;
}