#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int j,nr,n,p,i,ul,pl,ok,x[1009],dp[2009],a[1009],ap[1009],app[1009];
vector < int > v;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&p);
for(i=1;i<=n;i++)
{
    scanf("%d",&x[i]);
    app[x[i]]=1;
}
for(i=1;i<=n;i++)
if(ap[i]==0&&x[i]!=0&&app[i]==0)
{
    ul=i;
    v.clear();
    v.push_back(i);
    ap[ul]=1;
    while(1)
    {
        ul=x[ul];
        if(ul==0) break;
        ap[ul]=1;
        v.push_back(ul);
    }
    reverse(v.begin(),v.end());
    if(ok==0&&ap[p]!=0)
    {
        for(j=0;j<v.size();j++)
            if(v[j]==p) break;
        pl=j+1;
        ok=1;
    }
    else
    {
        nr++;
        a[nr]=v.size();
    }
}
for(i=1;i<=n;i++)
    if(ap[i]==0&&x[i]==0)
    {
        if(i==p) pl=1;
        else
        {
            nr++;
            a[nr]=1;
        }
    }
dp[0]=1;
for(i=1;i<=nr;i++)
    for(j=n-a[i];j>=0;j--)
        if(dp[j+a[i]]==0&&dp[j]==1) dp[j+a[i]]=1;
for(i=0;i+pl<=n;i++)
    if(dp[i]) printf("%d\n",i+pl);
return 0;
}