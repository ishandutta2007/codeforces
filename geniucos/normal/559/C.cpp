#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int s1,x11,x1,y11,y1,mod,phi,i,j,n,fac[1000009],inv[1000009],x[10009],y[10009],d[10009];
vector < pair < int , int > > v;
vector < pair < int , int > >::iterator it;
int ridic(int baza,int exp)
{
    int i,p=1;
    for(i=0;(1<<i)<=exp;i++)
    {
        if(exp&(1<<i)) p=(1LL * p*baza)%mod;
        baza=(1LL * baza*baza)%mod;
    }
    return p;
}
int comb(int n1,int k1)
{
    if (n1 < 0 || k1 < 0) return 0;
    if (k1 > n1) return 0;
    if (k1 == n1 || k1 == 0) return 1;
    int p=fac[n1];
    p=(1LL * p*inv[k1])%mod;
    p=(1LL * p*inv[n1-k1])%mod;
    return p;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d %d %d",&x11, &y11, &n);
mod=1e9+7;
fac[0]=1;
for(i=1;i<=300000;i++)
    fac[i]=(1LL * fac[i-1]*i)%mod;
for (int i=0; i<=300000; i++)
    inv[i] = ridic (fac[i], mod - 2);
///////o sa determin phi-ul lui mod
/////////////////
v.push_back(make_pair(x11,y11));
for(i=1;i<=n;i++)
{
    scanf("%d",&x1);
    scanf("%d",&y1);
    v.push_back(make_pair(x1,y1));
}
sort(v.begin(),v.end());
i=0;
for(it=v.begin();it!=v.end();it++)
{
    i++;
    x[i]=it->first - 1;
    y[i]=it->second - 1;
}
n++;
for(i=1;i<=n;i++)
{
    s1=0;
    for(j=1;j<i;j++)
        if(y[j]<=y[i])
            s1=((long long)s1+1LL * d[j]*comb(x[i]+y[i]-x[j]-y[j],x[i]-x[j]))%mod;
    d[i]=((long long)comb(x[i]+y[i],x[i])-s1+mod)%mod;
}
for(i=1;i<=n;i++)
    if(x[i]==x11 - 1&&y[i]==y11 - 1)
    {
        printf("%d\n",d[i]);
        return 0;
    }
return 0;
}