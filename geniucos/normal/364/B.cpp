#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int nr,p,s,n,d,i,j,dr[53],tmp[53],aj[53],a[53],ok[500009],b[500009];
long long sol,T;
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
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&d);
for(i=1;i<=n;i++)
{
    scanf("%d",&a[i]);
    s+=a[i];
}
ok[0]=1;
for(i=1;i<=n;i++)
    for(j=s-a[i];j>=0;j--)
        if(ok[j]) ok[j+a[i]]=1;
for(i=0;i<=s;i++)
    if(ok[i])
    {
        nr++;
        b[nr]=i;
    }
s=0;
p=1;
while(1)
{
    if(b[p]<=s+d&&p<=nr)
    {
        while(b[p]<=s+d&&p<=nr) p++;
        s=b[p-1];
        T++;
    }
    else break;
}
if(s==0) T=0;
printf("%d %d\n",s,T);
return 0;
}