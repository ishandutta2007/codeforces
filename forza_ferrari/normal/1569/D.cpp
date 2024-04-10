#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct element
{
    int x,y,l,r;
}node[300001];
int t,n,m,p,x[200001],y[200001],px[200001],py[200001];
long long ans;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline bool cmp1(element x,element y)
{
    return x.l^y.l? x.l<y.l:x.r<y.r;
}
inline bool cmp2(element x,element y)
{
    return x.r^y.r? x.r<y.r:x.l<y.l;
}
int main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read(),p=read();
        ans=0;
        for(register int i=1;i<=n;++i)
            x[i]=read(),px[i]=0;
        for(register int i=1;i<=m;++i)
            y[i]=read(),py[i]=0;
        for(register int i=1;i<=p;++i)
        {
            node[i].x=read(),node[i].y=read();
            node[i].l=lower_bound(x+1,x+n+1,node[i].x)-x;
            node[i].r=lower_bound(y+1,y+m+1,node[i].y)-y;
        }
        sort(node+1,node+p+1,cmp1);
        int tmp=0;
        for(register int i=1;i<=p;++i)
        {
            if((node[i].l^node[i-1].l)||(node[i].r^node[i-1].r))
            {
                px[node[i-1].l]+=tmp;
                tmp=0;
            }
            if(node[i].x==x[node[i].l])
                continue;
            ++tmp;
            ans+=px[node[i].l];
        }
        sort(node+1,node+p+1,cmp2);
        tmp=0;
        for(register int i=1;i<=p;++i)
        {
            if((node[i].l^node[i-1].l)||(node[i].r^node[i-1].r))
            {
                py[node[i-1].r]+=tmp;
                tmp=0;
            }
            if(node[i].y==y[node[i].r])
                continue;
            ++tmp;
            ans+=py[node[i].r];
        }
        printf("%lld\n",ans);
    }
    return 0;
}