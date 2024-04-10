#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,tot,root,ls[100001<<1],rs[100001<<1];
long long a[100001][11],val[11],sum[100001<<1][11],tl[11],tr[11];
vector<int> tag[100001<<1][11],vl[11],vr[11];
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
inline void push_up(int k)
{
    for(int i=0;i<10;++i)
        sum[k][i]=sum[ls[k]][i]+sum[rs[k]][i];
}
inline void push_down(int k)
{
    bool flag=0;
    for(int i=0;i<10;++i)
        if(tag[k][i].size()!=1||tag[k][i][0]!=i)
        {
            flag=1;
            break;
        }
    if(flag)
    {
        for(int i=0;i<10;++i)
        {
            tl[i]=tr[i]=0;
            vl[i].clear();
            vr[i].clear();
        }
        for(int i=0;i<10;++i)
        {
            for(auto j:tag[k][i])
            {
                for(auto p:tag[ls[k]][j])
                    vl[i].emplace_back(p);
                for(auto p:tag[rs[k]][j])
                    vr[i].emplace_back(p);
                tl[i]+=sum[ls[k]][j];
                tr[i]+=sum[rs[k]][j];
            }
        }
        for(int i=0;i<10;++i)
        {
            sum[ls[k]][i]=tl[i];
            sum[rs[k]][i]=tr[i];
            tag[ls[k]][i]=vl[i];
            tag[rs[k]][i]=vr[i];
            tag[k][i].clear();
            tag[k][i].emplace_back(i);
        }
    }
}
inline void build(int &k,int l,int r)
{
    k=++tot;
    for(int i=0;i<10;++i)
        tag[k][i].emplace_back(i);
    if(l==r)
    {
        for(int i=0;i<10;++i)
            sum[k][i]=a[l][i];
        return;
    }
    int mid=(l+r)>>1;
    build(ls[k],l,mid);
    build(rs[k],mid+1,r);
    push_up(k);
}
inline void update(int nl,int nr,int l,int r,int k,int x,int y)
{
    if(l>=nl&&r<=nr)
    {
        for(auto i:tag[k][x])
            tag[k][y].emplace_back(i);
        tag[k][x].clear();
        sum[k][y]+=sum[k][x];
        sum[k][x]=0;
        return;
    }
    push_down(k);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls[k],x,y);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs[k],x,y);
    push_up(k);
}
inline long long query(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
    {
        long long res=0;
        for(int i=0;i<10;++i)
            res+=1ll*i*sum[k][i];
        return res;
    }
    push_down(k);
    int mid=(l+r)>>1;
    long long res=0;
    if(nl<=mid)
        res+=query(nl,nr,l,mid,ls[k]);
    if(nr>mid)
        res+=query(nl,nr,mid+1,r,rs[k]);
    return res;
}
int main()
{
    n=read(),m=read();
    val[0]=1;
    for(int i=1;i<=10;++i)
        val[i]=10ll*val[i-1];
    for(int i=1;i<=n;++i)
    {
        int x=read();
        for(int j=0;j<=10;++j)
        {
            if(!x)
                break;
            int w=x%10;
            x/=10;
            a[i][w]+=val[j];
        }
    }
    build(root,1,n);
    while(m--)
    {
        int opt=read(),l=read(),r=read();
        if(opt==1)
        {
            int x=read(),y=read();
            if(x^y)
                update(l,r,1,n,root,x,y);
        }
        if(opt==2)
            cout<<query(l,r,1,n,root)<<'\n';
        /*for(int i=1;i<=n;++i)
            cout<<query(i,i,1,n,1)<<" ";
        cout<<'\n';*/
    }
    return 0;
}