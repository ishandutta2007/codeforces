#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int X,Maxi,tip,Nr,N,x,maxi,i,j,k,n,INF,dp[2009][2009][2],t[2009],h[2009],m[2009],T[2009],M[2009],H[2009],ap[2009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
INF=1<<28;
scanf("%d",&n);
scanf("%d",&x);
X=x;
for(i=1;i<=n;i++)
{
    scanf("%d",&t[i]);
    scanf("%d",&h[i]);
    scanf("%d",&m[i]);
}
tip=0;
while(1)
{
    Maxi=0;
    j=-1;
    for(i=1;i<=n;i++)
        if(ap[i]==0&&t[i]==tip&&h[i]<=x&&m[i]>Maxi) Maxi=m[i],j=i;
    if(j==-1) break;
    ap[j]=1;
    x+=Maxi;
    Nr++;
    tip^=1;
}
maxi=max(maxi,Nr);
for(i=1;i<=n;i++)
    ap[i]=0;
Nr=0;
tip=1;
x=X;
while(1)
{
    Maxi=0;
    j=-1;
    for(i=1;i<=n;i++)
        if(ap[i]==0&&t[i]==tip&&h[i]<=x&&m[i]>Maxi) Maxi=m[i],j=i;
    if(j==-1) break;
    ap[j]=1;
    x+=Maxi;
    Nr++;
    tip^=1;
}
maxi=max(maxi,Nr);
printf("%d\n",maxi);
return 0;
}