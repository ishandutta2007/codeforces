#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
struct element
{
    char opt;
    int x,y;
}q[500001];
struct querys
{
    int pos,tag,id;
    querys(int pos_,int tag_,int id_):
        pos(pos_),tag(tag_),id(id_){}
};
vector<querys> a[500001];
int n,m,cnt,tot,val[1000001],bin[1000001],dfn[1000001],s[1000001],sum[1000001],t[1000001<<2],tag[1000001<<2],ans[500001];
vector<int> v[1000001];
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
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x,int val)
{
    for(;x<=tot;x+=lowbit(x))
        sum[x]+=val;
}
inline int query(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[x];
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
    t[k]=max(t[ls(k)],t[rs(k)]);
}
inline void push_down(int k)
{
    if(tag[k])
    {
        t[ls(k)]=t[rs(k)]=tag[ls(k)]=tag[rs(k)]=tag[k];
        tag[k]=0;
    }
}
inline void update(int nl,int nr,int l,int r,int k,int p)
{
    if(l>=nl&&r<=nr)
    {
        t[k]=tag[k]=p;
        return;
    }
    int mid=(l+r)>>1;
    push_down(k);
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
inline int query(int node,int l,int r,int k)
{
    if(l==r)
        return t[k];
    push_down(k);
    int mid=(l+r)>>1;
    if(node<=mid)
        return query(node,l,mid,ls(k));
    return query(node,mid+1,r,rs(k));
}
inline int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline void dfs(int k)
{
    dfn[k]=++cnt;
    s[k]=1;
    for(int i:v[k])
    {
        dfs(i);
        s[k]+=s[i];
    }
}
signed main()
{
    tot=n=read(),m=read();
    for(int i=1;i<=m;++i)
    {
        ans[i]=-1;
        q[i].opt=getchar();
        while(q[i].opt!='U'&&q[i].opt!='M'&&q[i].opt!='A'&&q[i].opt!='Z'&&q[i].opt!='Q')
            q[i].opt=getchar();
        q[i].x=read();
        if(q[i].opt=='U'||q[i].opt=='M')
            q[i].y=read();
        if(q[i].opt=='M')
        {
            int x=anc(q[i].x),y=anc(q[i].y);
            bin[x]=bin[y]=++tot;
            v[tot].emplace_back(x);
            v[tot].emplace_back(y);
        }
        if(q[i].opt=='Q')
            ans[i]=0;
    }
    for(int i=1;i<=tot;++i)
        if(!dfn[anc(i)])
            dfs(anc(i));
    for(int i=1;i<=tot;++i)
        bin[i]=0;
    int tmp=n;
    for(int i=1;i<=m;++i)
    {
        if(q[i].opt=='M')
        {
            int x=anc(q[i].x),y=anc(q[i].y);
            bin[x]=bin[y]=++tmp;
        }
        if(q[i].opt=='Z')
        {
            int x=anc(q[i].x);
            update(dfn[x],dfn[x]+s[x]-1,1,tot,1,i);
        }
        if(q[i].opt=='Q')
        {
            a[i].emplace_back(q[i].x,1,i);
            a[query(dfn[q[i].x],1,tot,1)].emplace_back(q[i].x,-1,i);
        }
    }
    for(int i=1;i<=tot;++i)
    {
        dfn[i]=bin[i]=s[i]=0;
        v[i].clear();
    }
    tot=n;
    cnt=0;
    for(int i=1;i<=m;++i)
        if(q[i].opt=='U')
        {
            int x=anc(q[i].x),y=anc(q[i].y);
            bin[x]=bin[y]=++tot;
            v[tot].emplace_back(x);
            v[tot].emplace_back(y);
        }
    for(int i=1;i<=tot;++i)
        if(!dfn[anc(i)])
            dfs(anc(i));
    tmp=n;
    for(int i=1;i<=tot;++i)
        bin[i]=0;
    for(int i=1;i<=n;++i)
        val[i]=1;
    for(int i=1;i<=m;++i)
    {
        if(q[i].opt=='U')
        {
            int x=anc(q[i].x),y=anc(q[i].y);
            bin[x]=bin[y]=++tmp;
            val[tmp]=val[x]+val[y];
        }
        if(q[i].opt=='A')
        {
            int x=anc(q[i].x);
            update(dfn[x],val[x]);
            update(dfn[x]+s[x],-val[x]);
        }
        for(auto j:a[i])
            ans[j.id]+=j.tag*query(dfn[j.pos]);
    }
    for(int i=1;i<=m;++i)
        if(ans[i]>=0)
            cout<<ans[i]<<'\n';
    return 0;
}