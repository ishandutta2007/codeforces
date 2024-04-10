#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
struct edge
{
    int nxt,to,weight;
}e[100001<<1];
int n,tot=1,h[501],s,t,a[201],cur[501],dep[501],ans,cnt;
bool vis[501];
vector<int> v[101],l,r;
inline void add(int x,int y,int w)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
    e[tot].weight=w;
}
inline bool bfs()
{
    for(register int i=0;i<=t;++i)
    {
        vis[i]=0;
        cur[i]=h[i];
        dep[i]=0x3f3f3f3f;
    }
    queue<int> q;
    q.push(s);
    dep[s]=0;
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        vis[k]=0;
        for(register int i=h[k];i;i=e[i].nxt)
            if(e[i].weight&&dep[e[i].to]>dep[k]+1)
            {
                dep[e[i].to]=dep[k]+1;
                if(!vis[e[i].to])
                {
                    vis[e[i].to]=1;
                    q.push(e[i].to);
                }
            }
    }
    return dep[t]^dep[0];
}
int dfs(int k,int f)
{
    if(k==t)
    {
        ans+=f;
        return f;
    }
    int r=0,used=0;
    for(register int i=cur[k];i;i=e[i].nxt)
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
inline bool prime(int p)
{
    for(register int i=2;i*i<=p;++i)
        if(p%i==0)
            return 0;
    return 1;
}
void solve(int k)
{
    v[cnt].push_back(k);
    vis[k]=1;
    for(register int i=h[k];i;i=e[i].nxt)
        if(!vis[e[i].to])
        {
            if(!e[i^(a[k]&1)].weight)
                continue;
            solve(e[i].to);
            return;
        }
}
int main()
{
    scanf("%d",&n);
    s=n+1,t=n+2;
    for(register int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        if(a[i]&1)
        {
            add(s,i,2);
            add(i,s,0);
            l.push_back(i);
        }
        else
        {
            add(i,t,2);
            add(t,i,0);
            r.push_back(i);
        }
    }
    for(register int i=0;i<(int)(l.size());++i)
        for(register int j=0;j<(int)(r.size());++j)
            if(prime(a[l[i]]+a[r[j]]))
            {
                add(l[i],r[j],1);
                add(r[j],l[i],0);
            }
    dinic();
    if(ans^n)
    {
        puts("Impossible");
        return 0;
    }
    for(register int i=0;i<=t;++i)
        vis[i]=0;
    vis[s]=vis[t]=1;
    for(register int i=0;i<(int)(l.size());++i)
        if(!vis[l[i]])
        {
            ++cnt;
            solve(l[i]);
        }
    printf("%d\n",cnt);
    for(register int i=1;i<=cnt;++i)
    {
        printf("%d ",(int)(v[i].size()));
        for(register int j=0;j<(int)(v[i].size());++j)
            printf("%d ",v[i][j]);
        puts("");
    }
    return 0;
}