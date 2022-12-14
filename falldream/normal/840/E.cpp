#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 50000
#define N 256
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,f[MN+5][N],a[MN+5],head[MN+5],cnt=0,dep[MN+5],fa[9][MN+5],F[2][MN+5][N];
struct edge{int to,next;}e[MN*2+5];
inline void R(int&x,int y){y>x?x=y:0;}
inline void ins(int f,int t)
{
    e[++cnt]=(edge){t,head[f]};head[f]=cnt;
    e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}

void Pre(int x,int fat)
{
    fa[0][x]=fat;for(int j=0;j<N;++j) R(F[0][x][j],(a[x]>>8)^j);
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=fat) dep[e[i].to]=dep[x]+1,Pre(e[i].to,x);
    if(dep[x]>=N)
        for(int j=x,k=0;k<N;++k,j=fa[0][j]) R(f[x][a[j]>>8],(a[j]&255)^k);
}

int main()
{
    n=read();m=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<n;++i) ins(read(),read());
    Pre(dep[1]=1,0);
    for(int i=1;i<=8;++i,memset(F[i&1],0,sizeof(F[0])))
        for(int j=1;j<=n;++j)if(dep[j]>=1<<i)
        {
            fa[i][j]=fa[i-1][fa[i-1][j]];
            for(int k=0;k<N;++k) F[i&1][j][k]=max(F[(i&1)^1][j][k],F[(i&1)^1][fa[i-1][j]][k]);
        }
    for(int i=1;i<=m;++i)
    {
        int u=read(),v=read(),ans1=0,ans2=0,t=0,ans,x,T=0;
        for(x=v;dep[x]-256>=dep[u];x=fa[8][x],++t) R(ans1,F[0][x][t]);
        for(x=v,T=0;dep[x]-256>=dep[u];x=fa[8][x],++T) R(ans2,f[x][T^ans1]);
        ans=(ans1<<8)+ans2;
        for(t<<=8;dep[x]>=dep[u];x=fa[0][x],++t) R(ans,a[x]^t);
        printf("%d\n",ans);
    }
    return 0;
}