#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

#define N 50005
#define M 505

const int Mo=(int)1e9+7; 

using namespace std;
int i,j,n,f[N][M],vis[N],k,ans,x,y;
vector<int>v[N];
void dfs(int x)
{
	  vis[x]=1;  int i,j;
	  f[x][0]++;
	  for (i=0;i<v[x].size();++i)
	    if(!vis[v[x][i]])
	    {
	    	  int p=v[x][i];
	    	  dfs(p);
	    	  for (j=0;j<k;++j) ans+=f[x][j]*f[p][k-j-1];
	    	  for (j=0;j<k;++j) f[x][j+1]+=f[p][j];
	    }
}
int main()
{
 scanf("%d%d",&n,&k);
  for (i=1;i<n;++i)
  {
  	  scanf("%d%d",&x,&y);
  	  v[x].push_back(y); v[y].push_back(x);
  }
  dfs(1);
  printf("%d\n",ans);
}