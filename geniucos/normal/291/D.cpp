#include<cstdio>
#include<vector>
using namespace std;
int e,j,nrmutari,i,n,k,ap[10009],a[10009];
int unde(int val)
{
    return n-val;
}
vector < int > v[15];
vector < int > ::iterator it;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&k);
if(n==1)
{
    for(i=1;i<=k;i++)
        printf("1\n");
    return 0;
}
for(e=0;(1<<e)<=n-1;e++)
    ;
e--;
for(i=1;i<n;i++)
{
    a[i]=n-i-1;
    for(j=0;j<=e;j++)
        if(a[i]&(1<<j)) v[j].push_back(i);
}
for(i=1;i<=e;i++)
{
    for(j=1;j<=n;j++)
        ap[j]=n;
    for(j=i;j<=e;j++)
        ap[n-(1<<j)]=n-(1<<(i-1));
    for(it=v[i-1].begin();it!=v[i-1].end();it++)
        if(ap[*it]==n) ap[*it]=n-(1<<(i-1));
    for(j=1;j<=n;j++)
        printf("%d ",ap[j]);
    printf("\n");
}
nrmutari=e;
if(!v[e].empty())
{
    nrmutari++;
    i=e+1;
    for(j=1;j<=n;j++)
        ap[j]=n;
    for(it=v[i-1].begin();it!=v[i-1].end();it++)
        if(ap[*it]==n) ap[*it]=n-(1<<(i-1));
    for(j=1;j<=n;j++)
        printf("%d ",ap[j]);
    printf("\n");
}
for(i=1;i<=k-nrmutari;i++)
{
    for(j=1;j<=n;j++)
        printf("%d ",n);
    printf("\n");
}
return 0;
}