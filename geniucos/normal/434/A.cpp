#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
long long I,nr,i,n,m,a[100009],x[100009];
long long sol,aux,s,mini,tot,sp[100009];
vector < long long > v[100009];
vector < long long > :: iterator it;
long long mod(long long x)
{
    if(x<0) return -x;
    return x;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%I64d",&n);
scanf("%I64d",&m);
for(i=1;i<=m;i++)
    scanf("%I64d",&a[i]);
for(i=2;i<=m;i++)
    if(a[i]!=a[i-1]) v[a[i]].push_back(a[i-1]);
for(i=1;i<m;i++)
    if(a[i]!=a[i+1]) v[a[i]].push_back(a[i+1]);
for(i=1;i<m;i++)
    s+=mod(a[i+1]-a[i]);
sol=s;
for(I=1;I<=n;I++)
{
    aux=s;
    for(it=v[I].begin();it!=v[I].end();it++)
        aux-=mod(*it-I);
    nr=0;
    for(it=v[I].begin();it!=v[I].end();it++)
        x[++nr]=*it;
    sort(x+1,x+nr+1);
    for(i=1;i<=nr;i++)
        sp[i]=sp[i-1]+x[i];
    mini=(long long)30000000000000000LL;
    for(i=1;i<=nr;i++)
    {
        tot=(long long)1LL*x[i]*(i-1)-sp[i-1]+sp[nr]-sp[i]-1LL*(nr-i)*x[i];
        if(tot<mini) mini=tot;
        if(tot+aux<sol) sol=tot+aux;
    }
    aux+=tot;
    if(aux<sol)
        sol=aux;
}
printf("%I64d\n",sol);
return 0;
}