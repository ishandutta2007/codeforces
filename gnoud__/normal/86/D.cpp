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
int t,n,q,pu,pv;
long long a[200001];
long long dd[1000001];
struct so
{
    int u,v,id;
};
so tv[200001];
int getb(int x)
{
    return (x/t)+1-(x%t==0);
}
bool sosanh(so a,so b)
{
    if(getb(a.u)<getb(b.u)) return true;
    if(getb(a.u)==getb(b.u)&&a.v<b.v) return true;
    return false;
}
long long laykq[200001];
int main()
{
    //freopen("DQUERY.inp","r",stdin);
    //freopen("kt.out","w",stdout);
    scanf("%d",&n);
    scanf("%d",&q);
    t=sqrt(n);
    forinc(i,1,n) scanf("%lld",&a[i]);
    forinc(i,1,q) {
        scanf("%d",&tv[i].u);
        scanf("%d",&tv[i].v);
        tv[i].id=i;
    }
    sort(tv+1,tv+q+1,sosanh);
    //forinc(i,1,q)
    //cout<<tv[i].u<<" "<<tv[i].v<<" "<<tv[i].id<<endl;
    //return 0;
    long long kq=0;
    forinc(i,1,q)
    {
        //cout<<tv[i].u<<" "<<tv[i].v<<endl;
        if(i==1||(getb(tv[i].u)!=getb(pu)))
        {
            memset(dd,0,sizeof(dd));
            kq=0;
            forinc(j,tv[i].u,tv[i].v) {
                kq+=(a[j]*((dd[a[j]])*2+1ll));
                dd[a[j]]++;
            }
            //cout<<kq<<endl;
            laykq[tv[i].id]=kq;
            pu=tv[i].u;pv=tv[i].v;
            continue;
        }
            forinc(j,pv+1,tv[i].v) {
                kq+=(a[j]*((dd[a[j]])*2+1ll));
                dd[a[j]]++;
            }
            if(pu==tv[i].u) kq=kq;
            else if(pu>tv[i].u)
            {
                forinc(j,tv[i].u,pu-1)
                {
                    kq+=(a[j]*((dd[a[j]])*2+1ll));
                    dd[a[j]]++;
                }
            }
            else
            {
                forinc(j,pu,tv[i].u-1)
                {
                     kq-=(a[j]*((dd[a[j]])*2-1ll));
                     dd[a[j]]--;
                }
            }
            laykq[tv[i].id]=kq;
            pu=tv[i].u;pv=tv[i].v;
            continue;
    }
    forinc(i,1,q) printf("%lld\n",laykq[i]);
}