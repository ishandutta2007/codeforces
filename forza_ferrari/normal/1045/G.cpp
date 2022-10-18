#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int n,m,p[100001],cnt,ans[100001],sum;
struct element
{
    int x,r,q,L,R;
}a[100001];
inline bool cmp1(element x,element y)
{
    return x.r>y.r;
}
inline bool cmp2(element x,element y)
{
    return x.q<y.q;
}
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x,int k)
{
    for(;x<=cnt;x+=lowbit(x))
        ans[x]+=k;
}
inline int query(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=ans[x];
    return res;
}
void cdq(int l,int r)
{
    if(l==r)
        return;
    int mid=(l+r)>>1;
    cdq(l,mid);
    cdq(mid+1,r);
    int i=l,j=l-1;
    for(register int k=mid+1;k<=r;++k)
    {
        while(i<=mid&&a[k].q-a[i].q>m)
        {
            update(a[i].x,-1);
            ++i;
        }
        while(j<mid&&a[j+1].q-a[k].q<=m)
        {
            ++j;
            update(a[j].x,1);
        }
        sum+=query(a[k].R)-query(a[k].L-1);
    }
    for(register int k=i;k<=j;++k)
        update(a[k].x,-1);
    sort(a+l,a+r+1,cmp2);
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(register int i=1;i<=n;++i)
    {
        scanf("%lld%lld%lld",&a[i].x,&a[i].r,&a[i].q);
        p[i]=a[i].x;
    }
    sort(p+1,p+n+1);
    cnt=unique(p+1,p+n+1)-p-1;
    for(register int i=1;i<=n;++i)
    {
        a[i].L=lower_bound(p+1,p+cnt+1,a[i].x-a[i].r)-p;
        a[i].R=upper_bound(p+1,p+cnt+1,a[i].x+a[i].r)-p-1;
        a[i].x=lower_bound(p+1,p+cnt+1,a[i].x)-p;
    }
    sort(a+1,a+n+1,cmp1);
    cdq(1,n);
    printf("%lld\n",sum);
    return 0;
}