#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define N 100010
#define inf 1000000000
using namespace std;
int nxt[N<<1],to[N<<1],w[N<<1],head[N],cnt=1;
int cur[N],all;
void add(int u,int v,int w1)
{
    nxt[++cnt]=head[u];to[cnt]=v;w[cnt]=w1;head[u]=cnt;
    nxt[++cnt]=head[v];to[cnt]=u;w[cnt]=0;head[v]=cnt;
}
int dep[N];
queue<int>q;
bool bfs(int s,int t)
{
    for(int i=1;i<=all;i++) dep[i]=inf,cur[i]=head[i];
    dep[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=nxt[i])
        if(w[i]){
            int v=to[i];
            if(dep[v]>=inf)
            dep[v]=dep[u]+1,q.push(v);
        }
    }
    return dep[t]<inf;
}
int dfs(int u,int t,int fl)
{
    if(u==t || !fl) return fl;
    int res=0;
    for(int &i=cur[u];i;i=nxt[i])
    {
        int v=to[i],f;
        if(dep[v]==dep[u]+1 && (f=dfs(v,t,min(fl,w[i]))))
        {
            w[i]-=f;
            w[i^1]+=f;
            fl-=f;
            res+=f;
            if(!fl) break;
        }
    }
    return res;
}
int dinic(int s,int t)
{
    int ans=0;
    while(bfs(s,t)) ans+=dfs(s,t,inf);
    return ans;
}
void reset(){for(int i=1;i<=all;i++) head[i]=0;cnt=1;}
int p[N],c[N],l[N];
bool he[N];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    he[1]=true;
    for(int i=2;i<=N-10;i++)
    if(!he[i])
        for(int j=i*2;j<=N-10;j+=i) he[j]=true;
    for(int i=1;i<=n;i++) scanf("%d%d%d",&p[i],&c[i],&l[i]);
    int s=n+2,t=s+1;all=t;
    for(int r=0;r<=n;r++)
    {
        int ans=0;
        reset();
        for(int i=1;i<=n;i++)
        if(l[i]<=r && c[i]&1)
            for(int j=1;j<=n;j++)
            if(l[j]<=r && !(c[j]&1) && !he[c[i]+c[j]]) add(c[i]==1?n+1:i,j,inf);
        int a1=0;
        for(int i=1;i<=n;i++)
        if(l[i]<=r)
        {
            if(c[i]==1) a1=max(a1,p[i]);
            else if(c[i]&1) add(s,i,p[i]);
            else add(i,t,p[i]);
        }
        if(a1) add(s,n+1,a1);
        for(int i=1;i<=n;i++)
        if(l[i]<=r && c[i]!=1) ans+=p[i];
        ans+=a1;
        if(ans-dinic(s,t)>=k){printf("%d\n",r);return 0;}
    }
    puts("-1");
    return 0;
}