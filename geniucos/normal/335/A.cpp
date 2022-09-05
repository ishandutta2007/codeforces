#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int nr,l,cnt,n,p,u,mij,ras,i,j,ap[300];
char sir[1009];
int mod(int x)
{
    if(x<0) return -x;
    return x;
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
int inside(int x1,int y1,int x2,int y2,int x,int y)
{
    return (x>=x1&&x<=x2&&y>=y1&&y<=y2);
}
int ok(int nr)
{
    int cate=n;
    for(i='a';i<='z';i++)
    if(ap[i])
    {
        if(ap[i]%nr==0) cnt=ap[i]/nr;
        else cnt=ap[i]/nr+1;
        cate-=cnt;
    }
    return (cate>=0);
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
gets(sir+1);
l=strlen(sir+1);
scanf("%d\n",&n);
for(i=1;i<=l;i++)
    ap[sir[i]]++;
for(i='a';i<='z';i++)
    if(ap[i]>0) nr++;
if(nr>n)
{
    printf("-1\n");
    return 0;
}
p=1;
u=l;
while(p<=u)
{
    mij=(p+u)>>1;
    if(ok(mij))
    {
        ras=mij;
        u=mij-1;
    }
    else p=mij+1;
}
printf("%d\n",ras);
nr=ras;
for(i='a';i<='z';i++)
if(ap[i])
{
    if(ap[i]%nr==0) cnt=ap[i]/nr;
    else cnt=ap[i]/nr+1;
    n-=cnt;
    for(j=1;j<=cnt;j++)
        printf("%c",(char)i);
}
for(i=1;i<=n;i++)
    printf("a");
printf("\n");
return 0;
}