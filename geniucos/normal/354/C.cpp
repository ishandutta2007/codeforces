#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int ok,mini,maxi,nr,i,n,k,cum,a[300009],s[2000009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&k);
mini=10000009;
for(i=1;i<=n;i++)
{
    scanf("%d",&a[i]);
    if(a[i]<=k) ok=1;
    if(a[i]>maxi) maxi=a[i];
    if(a[i]<mini) mini=a[i];
}
if(ok)
{
    printf("%d\n",mini);
    return 0;
}
for(i=1;i<=n;i++)
    s[a[i]]++;
for(i=1;i<=2*maxi;i++)
    s[i]+=s[i-1];
for(cum=mini;cum>=k;cum--)
{
    for(i=0;i*cum<=maxi;i++)
        if(s[(i+1)*cum-1]>s[i*cum+k]) break;
    if(i*cum>maxi)
    {
        printf("%d\n",cum);
        return 0;
    }
}
printf("%d\n",cum);
return 0;
}