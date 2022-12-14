#include<iostream>
#include<cstring>
#define MN 300000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,head[MN+5],d[MN+5],cnt=0,Ans[MN+5],ans=0,St=0,tot=0;
bool vis[MN+5];struct edge{int to,next,w;}e[MN*2+5];

inline void ins(int f,int t,int w)
{
    e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
    e[++cnt]=(edge){f,head[t],w};head[t]=cnt;
}

int dfs(int x)
{
    vis[x]=1;int res=d[x];
    for(int i=head[x];i;i=e[i].next)
        if(!vis[e[i].to]&&dfs(e[i].to)) Ans[++ans]=e[i].w,res^=1;
    if(d[x]==-1) return 0; return res;
}

int main()
{
    n=read();m=read();
    for(int i=1;i<=n;++i) (d[i]=read())==-1?(St=i):(tot^=d[i]);
    if(!St&&tot) return 0*puts("-1");
    for(int i=1;i<=m;++i) ins(read(),read(),i);
    dfs(St?St:1);printf("%d\n",ans);
    for(int i=1;i<=ans;++i) printf("%d\n",Ans[i]);
    return 0;
}