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
int i,n,m,p,u,mij,ras,a[100009],b[100009];
long long mini,s1[100009],s2[100009];
long long cost(int val)
{
    long long R=0;
    p=1;
    u=n;
    ras=0;
    while(p<=u)
    {
        mij=(p+u)>>1;
        if(a[mij]<=val)
        {
            ras=mij;
            p=mij+1;
        }
        else u=mij-1;
    }
    if(ras==0) ;
    else R+=1LL*ras*val-s1[ras];
    ////////////////////////////////////////////////////////////////////
    p=1;
    u=m;
    ras=0;
    while(p<=u)
    {
        mij=(p+u)>>1;
        if(b[mij]>=val)
        {
            ras=mij;
            u=mij-1;
        }
        else p=mij+1;
    }
    if(ras==0) ;
    else R+=s2[m]-s2[ras-1]-1LL*(m-ras+1)*val;
    return R;
}
void U(long long cat)
{
    if(cat<mini) mini=cat;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
mini=(long long)500000000000000000LL;
scanf("%d",&n);
scanf("%d",&m);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
for(i=1;i<=m;i++)
    scanf("%d",&b[i]);
sort(a+1,a+n+1);
sort(b+1,b+m+1);
for(i=1;i<=n;i++)
    s1[i]=s1[i-1]+a[i];
for(i=1;i<=m;i++)
    s2[i]=s2[i-1]+b[i];
for(i=m;i>=1;i--)
    U(cost(b[i]));
cost(2);
for(i=n;i>=1;i--)
    U(cost(a[i]));
printf("%I64d\n",mini);
return 0;
}