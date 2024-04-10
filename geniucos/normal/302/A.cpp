#include<cstdio>
using namespace std;
int l,n,i,m,x1,y1,val,ap[4];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
for(i=1;i<=n;i++)
{
    scanf("%d",&val);
    if(val==-1) ap[1]++;
    else ap[2]++;
}
for(i=1;i<=m;i++)
{
    scanf("%d",&x1);
    scanf("%d",&y1);
    l=y1-x1+1;
    if(l&1)
    {
        printf("0\n");
        continue;
    }
    if(ap[1]>=l/2&&ap[2]>=l/2) printf("1\n");
    else printf("0\n");
}
return 0;
}