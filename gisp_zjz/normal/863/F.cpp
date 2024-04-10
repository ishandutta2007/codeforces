#include<bits/stdc++.h>

using namespace std;
const int N=1100,INF=0x3f3f3f3f;
const int M=N*N;
int pre[N],d[N],p[N],ans;
int cnt,head[N];
int q[M],l,r,lf[N],rt[N],n,m,ss,tt,res;

struct edge
{
    int u,v,w,c,next;
}e[M];

void init()
{
    memset(head,-1,sizeof(head));
    ans=cnt=0;
}

void add(int u,int v,int c,int w)
{
    e[cnt].u=u,e[cnt].v=v,e[cnt].w=w,e[cnt].c=c;
    e[cnt].next=head[u],head[u]=cnt++;
    e[cnt].u=v,e[cnt].v=u,e[cnt].w=-w,e[cnt].c=0;
    e[cnt].next=head[v],head[v]=cnt++;
}

void updata(int s,int t)
{
    int i,f=INF;
    for(i=t;i!=s;i=e[pre[i]].u)
        f=min(f,e[pre[i]].c);
    for(i=t;i!=s;i=e[pre[i]].u)
    {
       e[pre[i]].c-=f;
       e[pre[i]^1].c+=f;
       ans+=f*e[pre[i]].w;
    }
}

int spfa(int s,int t)
{
    int i,u,v,w;
    memset(p,0,sizeof(p));
    memset(pre,-1,sizeof(pre));
    memset(d,0x3f,sizeof(d));
    l=r=0;
    q[++r]=s,p[s]=1,d[s]=0;
    while(l<r)
    {
        p[u=q[++l]]=0;
        for(i=head[u];i!=-1;i=e[i].next)
        {
            v=e[i].v,w=e[i].w;
            if(e[i].c&&d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                pre[v]=i;
                if(!p[v])
                {
                    p[v]=1;
                    q[++r]=v;
                }
            }
        }
    }
    if(pre[t]==-1)
        return 0;
    return 1;
}

void MiCMaF(int s,int t)
{
    ans=0;
    while(spfa(s,t))
        updata(s,t);
}

int main()
{
    scanf("%d",&n); scanf("%d",&m);
    memset(head,-1,sizeof(head));
    for (int i=1;i<=n;i++) lf[i]=1, rt[i]=n;
    for (int i=0;i<m;i++)
    {
        int o; scanf("%d%d%d%d",&o,&ss,&tt,&res);
        if (o==1) for (int j=ss;j<=tt;j++) lf[j]=max(lf[j],res);
        else for (int j=ss;j<=tt;j++) rt[j]=min(rt[j],res);
    }
    for (int i=1;i<=n;i++) if (lf[i]>rt[i]) {cout << -1 << endl;return 0;}
    for (int i=1;i<=n;i++) add(n*3+1,i,1,0);
    for (int i=1;i<=n;i++)
        for (int j=lf[i];j<=rt[i];j++)
            add(i,j+n,1,0);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            add(i+n,j+n+n,1,j*2-1);
    for (int i=1;i<=n;i++) add(i+n+n,n*3+2,n,0);
    MiCMaF(n*3+1,n*3+2);
    cout << ans << endl;
}