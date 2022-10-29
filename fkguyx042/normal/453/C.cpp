#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

#define N 100005

using namespace std;
int i,j,m,n,p,k,x,a[N],y,str,vis[N];
vector<int>v[N],ans;
void In(int x)
{
	 a[x]^=1; ans.push_back(x);
}
void dfs(int x,int f)
{
	  In(x); vis[x]=1; 
	  int i;
	  for (i=0;i<(int)v[x].size();++i)
	    {
	    	   int p=v[x][i];
	    	   if (vis[p]) continue;
	    	   dfs(p,x);
	    	   In(x);
	    }
      if (a[x]&&f!=-1) In(f),In(x);
}
int main()
{
	 scanf("%d%d",&n,&m);
	 for (i=1;i<=m;++i)
	 {
	 	  scanf("%d%d",&x,&y);
	 	  v[x].push_back(y);
	 	  v[y].push_back(x);
	 }
	 for (i=1;i<=n;++i) 
	 {
	   scanf("%d",&a[i]);
	   if (a[i]) str=i;
     }
     if (!str) { puts("0"); return 0; }
	 dfs(str,-1);
	 if (a[str]) ans.pop_back(),a[str]^=1;
	 for (i=1;i<=n;++i)
	   if (a[i])
	   {
	   	 puts("-1");
	   	 return 0;
	   }
	 printf("%d\n",ans.size());
	 for (i=0;i<(int)ans.size();++i) printf("%d\n",ans[i]);
}