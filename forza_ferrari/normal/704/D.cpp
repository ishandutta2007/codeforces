#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct edge
{
    int nxt,to,weight;
}e[200001<<4];
int ans,n,m,a,b,tot=1,h[200005<<1],dep[200005<<1],cur[200005<<1],d[200005<<1],nodex[100001],nodey[100001],minx[100001],miny[100001],cntx,cnty,ss,tt,s,t,num[100001],p[100001][2],tx[100001],ty[100001];
bool vis[200005<<1],tag[100001];
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
inline int add(int x,int y,int w)
{
    e[++tot]={h[x],y,w};
    return h[x]=tot;
}
inline void add(int x,int y,int l,int r)
{
    d[x]-=l;
    d[y]+=l;
    add(x,y,r-l);
    add(y,x,0);
}
inline bool bfs()
{
    for(int i=0;i<=t;++i)
    {
        vis[i]=0;
        cur[i]=h[i];
        dep[i]=0x3f3f3f3f;
    }
    queue<int> q;
    q.emplace(s);
    dep[s]=0;
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        vis[k]=0;
        for(int i=h[k];i;i=e[i].nxt)
            if(e[i].weight&&dep[e[i].to]>dep[k]+1)
            {
                dep[e[i].to]=dep[k]+1;
                if(!vis[e[i].to])
                {
                    vis[e[i].to]=1;
                    q.emplace(e[i].to);
                }
            }
    }
    return dep[0]^dep[t];
}
inline int dfs(int k,int f)
{
    if(k==t)
    {
        ans+=f;
        return f;
    }
    int r=0,used=0;
    for(int i=cur[k];i;i=e[i].nxt)
    {
        cur[k]=i;
        if(e[i].weight&&dep[e[i].to]==dep[k]+1)
            if((r=dfs(e[i].to,min(e[i].weight,f-used))))
            {
                e[i].weight-=r;
                e[i^1].weight+=r;
                used+=r;
                if(f==used)
                    break;
            }
    }
    return used;
}
inline void dinic()
{
    while(bfs())
        dfs(s,1<<30);
}
int main()
{
    n=read(),m=read(),a=read(),b=read();
    for(int i=1;i<=n;++i)
        nodex[i]=p[i][0]=read(),nodey[i]=p[i][1]=read();
    sort(nodex+1,nodex+n+1);
    cntx=unique(nodex+1,nodex+n+1)-nodex-1;
    sort(nodey+1,nodey+n+1);
    cnty=unique(nodey+1,nodey+n+1)-nodey-1;
    ss=cntx+cnty+1;
    tt=ss+1;
    s=tt+1;
    t=s+1;
    for(int i=1;i<=n;++i)
    {
        p[i][0]=lower_bound(nodex+1,nodex+cntx+1,p[i][0])-nodex;
        p[i][1]=lower_bound(nodey+1,nodey+cnty+1,p[i][1])-nodey;
        ++tx[p[i][0]];
        ++ty[p[i][1]];
        num[i]=add(p[i][0],p[i][1]+cntx,1);
        add(p[i][1]+cntx,p[i][0],0);
    }
    for(int i=1;i<=cntx;++i)
        minx[i]=tx[i];
    for(int i=1;i<=cnty;++i)
        miny[i]=ty[i];
    for(int i=1;i<=m;++i)
    {
        int opt=read(),x=read(),w=read();
        if(opt==1)
        {
            int pos=lower_bound(nodex+1,nodex+cntx+1,x)-nodex;
            if(nodex[pos]==x)
                minx[pos]=min(minx[pos],w);
        }
        else
        {
            int pos=lower_bound(nodey+1,nodey+cnty+1,x)-nodey;
            if(nodey[pos]==x)
                miny[pos]=min(miny[pos],w);
        }
    }
    for(int i=1;i<=cntx;++i)
    {
        int l=(tx[i]-minx[i]+1)>>1,r=(tx[i]+minx[i])>>1;
        if(l<=r)
            add(ss,i,l,r);
        else
        {
            cout<<"-1\n";
            return 0;
        }
    }
    for(int i=1;i<=cnty;++i)
    {
        int l=(ty[i]-miny[i]+1)>>1,r=(ty[i]+miny[i])>>1;
        if(l<=r)
            add(i+cntx,tt,l,r);
        else
        {
            cout<<"-1\n";
            return 0;
        }
    }
    add(tt,ss,1<<30);
    add(ss,tt,0);
    int sum=0;
    for(int i=1;i<=tt;++i)
        if(d[i]>0)
        {
            sum+=d[i];
            add(s,i,d[i]);
            add(i,s,0);
        }
        else if(d[i]<0)
        {
            add(i,t,-d[i]);
            add(t,i,0);
        }
    dinic();
    if(ans^sum)
    {
        cout<<"-1\n";
        return 0;
    }
    ans=0;
    s=ss;
    t=tt;
    dinic();
    cout<<1ll*ans*min(a,b)+1ll*(n-ans)*max(a,b)<<'\n';
    for(int i=1;i<=n;++i)
        if(a<=b)
            tag[i]=e[num[i]].weight? 1:0;
        else
            tag[i]=e[num[i]].weight? 0:1;
    for(int i=1;i<=n;++i)
        cout<<(tag[i]? 'b':'r');
    cout<<'\n';
    return 0;
}