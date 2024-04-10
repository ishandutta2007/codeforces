#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
long long xx,yy,n,aux,x,y,m;
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
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%I64d",&x);
scanf("%I64d",&y);
scanf("%I64d",&m);
if(x>=m||y>=m)
{
    printf("0\n");
    return 0;
}
if(x==0&&y==0)
{
    printf("-1\n");
    return 0;
}
if(x==0||y==0)
{
    if(x+y<0)
    {
        printf("-1\n");
        return 0;
    }
}
if(x>=y)
{
    aux=x;
    x=y;
    y=aux;
}
if(x<0&&y>0)
{
    n=(0-x)/y;
    if((0-x)%y!=0) n++;
    x+=n*y;
}
xx=x;
yy=y;
while(1)
{
    n++;
    if(x>y) y+=x;
    else x+=y;
    if(x<xx||y<yy)
    {
        printf("-1\n");
        return 0;;
    }
    if(x>=m||y>=m) break;
}
printf("%I64d\n",n);
return 0;
}