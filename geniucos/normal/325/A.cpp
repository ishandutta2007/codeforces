#include<cstdio>
#include<algorithm>
using namespace std;
int n,i,x1[10],x2[10],y1[10],y2[10],X1,Y1,X2,Y2;
long long s;
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
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
X1=100000;
X2=-100000;
Y1=100000;
Y2=-100000;
for(i=1;i<=n;i++)
{
    scanf("%d",&x1[i]);
    scanf("%d",&y1[i]);
    scanf("%d",&x2[i]);
    scanf("%d",&y2[i]);
    s=s+1LL*(x2[i]-x1[i])*(y2[i]-y1[i]);
    if(y1[i]<Y1) Y1=y1[i];
    if(y2[i]>Y2) Y2=y2[i];
    if(x1[i]<X1) X1=x1[i];
    if(x2[i]>X2) X2=x2[i];
}
for(i=1;1LL*i*i<=s;i++)
    ;
i--;
if(1LL*i*i!=s)
{
    printf("NO\n");
    return 0;
}
if(X2-X1!=i||Y2-Y1!=i)
{
    printf("NO\n");
    return 0;
}
printf("YES\n");
return 0;
}