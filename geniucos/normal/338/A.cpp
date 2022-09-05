#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int mod,n,m,k,v,p,u,ras,mij;
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
int ok(int kk)
{
    int cate,aux=m-1LL*kk*k;
    if(aux%(k-1)==0) cate=aux/(k-1);
    else cate=aux/(k-1)+1;
    return (n-k*kk>=1LL*(aux/(k-1))*(k-1)+aux%(k-1)+cate-1);
}
int pow(int a,int b)
{
    int i,p=1;
    for(i=0;(1<<i)<=b;i++)
    {
        if(b&(1<<i)) p=(1LL*p*a)%mod;
        a=(1LL*a*a)%mod;
    }
    return p;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
scanf("%d",&k);
mod=1000000009;
p=0;
u=m/k+1;
ok(1);
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
m-=ras*k;
v=m%mod;
v+=(1LL*(pow(2,ras+1)-2)*k)%mod;
v%=mod;
v+=mod;
v%=mod;
printf("%d\n",v);
return 0;
}