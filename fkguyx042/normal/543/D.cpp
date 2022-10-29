#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int Mo=(int)1e9+7;
vector<int>v[200005];
long long i,j,m,n,p,k,F[200005][2],G[200005][2],ans,fa[200005],sum[200005],Sum[200005];
int Sumx[200005],next[200005],last[200005];
int power(int x,int y)
{ 
     int sum=1;
     for (;y;y>>=1)
     {
          if  (y&1) sum=1ll*x*sum%Mo;
          x=1ll*x*x%Mo;
     }
     return sum;
} 
void dfs(int x)
{
      int i,j;
      if (!v[x].size()) F[x][0]=1;
      else 
   { 
       F[x][0]=F[x][1]=1;
      for (i=0;i<v[x].size();++i)
      {
           int p=v[x][i]; dfs(p);
           F[x][0]=1ll*F[x][0]*F[p][0]%Mo;
           F[x][1]=1ll*F[x][1]*(F[p][1]+2*F[p][0]%Mo)%Mo;
      }
      F[x][1]=(F[x][1]-F[x][0]+Mo)%Mo;
    }
}
void Dfs(int x)
{
     int i,Last=0;
     for (i=0;i<v[x].size();++i)
     {
           int p=v[x][i];
           sum[p]=1ll*sum[Last]*F[p][0];
           Sum[p]=1ll*Sum[Last]*(2*F[p][0]%Mo+F[p][1])%Mo;
           last[p]=Last;Last=p;
     }
     Last=0;
     for (i=v[x].size()-1;i>=0;--i)
     {
          int p=v[x][i];
         Sumx[p]=1ll*Sumx[Last]*(2*F[p][0]%Mo+F[p][1])%Mo;
         next[p]=Last; Last=p;
     }
     for (i=0;i<v[x].size();++i)
    {
        int p=v[x][i];
        int A=sum[last[p]];
        int B=1ll*Sum[last[p]]*Sumx[next[p]]%Mo;
        B=(B-A+Mo)%Mo;
        G[p][0]=1ll*A*G[x][0]%Mo;
        G[p][1]=1ll*B*G[x][1]%Mo;
        (G[p][1]+=1ll*A*G[x][1]%Mo)%=Mo;
        (G[p][1]+=1ll*B*G[x][0]%Mo)%=Mo;
        (G[p][1]+=1ll*A*G[x][0]%Mo)%=Mo;
        Dfs(p);
    }
}
int main()
{
     scanf("%I64d",&n);
     sum[0]=1;Sum[0]=1; Sumx[0]=1;
     for (i=2;i<=n;++i) scanf("%I64d",&fa[i]),v[fa[i]].push_back(i);
     dfs(1);
     G[1][0]=1;
     Dfs(1);    
     for (i=1;i<=n;++i) printf("%d ", 1ll*(G[i][0]+G[i][1])*(F[i][0]+F[i][1])%Mo);
}