#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int i,n,ul,b[300009];
int mod(int a)
{
    if(a<0) return -a;
    return a;
}
int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
struct str
{
    int v,p;
}a[300009];
bool cmp(str a,str b)
{
    return a.v<b.v;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    scanf("%d",&a[i].v);
    a[i].p=i;
}
sort(a+1,a+n+1,cmp);
ul=a[1].v;
b[a[1].p]=a[1].v;
for(i=2;i<=n;i++)
{
    if(a[i].v<=ul) a[i].v=ul+1;
    b[a[i].p]=a[i].v;
    ul=a[i].v;
}
for(i=1;i<=n;i++)
    printf("%d ",b[i]);
printf("\n");
return 0;
}