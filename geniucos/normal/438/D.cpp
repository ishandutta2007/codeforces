#include<cstdio>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
int i,x,y,tip,n,m,R,a[100009],ma[400009];
long long s,sum[400009];
void build(int nod,int st,int dr)
{
    if(st==dr)
    {
        sum[nod]=ma[nod]=a[st];
        return;
    }
    int mij=(st+dr)>>1;
    build(nod<<1,st,mij);
    build((nod<<1)+1,mij+1,dr);
    sum[nod]=sum[nod<<1]+sum[(nod<<1)+1];
    ma[nod]=max(ma[nod<<1],ma[(nod<<1)+1]);
}
void U1(int nod,int st,int dr,int x,int y,int R)
{
    int mij=(st+dr)>>1;
    if(st==dr)
    {
        sum[nod]=ma[nod]=a[st]=a[st]%R;
        return;
    }
    if(x<=st&&dr<=y)
    {
        if(ma[nod<<1]>=R) U1(nod<<1,st,mij,x,y,R);
        if(ma[(nod<<1)+1]>=R) U1((nod<<1)+1,mij+1,dr,x,y,R);
    }
    else
    {
        if(x<=mij) U1(nod<<1,st,mij,x,y,R);
        if(y>mij) U1((nod<<1)+1,mij+1,dr,x,y,R);
    }
    sum[nod]=sum[nod<<1]+sum[(nod<<1)+1];
    ma[nod]=max(ma[nod<<1],ma[(nod<<1)+1]);
}
void U2(int nod,int st,int dr,int poz,int newval)
{
    if(st==dr)
    {
        ma[nod]=sum[nod]=a[poz]=newval;
        return;
    }
    int mij=(st+dr)>>1;
    if(poz<=mij) U2(nod<<1,st,mij,poz,newval);
    if(poz>mij) U2((nod<<1)+1,mij+1,dr,poz,newval);
    sum[nod]=sum[nod<<1]+sum[(nod<<1)+1];
    ma[nod]=max(ma[nod<<1],ma[(nod<<1)+1]);
}
void Q(int nod,int st,int dr,int x,int y)
{
    if(x<=st&&dr<=y)
    {
        s+=sum[nod];
        return;
    }
    int mij=(st+dr)>>1;
    if(x<=mij) Q(nod<<1,st,mij,x,y);
    if(y>mij) Q((nod<<1)+1,mij+1,dr,x,y);
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
build(1,1,n);
while(m)
{
    m--;
    scanf("%d",&tip);
    if(tip==1)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        s=0;
        Q(1,1,n,x,y);
        printf("%I64d\n",s);
    }
    else
    if(tip==2)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        scanf("%d",&R);
        U1(1,1,n,x,y,R);
    }
    else
    {
        scanf("%d",&x);
        scanf("%d",&y);
        U2(1,1,n,x,y);
    }
}
return 0;
}