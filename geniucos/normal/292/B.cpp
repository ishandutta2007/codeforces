#include<cstdio>
using namespace std;
int n,m,x,y,i,vs[100009],ap[10];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
for(i=1;i<=m;i++)
{
    scanf("%d",&x);
    scanf("%d",&y);
    vs[x]++;
    vs[y]++;
}
for(i=1;i<=n;i++)
    if(vs[i]!=n-1&&vs[i]!=1) break;
if(i>n)
{
    x=0;
    for(i=1;i<=n;i++)
        if(vs[i]==n-1) x++;
    if(x!=1) goto costin;
    printf("star topology\n");
    return 0;
}
costin:
for(i=1;i<=n;i++)
    if(vs[i]!=2) break;
if(i>n)
{
    printf("ring topology\n");
    return 0;
}
for(i=1;i<=n;i++)
    if(vs[i]>2) break;
if(i>n)
{
    for(i=1;i<=n;i++)
        ap[vs[i]]++;
    if(ap[2]==n-2&&ap[1]==2)
    {
        printf("bus topology\n");
        return 0;
    }
}
printf("unknown topology\n");
return 0;
}