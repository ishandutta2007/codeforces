#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#define N 1010
#define db double
#define eps (1e-9)
using namespace std;
namespace LW{
    int n,m;
    db num[N][N];
    void pivot(int x,int y)
    {
        db res=num[x][y];
        num[x][y]=1;
        for(int j=0;j<=n;j++) num[x][j]/=res;
        for(int i=0;i<=m;i++)
        if(i!=x && fabs(num[i][y])>eps)
        {
            res=num[i][y],num[i][y]=0;
            for(int j=0;j<=n;j++) num[i][j]-=res*num[x][j];
        }
    }
    int solve()
    {
        while(true)
        {
            int x=0,y=0;
            for(int i=1;i<=m;i++) if(num[i][0]<-eps && (!x || rand()&1)) x=i;
            if(!x) break;
            for(int i=1;i<=n;i++) if(num[x][i]<-eps && (!y || rand()&1)) y=i;
            if(!y) return -1;
            pivot(x,y);
        }
        while(true)
        {
            int x=0,y=0;
            db res=0;
            for(int i=1;i<=n;i++) if(num[0][i]>eps){res=num[0][i],y=i;break;}
            if(!y) break;
            res=1e10;
            for(int i=1;i<=m;i++) if(num[i][y]>eps && num[i][0]/num[i][y]<res-eps) res=num[i][0]/num[i][y],x=i;
            if(!x) return -1;
            pivot(x,y);
        }
        printf("%d\n",(int)(num[0][0]+0.5));
        return 1;
    }
}

int nxt[N<<1],to[N<<1],head[N],cnt;
int p[N<<1],val[N];
int n,k;
void add(int u,int v,int w)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    p[cnt]=w;
    head[u]=cnt;
}
void dfs(int u,int fa,int dis,int rt)
{
	if(dis>k)return;
    LW::num[rt][u]=-1;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v!=fa) dfs(v,u,dis+p[i],rt);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    LW::n=n,LW::m=n+2;
    int s=0;
    for(int i=1;i<=n;i++) scanf("%d",&val[i]),s+=val[i];
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=n;i++) LW::num[0][i]=val[i]-1;
    LW::num[n+1][0]=s;LW::num[n+2][0]=-s;
    for(int i=1;i<=n;i++)
    {
        LW::num[n+1][i]=1;
        LW::num[n+2][i]=-1;
        dfs(i,0,0,i);
        LW::num[i][0]=-1;
    }
	if(LW::solve()==-1) puts("-1");
    return 0;
}