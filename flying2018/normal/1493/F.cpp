#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 100010
using namespace std;
int big[N],n,m,flg,c=0;
vector<int>v;
bool push(int x0,int x1,int x)//[x0,x0+x)==[x1,x1+x)
{
    if(!flg) printf("? %d %d %d %d %d %d\n",x,m,x0,1,x1,1);
    else printf("? %d %d %d %d %d %d\n",n,x,1,x0,1,x1);
    fflush(stdout);
    int res=1;
    scanf("%d",&res);
    return res;
}
bool qeury(int p,int d)
{
    if(p==2) return push(1,d+1,d);
    if(p==3) return push(1,d+1,d) && push(d+1,d*2+1,d);
    int q=d*(p/2);
    return push(1,q+1,q) && push(1,q+d+1,q) && push(d+1,q+d+1,q);
}
int main()
{
    scanf("%d%d",&n,&m);
    int x=max(n,m);
    for(int i=1;i<=x;i++) big[i]=i;
    for(int i=2;i<=x;i++)
        for(int j=i*2;j<=x;j+=i) big[j]=min(big[j],i);
    int rn=n;
    for(int r=n;r>1;r/=big[r])
    if(qeury(big[r],rn/big[r])) rn/=big[r];
    flg=true;
    int rm=m;
    for(int r=m;r>1;r/=big[r])
    if(qeury(big[r],rm/big[r])) rm/=big[r];
    rn=n/rn;rm=m/rm;
    int cn=0,cm=0;
    for(int i=1;i<=rn;i++)
    if(rn%i==0) cn++;
    for(int i=1;i<=rm;i++)
    if(rm%i==0) cm++;
    printf("! %lld\n",1ll*cn*cm);
    return 0;
}