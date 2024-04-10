#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int Mo=(int)1e9+7;
vector<int>v[100005];
void add(int x,int y) { v[x].push_back(y); }
int i,n,x,y,f[100005][2],A,B,g[2][2];
int inc(int x,int y)
{ 
  x+=y;  while (x>=Mo) x-=Mo; 
    while (x<0) x+=Mo;
    return x;
}
void dfs(int x)
{ 
    int i;
    for (i=0;i<v[x].size();++i) dfs(v[x][i]);
    f[x][1]=1; f[x][0]=0;     memset(g,0,sizeof(g)); g[0][0]=g[0][1]=1;
    if (v[x].size()==0) return;
    for (i=0;i<v[x].size();++i)
       {
       	     int u=v[x][i];
       	     A=inc(1ll*f[x][1]*f[u][1]%Mo,1ll*f[x][0]*f[u][0]%Mo);
       	     B=inc(1ll*f[x][1]*f[u][0]%Mo,1ll*f[x][0]*f[u][1]%Mo);
       	     f[x][0]=inc(f[x][0],A);f[x][1]=inc(f[x][1],B);
       }
    f[x][0]=inc(f[x][0],f[x][0]); f[x][1]=inc(f[x][1],f[x][1]);
    for (i=0;i<v[x].size();++i)
     {  
         int u=v[x][i];
         A=inc(g[0][0],1LL*f[u][0]*g[1][0]%Mo);
         B=inc(g[1][0],1ll*f[u][0]*g[0][0]%Mo);
         g[0][0]=A; g[1][0]=B;
         A=inc(g[0][1],1ll*f[u][1]*g[1][1]%Mo);
         B=inc(g[1][1],1ll*f[u][1]*g[0][1]%Mo);
         g[0][1]=A; g[1][1]=B;
    } 
    f[x][1]=inc(f[x][1],inc(-g[0][0],-g[1][0]));
    f[x][0]=inc(f[x][0],-g[1][1]);
}
int main()
{ 
 scanf("%d",&n);
 for (i=2;i<=n;++i) scanf("%d",&x),add(x,i);
 dfs(1);
 printf("%d\n",(f[1][0]+f[1][1])%Mo);
}