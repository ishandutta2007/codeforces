#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int M,n,m;
int w[100005];
long long sum[500005];
int mx[500005],l[500005],r[500005];


void build(int x,int L,int R)
{
    l[x]=L;r[x]=R;
    int mid=(L+R)>>1;
    if(L==R)
    {
        mx[x]=sum[x]=w[L];
        return;
    }
    build((x<<1),L,mid);
    build((x<<1)+1,mid+1,R);
    mx[x]=max(mx[x<<1],mx[(x<<1)|1]);
    sum[x]=sum[x<<1]+sum[(x<<1)|1];
}


void update(int x,int L,int R,int val)
{
    if(L<=l[x]&&r[x]<=R)
    {
        mx[x]=sum[x]=val;
        return;
    }
    int mid=(l[x]+r[x])>>1;
    if(L<=mid)update((x<<1),L,R,val);
    if(mid<R)update((x<<1)+1,L,R,val);
    mx[x]=max(mx[x<<1],mx[(x<<1)+1]);
    sum[x]=sum[x<<1]+sum[(x<<1)+1];
}


void change(int x,int L,int R,int mo)
{
    if(mx[x]<mo)return;
    if(l[x]==r[x])
    {
        mx[x]%=mo;
        sum[x]%=mo;
        return;
    }
    int mid=(l[x]+r[x])>>1;
    if(L<=mid)change(x<<1,L,R,mo);
    if(R>mid)change((x<<1)+1,L,R,mo);
    mx[x]=max(mx[x<<1],mx[(x<<1)+1]);
    sum[x]=sum[x<<1]+sum[(x<<1)+1];
}


long long query(int x,int L,int R)
{
    if(L<=l[x]&&r[x]<=R)return sum[x];
    int mid=(l[x]+r[x])>>1;
    long long ret=0;
    if(L<=mid)ret+=query(x<<1,L,R);
    if(R>mid)ret+=query((x<<1)+1,L,R);
    return ret;
}


int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int kind;
        scanf("%d",&kind);
        if(kind==1)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%I64d\n",query(1,l,r));
        }else
        if(kind==3)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            update(1,l,l,r);
        }else
        {
            int l,r,mo;
            scanf("%d%d%d",&l,&r,&mo);
            change(1,l,r,mo);
        }
    }
    return 0;
}