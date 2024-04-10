#include<bits/stdc++.h>
#define MN 200000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int cnt,head[MN+5],n,size[MN+5],mx[MN+5],X,Y,Z,ans;
struct edge{int to,next;}e[MN*2+5];
struct res{int x,y,yy;}Ans[MN*2+5];
inline void ins(int f,int t)
{
    e[++cnt]=(edge){t,head[f]};head[f]=cnt;
    e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}
void dfs(int x,int fa)
{
    size[x]=1;
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=fa) dfs(e[i].to,x),size[x]+=size[e[i].to],mx[x]=max(mx[x],size[e[i].to]);
    mx[x]=max(mx[x],n-size[x]);
}
void dfs2(int x,int fa,int dep)
{
    if(dep>1)
    {
        Ans[++ans]=(res){X,Y,x};Y=x;
        Ans[++ans]=(res){x,fa,Z};
    }
    for(int i=head[x];i;i=e[i].next) if(e[i].to!=fa) dfs2(e[i].to,x,dep+1);
}
int main()
{
    n=read();
    for(int i=1;i<n;++i) ins(read(),read());
    dfs(1,0);
    for(int i=1;i<=n;++i) if(mx[i]<=n/2)
        for(int j=head[i];j;j=e[j].next) if(mx[e[j].to]>n/2)
            X=i,Y=Z=e[j].to,dfs2(e[j].to,i,0),Ans[++ans]=(res){X,Y,e[j].to};
    printf("%d\n",ans);
    for(int i=1;i<=ans;++i) printf("%d %d %d\n",Ans[i].x,Ans[i].y,Ans[i].yy);
    return 0;
}