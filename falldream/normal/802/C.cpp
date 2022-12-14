#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define S 0
#define MN 80
#define T 81
#define INF 2000000000
using namespace std;
inline int read()
{
    int x = 0 , f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}

int d[MN+5],n,k,head[MN+5],cnt=1,a[MN+5],c[MN+5],ans=0,pi=0,la[MN+5];
struct edge{int to,next,w,c;}e[MN*MN];
bool inq[MN+5],mark[MN+5];
deque<int> q;

inline void ins(int f,int t,int w,int c)
{
    e[++cnt]=(edge){t,head[f],w,c}; head[f]=cnt;
    e[++cnt]=(edge){f,head[t],0,-c};head[t]=cnt;
}

bool modlabel()
{
    for(int i=S;i<=T;++i) d[i]=INF;
    d[T]=0;inq[T]=1;q.push_front(T);
    while(!q.empty())
    {
        int x=q.front();q.pop_front();
        for(int i=head[x];i;i=e[i].next)
            if(e[i^1].w&&e[i^1].c+d[x]<d[e[i].to])
            {
                d[e[i].to]=d[x]+e[i^1].c;
                if(!inq[e[i].to])
                {
                    inq[e[i].to]=1;
                    if(d[e[i].to]<d[q.size()?q.front():0]) q.push_front(e[i].to);
                    else q.push_back(e[i].to);
                }
            }
        inq[x]=0;
    }
    for(int i=S;i<=T;++i)
        for(int j=head[i];j;j=e[j].next)
            e[j].c+=d[e[j].to]-d[i];
    return pi+=d[S],d[S]<INF;
}

int dfs(int x,int f)
{
    if(x==T) return ans+=pi*f,f;
    int used=0;mark[x]=1;
    for(int i=head[x];i;i=e[i].next)
        if(e[i].w&&!e[i].c&&!mark[e[i].to])
        {
            int w=dfs(e[i].to,min(f-used,e[i].w));
            used+=w;e[i].w-=w;e[i^1].w+=w;
            if(used==f) return used;
        }
    return used;
}

int main()
{
    n=read();k=read()-1;
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i) c[i]=read();
    for(int i=1;i<=n;++i) ans+=c[a[i]];
    ins(S,1,k,0);ins(n,T,k,0);
    for(int i=1;i<n;++i) ins(i,i+1,INF,0);
    for(int i=1;i<=n;++i)
    {
        if(la[a[i]])
        {
            if(la[a[i]]==i-1) ans-=c[a[i]];
            else ins(la[a[i]]+1,i,1,-c[a[i]]);
        }
        la[a[i]]=i;
    }
    while(modlabel())
        do memset(mark,0,sizeof(mark));
        while(dfs(S,INF));
    cout<<ans;
    return 0;
}