#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstring>
#define N 12
using namespace std;
//0:knight 1:bishop 2:rook
int kx[8]={1,-1,2,-2,1,-1,2,-2},
    ky[8]={2,2,1,1,-2,-2,-1,-1};
struct dist{
    int d,v;//d:do times , v:change times
    dist(int D=0,int V=0):d(D),v(V){}
    bool operator <(const dist a)const{return d==a.d?v<a.v:d<a.d;}
    dist operator +(dist a){return dist(d+a.d,v+a.v);}
};
dist f[N][N][3][N][N][3];//f[x][y][p][x'][y'][p'] at (x,y) as p , to (x',y') as p'
struct node{
    int x,y,k;
    node(int X=0,int Y=0,int K=0):x(X),y(Y),k(K){}
};
queue<node>q;
int n;
void dfs(node s,dist g[][N][3])
{
    auto push=[&](node a,dist d)
    {
        if(a.x<=0 || a.x>n || a.y<=0 || a.y>n) return;
        if(d<g[a.x][a.y][a.k]) g[a.x][a.y][a.k]=d,q.push(a);
    };
    auto add=[&](dist a){return dist(a.d+1,a.v);};
    auto chg=[&](dist a){return dist(a.d+1,a.v+1);};
    g[s.x][s.y][s.k]=dist(0,0);
    q.push(s);
    while(!q.empty())
    {
        node u=q.front();dist d=g[u.x][u.y][u.k];
        q.pop();
        if(u.k==0)
        {
            for(int i=0;i<8;i++)
            push(node(u.x+kx[i],u.y+ky[i],0),add(d));
        }
        if(u.k==1)
        {
            for(int i=1;i<=n;i++) push(node(u.x+i,u.y+i,1),add(d));
            for(int i=1;i<=n;i++) push(node(u.x-i,u.y+i,1),add(d));
            for(int i=1;i<=n;i++) push(node(u.x+i,u.y-i,1),add(d));
            for(int i=1;i<=n;i++) push(node(u.x-i,u.y-i,1),add(d));
        }
        if(u.k==2)
        {
            for(int i=1;i<=n;i++) push(node(u.x,i,2),add(d));
            for(int i=1;i<=n;i++) push(node(i,u.y,2),add(d));
        }
        push(node(u.x,u.y,(u.k+1)%3),chg(d));
        push(node(u.x,u.y,(u.k+2)%3),chg(d));
    }
}
dist h[N*N][3];
int x[N*N],y[N*N];
int main()
{
    memset(f,0x3f,sizeof(f));
    memset(h,0x3f,sizeof(h));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<=2;k++)
                dfs(node(i,j,k),f[i][j][k]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int a;
            scanf("%d",&a);
            x[a]=i,y[a]=j;
        }
    for(int k=0;k<=2;k++)
    h[1][k]=dist(0,0);
    for(int i=2;i<=n*n;i++)
        for(int j=0;j<=2;j++)
            for(int k=0;k<=2;k++)
            h[i][k]=min(h[i][k],h[i-1][j]+f[x[i-1]][y[i-1]][j][x[i]][y[i]][k]);
    dist ans=h[n*n][0];
    for(int k=1;k<=2;k++) ans=min(ans,h[n*n][k]);
    printf("%d %d\n",ans.d,ans.v);
    return 0;
}