#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<string>
using namespace std;
int i,mod,n,dp[100009],x[100009],cartel[100009],P[100009],t[100009];
vector < int > fii[100009];
void DP(int nod)
{
    if(fii[nod].empty())
    {
        x[nod]=1-cartel[nod];
        dp[nod]=cartel[nod];
        return ;
    }
    vector < int > :: iterator it;
    for(it=fii[nod].begin();it!=fii[nod].end();it++)
        DP(*it);
    if(cartel[nod]==0)
    {
        int prod=1;
        for(it=fii[nod].begin();it!=fii[nod].end();it++)
            prod=(1LL*prod*(x[*it]+dp[*it]))%mod;
        x[nod]=prod;
        /////////////////////////////////////////
        prod=1;
        dp[nod]=0;
        P[fii[nod].size()]=1;
        for(i=fii[nod].size()-1;i>=0;i--)
            P[i]=(1LL*P[i+1]*(x[fii[nod][i]]+dp[fii[nod][i]]))%mod;
        for(i=0;i<fii[nod].size();i++)
        {
            dp[nod]=((long long)dp[nod]+
                     1LL*((1LL*prod*P[i+1])%mod)*dp[fii[nod][i]])%mod;
            prod=(1LL*prod*(x[fii[nod][i]]+dp[fii[nod][i]]))%mod;
        }
    }
    else
    {
        x[nod]=0;
        ////////
        int prod=1;
        for(it=fii[nod].begin();it!=fii[nod].end();it++)
            prod=(1LL*prod*(x[*it]+dp[*it]))%mod;
        dp[nod]=prod;
    }
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
mod=1000000007;
scanf("%d",&n);
for(i=1;i<n;i++)
    scanf("%d",&t[i]),fii[t[i]].push_back(i);
for(i=0;i<n;i++)
    scanf("%d",&cartel[i]);
DP(0);
printf("%d\n",dp[0]);
return 0;
}