#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int exp,nr,n,l,p,lp,L,i,b[2000008];
long long s,sum;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
p=1;
for(i=0;i<=40;i++)
{
    if(p==n) break;
    p=p<<2;
}
L=i;
for(i=1;i<=n;i++)
    scanf("%d",&b[i]);
sort(b+1,b+n+1);
lp=0;
p=1;
sum=0;
nr=n;
for(exp=0;exp<=L;exp++)
{
    l=p-lp;
    s=0;
    for(i=nr-l+1;i<=nr;i++)
        s+=b[i];
    sum+=1LL*s*(L+1-exp);
    nr=nr-l;
    lp=p;
    p=p*4;
}
printf("%I64d\n",sum);
return 0;
}