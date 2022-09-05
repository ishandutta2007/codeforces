#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int dp[4],v1,v2,x1,y1,x2,y2,nr,i,j,n,m,INF,cost,a[800009],b[800009],c[800009],d[800009],v[109];
char Mat[3][200009];
void reup(int &x)
{
    if(x>INF) x=INF;
}
void cod(int p,int &x,int &y)
{
    if(p<=n) x=1,y=p;
    else x=2,y=p-n;
}
void swap(int &x,int &y)
{
    int aux=x;
    x=y;
    y=aux;
}
void build(int nod,int st,int dr)
{
    if(st==dr)
    {
        if(Mat[1][st]==Mat[2][st])
        {
            if(Mat[1][st]=='X') a[nod]=b[nod]=c[nod]=d[nod]=INF;
            else a[nod]=d[nod]=0,b[nod]=c[nod]=1;
        }
        else
        {
            if(Mat[1][st]=='X') d[nod]=0,a[nod]=b[nod]=c[nod]=INF;
            else a[nod]=0,b[nod]=c[nod]=d[nod]=INF;
        }
        return ;
    }
    int mij=(st+dr)>>1,l=(nod<<1),r=(nod<<1)+1;
    build(l,st,mij);
    build(r,mij+1,dr);
    a[nod]=min(a[l]+a[r],b[l]+c[r])+1;
    b[nod]=min(a[l]+b[r],b[l]+d[r])+1;
    c[nod]=min(d[l]+c[r],c[l]+a[r])+1;
    d[nod]=min(d[l]+d[r],c[l]+b[r])+1;
    reup(a[nod]),reup(b[nod]),reup(c[nod]),reup(d[nod]);
}
void Q(int nod,int st,int dr,int x,int y)
{
    if(x<=st&&dr<=y)
    {
        v[++nr]=nod;
        return ;
    }
    int mij=(st+dr)>>1;
    if(x<=mij) Q(nod<<1,st,mij,x,y);
    if(y>mij) Q((nod<<1)+1,mij+1,dr,x,y);
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
INF=5*n;
scanf("%d\n",&m);
for(i=1;i<=2;i++)
    gets(Mat[i]+1);
build(1,1,n);
while(m)
{
    m--;
    scanf("%d %d",&i,&j);
    cod(i,x1,y1);
    cod(j,x2,y2);
    if(y1==y2)
    {
        if(x1==x2) printf("0\n");
        else printf("1\n");
        continue;
    }
    if(y1>y2) swap(x1,x2),swap(y1,y2);
    cost=nr=0;
    Q(1,1,n,y1,y2);
    dp[x1]=0;
    dp[3-x1]=INF;
    for(i=1;i<=nr;i++)
    {
        v1=min(dp[1]+a[v[i]],dp[2]+c[v[i]]);
        v2=min(dp[1]+b[v[i]],dp[2]+d[v[i]]);
        dp[1]=v1;
        dp[2]=v2;
    }
    cost=dp[x2];
    cost+=nr-1;
    if(cost>=INF) printf("-1\n");
    else printf("%d\n",cost);
}
return 0;
}