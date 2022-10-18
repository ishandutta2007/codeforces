#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,block,pos[100001],p[100001][2],a[100001],b[100001],tag[100001],cnt[100001];
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
inline void rebuild(int id)
{
    for(int i=p[id][0];i<=p[id][1];++i)
    {
        a[i]=max(1,a[i]-tag[id]);
        if(a[i]<p[id][0])
            b[i]=a[i];
        else
            b[i]=b[a[i]];
    }
    tag[id]=0;
}
inline void update(int l,int r,int val)
{
    if(pos[l]==pos[r])
    {
        for(int i=l;i<=r;++i)
            a[i]=max(1,a[i]-val);
        rebuild(pos[l]);
        return;
    }
    for(int i=l;i<=p[pos[l]][1];++i)
        a[i]=max(1,a[i]-val);
    rebuild(pos[l]);
    for(int i=p[pos[r]][0];i<=r;++i)
        a[i]=max(1,a[i]-val);
    rebuild(pos[r]);
    for(int i=pos[l]+1;i<pos[r];++i)
    {
        tag[i]=min(n,tag[i]+val);
        if(++cnt[i]<=block)
            rebuild(i);
    }
}
inline int query(int x,int y)
{
    while(pos[x]!=pos[y]||b[x]!=b[y])
        if(pos[x]^pos[y])
        {
            if(pos[x]<pos[y])
                x^=y^=x^=y;
            x=max(1,b[x]-tag[pos[x]]);
        }
        else
            x=max(1,b[x]-tag[pos[x]]),y=max(1,b[y]-tag[pos[y]]);
    while(x^y)
    {
        if(x<y)
            x^=y^=x^=y;
        x=max(1,a[x]-tag[pos[x]]);
    }
    return x;
}
int main()
{
    n=read(),m=read();
    block=sqrt(n);
    pos[1]=p[1][0]=p[1][1]=1;
    for(int i=2;i<=n;++i)
    {
        a[i]=read();
        pos[i]=(i-1)/block+1;
        if(!p[pos[i]][0])
            p[pos[i]][0]=i;
        p[pos[i]][1]=i;
    }
    for(int i=1;(i-1)*block+1<=n;++i)
        rebuild(i);
    while(m--)
    {
        int opt=read(),x=read(),y=read();
        if(opt==1)
            update(x,y,read());
        if(opt==2)
            cout<<query(x,y)<<'\n';
    }
    return 0;
}