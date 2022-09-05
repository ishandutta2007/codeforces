#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int ok,st,dr,k;
long long mij,p,ras,n,V;
int mod(int x)
{
    if(x<0) return -x;
    return x;
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
vector < long long > v;
vector < long long >::iterator it;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%I64d",&n);
for(k=0;(1LL<<k)<=n+1;k++)
{
    st=0;
    dr=1000000000;
    ras=0;
    while(st<=dr)
    {
        mij=(st+dr)>>1LL;
        p=1LL*mij*2+1;
        ok=0;////1 daca e prea mare
        if(1LL*p*(p-1)/2>n) ok=1;
        if(1LL*((1LL<<k)-1)>n/p) ok=1;
        if(ok==0)
        {
            V=n-1LL*p*(p-1)/2;
            if(V/p<1LL*((1LL<<k)-1)) ok=1;
            else ok=0;
        }
        if(ok==1) dr=mij-1;
        else
        {
            if(1LL*p*(p-1)/2+1LL*((1LL<<k)-1)*p==n) ras=p;
            st=mij+1;
        }
    }
    if(ras!=0) v.push_back(1LL*ras*(1LL<<k));
}
sort(v.begin(),v.end());
for(it=v.begin();it!=v.end();it++)
    printf("%I64d\n",*it);
if(v.empty()) printf("-1\n");
return 0;
}