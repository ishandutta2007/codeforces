#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int nr,tip,i,n,m,val,pf[100009],b[100009],C[100009];
long long poz,l,a[100009];
int V(long long poz)
{
    int p,u,mij,ras;
    p=1;
    u=n;
    while(p<=u)
    {
        mij=(p+u)>>1;
        if(a[mij]>=poz)
        {
            ras=mij;
            u=mij-1;
        }
        else p=mij+1;
    }
    if(b[ras]>0) return b[ras];
    poz=poz-a[ras-1];
    poz=poz%pf[ras];
    if(poz==0) poz=pf[ras];
    return V(poz);
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    scanf("%d",&tip);
    if(tip==1)
    {
        scanf("%d",&val);
        l++;
        a[++nr]=l;
        b[nr]=val;
    }
    else
    {
        scanf("%d",&pf[i]);
        scanf("%d",&C[i]);
        l+=1LL*pf[i]*C[i];
        a[++nr]=l;
    }
}
scanf("%d",&m);
//return 0;
while(m)
{
    m--;
    scanf("%I64d",&poz);
    printf("%d ",V(poz));
}
return 0;
}