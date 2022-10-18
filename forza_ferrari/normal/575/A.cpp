#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
#define int long long
int n,m,p,mod,f0,f1,s[50005];
struct matrix
{
    int a[2][2];
    matrix()
    {
        a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;
    }
    inline void init()
    {
        a[0][0]=a[1][1]=1;
        a[1][0]=a[0][1]=0;
    }
}a[50005],ans,sum[50005<<2];
vector<int> v;
map<int,vector<pair<int,int> > > mp;
inline matrix operator *(matrix x,matrix y)
{
    matrix res;
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            for(int k=0;k<2;++k)
                res.a[i][j]=(res.a[i][j]+x.a[i][k]*y.a[k][j]%mod)%mod;
    return res;
}
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
inline matrix pw(matrix a,int b)
{
    matrix res;
    res.init();
    while(b)
    {
        if(b&1)
            res=res*a;
        b>>=1;
        a=a*a;
    }
    return res;
}
inline int ls(int k)
{
    return k<<1;
}
inline int rs(int k)
{
    return k<<1|1;
}
inline void push_up(int k)
{
    sum[k]=sum[ls(k)]*sum[rs(k)];
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        sum[k]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update(int node,int l,int r,int k,matrix w)
{
    if(l==r)
    {
        sum[k]=w;
        return;
    }
    int mid=(l+r)>>1;
    if(node<=mid)
        update(node,l,mid,ls(k),w);
    else
        update(node,mid+1,r,rs(k),w);
    push_up(k);
}
inline matrix query(int nl,int nr,int l,int r,int k)
{
    if(nl>nr)
    {
        matrix res;
        res.init();
        return res;
    }
    if(l>=nl&&r<=nr)
        return sum[k];
    int mid=(l+r)>>1;
    if(nr<=mid)
        return query(nl,nr,l,mid,ls(k));
    if(nl>mid)
        return query(nl,nr,mid+1,r,rs(k));
    return query(nl,nr,l,mid,ls(k))*query(nl,nr,mid+1,r,rs(k));
}
signed main()
{
    p=read(),mod=read(),n=read();
    f0=1;
    if(p<2)
    {
        cout<<p%mod<<'\n';
        return 0;
    }
    ++p;
    for(int i=1;i<=n;++i)
    {
        a[i].a[0][1]=1;
        s[i]=read()%mod;
        if(i>1)
        {
            int tmp=(s[i]*f0%mod+s[i-1]*f1%mod)%mod;
            f1=f0;
            f0=tmp;
        }
        if(i+1==p)
        {
            cout<<f0<<'\n';
            return 0;
        }
        if(i==n)
            a[n].a[0][0]=a[1].a[1][0]=s[i];
        else
            a[i].a[0][0]=a[i+1].a[1][0]=s[i];
    }
    build(1,1,n);
    m=read();
    while(m--)
    {
        int x=read()+1,val=read()%mod,cnt=(x-1)/n+1,pos=(x-1)%n+1;
        mp[cnt].emplace_back(pos,val);
        if(pos==n)
            mp[cnt+1].emplace_back(0,val);
    }
    int lst=1;
    for(auto i:mp)
    {
        if(i.first>(p-1)/n+1)
            break;
        v.clear();
        matrix w=pw(sum[1],i.first-lst-1);
        int t0=(f0*w.a[0][0]%mod+f1*w.a[1][0]%mod)%mod,t1=(f0*w.a[0][1]%mod+f1*w.a[1][1]%mod)%mod;
        f0=t0;
        f1=t1;
        lst=i.first;
        for(auto j:i.second)
        {
            if(j.first)
            {
                w=query(j.first,j.first,1,n,1);
                v.emplace_back(j.first);
                w.a[0][0]=j.second;
                update(j.first,1,n,1,w);
            }
            if(j.first+1<=n)
            {
                w=query(j.first+1,j.first+1,1,n,1);
                v.emplace_back(j.first+1);
                w.a[1][0]=j.second;
                update(j.first+1,1,n,1,w);
            }
        }
        if(i.first!=(p-1)/n+1)
            w=sum[1];
        else
            w=query(1,(p-1)%n,1,n,1);
        t0=(f0*w.a[0][0]%mod+f1*w.a[1][0]%mod)%mod,t1=(f0*w.a[0][1]%mod+f1*w.a[1][1]%mod)%mod;
        f0=t0;
        f1=t1;
        if(i.first==(p-1)/n+1)
        {
            cout<<f0<<'\n';
            return 0;
        }
        for(int j:v)
            update(j,1,n,1,a[j]);
    }
    matrix w=pw(sum[1],(p-1)/n-lst);
    int t0=(f0*w.a[0][0]%mod+f1*w.a[1][0]%mod)%mod,t1=(f0*w.a[0][1]%mod+f1*w.a[1][1]%mod)%mod;
    f0=t0;
    f1=t1;
    w=query(1,(p-1)%n,1,n,1);
    t0=(f0*w.a[0][0]%mod+f1*w.a[1][0]%mod)%mod,t1=(f0*w.a[0][1]%mod+f1*w.a[1][1]%mod)%mod;
    f0=t0;
    f1=t1;
    cout<<f0<<'\n';
    return 0;
}