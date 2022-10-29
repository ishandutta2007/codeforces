#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>

#define N 10005
#define M 1000005
using namespace std;
map<int,int>mp;
const int lim=(int)1e9;
int i,j,m,n,p,k,vis[N],l,K,ans,sum[N];
int Q[M];
long long pow[N];
void dfs(long long x)
{
	  if  (x>lim) return;
	  Q[++Q[0]]=x;
	  dfs(x*10+4); dfs(x*10+7);
}
void cal(int x)
{
	  for (i=1;i<=Q[0];++i) if (Q[i]<=x) ++ans;
}
int ask(int x)
{
	  int sum=0;
	  for (i=1;i<=x;++i) if (vis[i]) ++sum;
	  return sum;
}
int main()
{
	 dfs(4); dfs(7);
	 scanf("%d%d",&n,&K); --K;
	 pow[0]=1;
	 for (i=1;i<=Q[0];++i) mp[Q[i]]=1;
	 for (i=1;i<=n;++i)
	 {
	 	      pow[i]=1ll*pow[i-1]*i;
	 	      if (pow[i]>=K+1) break;
	 }
	 if (i>n) { printf("-1\n"); return 0; } 
	 l=i;
	 cal(n-l);
	 for (i=1;i<=l;++i) vis[i]=1;
	 for (j=1;j<l;++j)
	 {
	 	  int id=0;
	    for (k=1;k<=l;++k)
	        if (vis[k])
	      	    if (1ll*ask(k-1)*pow[l-j]<=K) id=k;
	        K-=ask(id-1)*pow[l-j];
	        sum[j]=id;
	        vis[id]=0;
	 }
	   for (i=1;i<=l;++i)
	     if (vis[i]) break;
	     sum[l]=i;
	   for (i=1;i<=l;++i) if (mp[n-l+i]&&mp[n-l+sum[i]]) ++ans;
	   printf("%d\n",ans);
}