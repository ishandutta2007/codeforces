#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int mij,ras,i,A,n,m,st,dr,b[100009],p[100009];
long long tot;
int ok(int k)
{
    long long tot=0;
    for(i=1;i<=k;i++)
    {
        if(b[n-k+i]<p[i]) tot+=p[i]-b[n-k+i];
        if(tot>A) return 0;
    }
    return 1;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
scanf("%d",&A);
for(i=1;i<=n;i++)
    scanf("%d",&b[i]);
sort(b+1,b+n+1);
for(i=1;i<=m;i++)
    scanf("%d",&p[i]);
sort(p+1,p+m+1);
st=0;
dr=m;
if(n<m) dr=n;
while(st<=dr)
{
    mij=(st+dr)>>1;
    if(ok(mij))
    {
        ras=mij;
        st=mij+1;
    }
    else dr=mij-1;
}
printf("%d ",ras);
tot=-A;
for(i=1;i<=ras;i++)
    tot+=p[i];
if(tot<0) tot=0;
printf("%I64d\n",tot);
return 0;
}