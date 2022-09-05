#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int ul,i,j,n,l,r,Ql,Qr,w[100009],s[100009];
long long mini,cost,c1,c2;
int mod(int x)
{
    if(x<0) return -x;
    return x;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&l);
scanf("%d",&r);
scanf("%d",&Ql);
scanf("%d",&Qr);
for(i=1;i<=n;i++)
{
    scanf("%d",&w[i]);
    s[i]=s[i-1]+w[i];
}
mini=100000000000;
for(i=0;i<=n;i++)
{
    if(mod(2*i-n)<=1)
    {
        cost=1LL*s[i]*l+1LL*(s[n]-s[i])*r;
        if(cost<mini) mini=cost;
    }
    else
    {
        cost=1LL*s[i]*l+(s[n]-s[i])*r;
        if(i>n-i) cost+=1LL*Ql*(i-(n-i+1));
        else cost+=1LL*Qr*(n-i-(i+1));
        if(cost<mini) mini=cost;
    }
}
printf("%I64d\n",mini);
return 0;
}