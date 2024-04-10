#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,ans,maxlen,cur;
vector<pair<int,int> > v[100001];
struct tree
{
    pair<int,int> maxn[100001<<2];
    int root,tag[100001<<2],t[100001],w[100001],fa[100001][21],val[100001],dep[100001],cnt,dfn[100001],id[100001],s[100001],ans[100001];
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
        maxn[k]=max(maxn[ls(k)],maxn[rs(k)]);
    }
    inline void push_down(int k)
    {
        maxn[ls(k)].first+=tag[k];
        maxn[rs(k)].first+=tag[k];
        tag[ls(k)]+=tag[k];
        tag[rs(k)]+=tag[k];
        tag[k]=0;
    }
    inline void build(int k,int l,int r)
    {
        if(l==r)
        {
            maxn[k]={dep[id[l]],id[l]};
            return;
        }
        int mid=(l+r)>>1;
        build(ls(k),l,mid);
        build(rs(k),mid+1,r);
        push_up(k);
    }
    inline void update(int nl,int nr,int l,int r,int k,int p)
    {
        if(l>=nl&&r<=nr)
        {
            maxn[k].first+=p;
            tag[k]+=p;
            return;
        }
        push_down(k);
        int mid=(l+r)>>1;
        if(nl<=mid)
            update(nl,nr,l,mid,ls(k),p);
        if(nr>mid)
            update(nl,nr,mid+1,r,rs(k),p);
        push_up(k);
    }
    inline void dfs(int k,int f,int deep,int len)
    {
        val[k]=dep[k]=deep;
        w[k]=len;
        s[k]=1;
        dfn[k]=++cnt;
        id[cnt]=k;
        fa[k][0]=f;
        for(int i=1;i<=20;++i)
            fa[k][i]=fa[fa[k][i-1]][i-1];
        for(auto i:v[k])
        {
            if(i.first==f)
                continue;
            dfs(i.first,k,deep+i.second,i.second);
            s[k]+=s[i.first];
            val[k]=max(val[k],val[i.first]);
        }
    }
    inline void solve()
    {
        dfs(root,0,0,0);
        build(1,1,n);
        for(int i=1;i<=n;++i)
        {
            int k=maxn[1].second;
            ans[i]=ans[i-1]+maxn[1].first;
            while(k&&!t[k])
            {
                t[k]=i;
                update(dfn[k],dfn[k]+s[k]-1,1,n,1,-w[k]);
                k=fa[k][0];
            }
        }
    }
    inline int query(int x,int y)
    {
        if(t[x]<=y)
            return ans[min(n,y)];
        int a=x,b=x;
        for(int i=20;~i;--i)
        {
            if(t[fa[a][i]]>=y)
                a=fa[a][i];
            if(t[fa[b][i]]>y)
                b=fa[b][i];
        }
        a=fa[a][0];
        b=fa[b][0];
        return max(ans[y-1]+val[x]-dep[a],ans[y]+val[x]-val[b]);
    }
}T1,T2;
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
inline void dfs(int k,int f,int deep)
{
    if(deep>maxlen)
    {
        maxlen=deep;
        cur=k;
    }
    for(auto i:v[k])
    {
        if(i.first==f)
            continue;
        dfs(i.first,k,deep+i.second);
    }
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read(),w=read();
        v[x].emplace_back(y,w);
        v[y].emplace_back(x,w);
    }
    dfs(1,0,0);
    T1.root=cur;
    maxlen=cur=0;
    dfs(T1.root,0,0);
    T2.root=cur;
    T1.solve();
    T2.solve();
    while(m--)
    {
        int x=(read()+ans-1)%n+1,y=(read()+ans-1)%n+1;
        cout<<(ans=max(T1.query(x,(y<<1)-1),T2.query(x,(y<<1)-1)))<<'\n';
    }
    return 0;
}