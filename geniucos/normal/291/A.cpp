#include<cstdio>
using namespace std;
int n,i,j,nrp,nr,a[1009],ap[1009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
for(i=1;i<=n;i++)
if(ap[i]==0)
{
    if(a[i]==0) continue;
    nrp=0;
    for(j=i+1;j<=n;j++)
        if(a[i]==a[j])
        {
            nrp++;
            ap[j]=1;
        }
    if(nrp>1)
    {
        printf("-1\n");
        return 0;
    }
    if(nrp==1) nr++;
}
printf("%d\n",nr);
return 0;
}