#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
struct edge
{
    int nxt,to,weight;
}e[200001<<1];
int n,tot,h[200001],dep[200001],fa[200001],s[200001],son[200001],num[200001],top[200001],w[200001],dfn[200001],cnt,sum[200001<<2][2],val[200001<<2][2],tag[200001<<2];
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
inline void add(int x,int y,int w)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
    e[tot].weight=w;
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
    val[k][0]=val[ls(k)][0]+val[rs(k)][0];
    val[k][1]=val[ls(k)][1]+val[rs(k)][1];
    sum[k][0]=sum[ls(k)][0]+sum[rs(k)][0];
    sum[k][1]=sum[ls(k)][1]+sum[rs(k)][1];
}
inline void push_down(int k)
{
    if(tag[k])
    {
        swap(val[ls(k)][0],val[ls(k)][1]);
        swap(val[rs(k)][0],val[rs(k)][1]);
        swap(sum[ls(k)][0],sum[ls(k)][1]);
        swap(sum[rs(k)][0],sum[rs(k)][1]);
        tag[ls(k)]^=1;
        tag[rs(k)]^=1;
        tag[k]=0;
    }
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        val[k][1]=1;
        sum[k][1]=w[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update(int nl,int nr,int l,int r,int k)
{
    if(nl>nr)
        return;
    if(l>=nl&&r<=nr)
    {
        swap(val[k][0],val[k][1]);
        swap(sum[k][0],sum[k][1]);
        tag[k]^=1;
        return;
    }
    push_down(k);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k));
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k));
    push_up(k);
}
inline int query(int node,int l,int r,int k)
{
    if(l==r)
        return val[k][0]? sum[k][0]:0;
    push_down(k);
    int mid=(l+r)>>1;
    if(node<=mid)
        return query(node,l,mid,ls(k));
    return query(node,mid+1,r,rs(k));
}
inline void dfs1(int k,int f,int deep)
{
    dep[k]=deep;
    fa[k]=f;
    s[k]=1;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs1(e[i].to,k,deep+1);
        s[k]+=s[e[i].to];
        if(s[e[i].to]>s[son[k]])
        {
            son[k]=e[i].to;
            num[k]=e[i].weight;
        }
    }
}
inline void dfs2(int k,int t,int v)
{
    top[k]=t;
    dfn[k]=++cnt;
    w[cnt]=v;
    if(!son[k])
        return;
    dfs2(son[k],t,num[k]);
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==fa[k]||e[i].to==son[k])
            continue;
        dfs2(e[i].to,e[i].to,e[i].weight);
    }
}
inline void up(int x)
{
    while(top[x]^1)
    {
        update(dfn[top[x]],dfn[x],1,n,1);
        x=fa[top[x]];
    }
    update(2,dfn[x],1,n,1);
}
signed main()
{
    cin>>n;
    for(int i=1;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        add(x,y,i);
        add(y,x,i);
    }
    dfs1(1,0,1);
    dfs2(1,1,0);
    build(1,1,n);
    int res=1;
    while(1)
    {
        int opt;
        cin>>opt;
        if(opt==3)
            return 0;
        if(opt==1)
        {
            int k;
            cin>>k;
            if(!k)
                return 0;
            up(k);
            if(val[1][0]<<1==++res)
                cout<<sum[1][0]<<endl;
            else
                cout<<0<<endl;
        }
        if(opt==2)
        {
            if(val[1][0]<<1==res)
            {
                vector<int> ans;
                for(int i=2,w;i<=n;++i)
                    if((w=query(i,1,n,1)))
                        ans.emplace_back(w);
                sort(ans.begin(),ans.end());
                cout<<ans.size()<<" ";
                for(auto i:ans)
                    cout<<i<<" ";
                cout<<endl;
            }
            else
                cout<<0<<endl;
        }
    }
    return 0;
}