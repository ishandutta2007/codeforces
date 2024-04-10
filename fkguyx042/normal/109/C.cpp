#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

#define N 100005

using namespace std;
int cnt[N],vis[N],i,j,m,n,p,k,x,y,z;
long long ans;
vector<int>v[N];
bool check(int x)
{
 for (;x;x/=10)
   if (x%10!=4&&x%10!=7) return 1;
 return 0;
}
void dfs(int x)
{
	  int i;
	  vis[x]=1;
	  cnt[cnt[0]]++;
	  for (i=0;i<(int)v[x].size();++i)
	    if (!vis[v[x][i]]) dfs(v[x][i]);
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<n;++i)
	{
		  scanf("%d%d%d",&x,&y,&z);
		  if (check(z)) v[x].push_back(y),v[y].push_back(x);
	}
	for (i=1;i<=n;++i)
	   if (!vis[i])
	   {
	   	 ++cnt[0];
	   	 dfs(i);
	   }
	for (i=1;i<=cnt[0];++i) ans+=1ll*cnt[i]*(n-cnt[i])*(n-cnt[i]-1);
	printf("%I64d\n",ans);
}