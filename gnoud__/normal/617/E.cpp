#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define pii pair<int,int>
#define MAX(a,b,c) max(max(a,b),c)
#define fi first
#define se second
#define two(n) (1<<n)
#define getbit(x,i) ((x>>i)&1)
#define batbit(x,i) (x|(1ll<<i))
#define offbit(x,i) (x&~(1<<i))
using namespace std;
long long t,n,q,pu,pv,k;
long long a[200001];
long long dd[2000001];
struct so
{
    long long u,v,id;
};
so tv[200001];
long long getb(long long x)
{
    return (x/t)+1-(x%t==0);
}
bool sosanh(so a,so b)
{
    if(getb(a.u)<getb(b.u)) return true;
    if(getb(a.u)==getb(b.u)&&a.v<b.v) return true;
    return false;
}
long long kq=0;
void them(long long u,long long v)
{
    forinc(j,u,v) {
        kq+=dd[a[j]^k];
        dd[a[j]]++;
    }
}
void bot(long long u,long long v)
{
    forinc(j,u,v) {
        dd[a[j]]--;
        kq-=dd[a[j]^k];
    }
}
long long laykq[200001];
int main()
{
    //freopen("DQUERY.inp","r",stdin);
    //freopen("kt.out","w",stdout)
    scanf("%d",&n);
    scanf("%d",&q);
    scanf("%d",&k);
    t=300;
    forinc(i,1,n) {
       long long x;
       cin>>x;
       a[i]=a[i-1]^x;
    }
    forinc(i,1,q) {
        scanf("%lld",&tv[i].u);
        scanf("%lld",&tv[i].v);
        tv[i].id=i;
    }
    sort(tv+1,tv+q+1,sosanh);
    forinc(i,1,q)
    {
        long long U=tv[i].u-1,V=tv[i].v;
        if(i==1||(getb(tv[i].u)!=getb(pu)))
        {
            memset(dd,0,sizeof(dd));
            kq=0;
            them(U,V);
            laykq[tv[i].id]=kq;
            pu=U;pv=V;
            continue;
        }
        them(pv+1,V);
        if(pu>U) them(U,pu-1);
        else if(pu<U) bot(pu,U-1);
        laykq[tv[i].id]=kq;
        pu=U;pv=V;
    }
    forinc(i,1,q) printf("%lld\n",laykq[i]);
}