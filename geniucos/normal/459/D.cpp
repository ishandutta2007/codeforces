#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<string>
using namespace std;
int nm,v,i,n,a[1000009],aib[1000009],st[1000009],dr[1000009],ap[1000009];
long long ras;
pair < int , int > A[1000009];
void Read()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&A[i].first);
        A[i].second=i;
    }
    sort(A+1,A+n+1);
    v=0;
    for(i=1;i<=n;i++)
    {
        if(A[i].first!=A[i-1].first) v++;
        a[A[i].second]=v;
    }
}
void U(int poz,int v)
{
    while(poz<=nm)
    {
        aib[poz]+=v;
        poz+=poz-(poz&(poz-1));
    }
}
int Q(int poz)
{
    int s=0;
    while(poz)
    {
        s+=aib[poz];
        poz&=poz-1;
    }
    return s;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
Read();
for(i=1;i<=n;i++)
{
    ap[a[i]]++;
    st[i]=ap[a[i]];
    if(st[i]>nm) nm=st[i];
}
for(i=1;i<=n;i++)
    ap[a[i]]=0;
for(i=n;i>=1;i--)
{
    ap[a[i]]++;
    dr[i]=ap[a[i]];
    if(dr[i]>nm) nm=dr[i];
}
for(i=1;i<n;i++)
    U(st[i],1);
for(i=n;i>1;i--)
{
    ras+=i-1-Q(dr[i]);
    U(st[i-1],-1);
}
printf("%I64d\n",ras);
return 0;
}