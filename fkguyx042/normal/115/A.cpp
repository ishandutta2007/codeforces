#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

#define N 2005

using namespace std;
vector<int>v[N];
int n,i,fa[N],deep[N],Q[N],p,j,ans;
void add(int x,int y)
{
	  v[x].push_back(y);
}
void bfs(int x)
{
	  Q[Q[0]=1]=x;
	  int l,i;
	  for (l=1;l<=Q[0];++l)
	  {
	  	   p=Q[l];
	  	   for(j=0;j<v[p].size();++j)
	  	      Q[++Q[0]]=v[p][j],deep[Q[Q[0]]]=deep[p]+1;
	  }
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i)
	{
		  scanf("%d",&fa[i]);
		  if (fa[i]!=-1) add(fa[i],i);
	}
	for (i=1;i<=n;++i)
	  if (fa[i]==-1)
	  {
	  	    bfs(i);
	  	    ans=max(ans,deep[Q[Q[0]]]);
	  }
	  printf("%d\n",ans+1);
}