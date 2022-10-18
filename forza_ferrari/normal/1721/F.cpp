//oh
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<set>
using namespace std;
struct edge
{
    int nxt,to,weight,val;
}e[1000001<<3];
int n1,n2,m,q,tot=1,dep[400005],cur[400005],h[400005],s,t,node[400005],sum[400005];
long long ans;
bool vis[400005],tag[400005][2],ban[400005];
set<int> s1,s2,edge;
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
inline int add(int x,int y,int w,int val)
{
    e[++tot]={h[x],y,w,val};
    return h[x]=tot;
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
inline void solve1(int k)
{
    if(ban[k]||tag[k][0])
        return;
    tag[k][0]=1;
    if(k<=n1)
        s1.erase(k);
    for(int i=h[k];i;i=e[i].nxt)
        if(e[i].weight)
            solve1(e[i].to);
}
inline void solve2(int k)
{
    if(ban[k]||tag[k][1])
        return;
    tag[k][1]=1;
    if(k>n1&&k<=n1+n2)
        s2.erase(k-n1);
    for(int i=h[k];i;i=e[i].nxt)
        if(!e[i].weight)
            solve2(e[i].to);
}
int main()
{
    n1=read(),n2=read(),m=read(),q=read();
    s=n1+n2+1;
    t=s+1;
    for(int i=1;i<=n1;++i)
    {
        add(s,i,1,0);
        add(i,s,0,0);
        s1.emplace(i);
    }
    for(int i=1;i<=n2;++i)
    {
        add(i+n1,t,1,0);
        add(t,i+n1,0,0);
        s2.emplace(i);
    }
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read();
        add(x,y+n1,1,i);
        add(y+n1,x,0,i);
    }
    dinic();
    int cnt=ans;
    ans=0;
    solve1(s);
    solve2(t);
    for(int i=h[s];i;i=e[i].nxt)
        if(!e[i].weight)
            for(int j=h[e[i].to];j;j=e[j].nxt)
                if(!e[j].weight&&e[j].to>n1&&e[j].to<=n1+n2)
                {
                    ans+=e[j].val;
                    node[e[i].to]=e[j].to;
                    node[e[j].to]=e[i].to;
                    sum[e[i].to]=sum[e[j].to]=e[j].val;
                    edge.emplace(e[j].val);
                    break;
                }
    while(q--)
    {
        /*for(int i:s1)
            cout<<i<<" ";
        cout<<'\n';
        for(int i:s2)
            cout<<i<<" ";
        cout<<'\n';*/
        int opt=read();
        if(opt==1)
        {
            --cnt;
            cout<<"1\n";
            if(!s1.empty())
            {
                ans-=sum[*s1.begin()];
                cout<<*s1.begin()<<'\n';
                edge.erase(sum[*s1.begin()]);
                int p=node[*s1.begin()];
                tag[*s1.begin()][0]=1;
                ban[*s1.begin()]=1;
                s1.erase(s1.begin());
                solve2(p);
            }
            else
            {
                ans-=sum[*s2.begin()+n1];
                cout<<-(*s2.begin())<<'\n';
                edge.erase(sum[*s2.begin()+n1]);
                int p=node[*s2.begin()+n1];
                tag[*s2.begin()+n1][1]=1;
                ban[*s2.begin()+n1]=1;
                s2.erase(s2.begin());
                solve1(p);
            }
            cout<<ans<<'\n';
        }
        else
        {
            cout<<cnt<<'\n';
            for(int i:edge)
                cout<<i<<" ";
            cout<<'\n';
        }
        cout.flush();
    }
    return 0;
}