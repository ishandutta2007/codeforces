#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define fi first
#define se second
#define mk make_pair

#define N 200005
#define seed 23333
#define Mo 998244353

using namespace std;
vector<int>v[N];
int i,j,m,n,p,k,big[N],sum[N],fa[N],size[N],vis[N],ans,x,y,a[N];
void dfs(int x)
{
	  int i,Max=0;
	  big[x]=vis[x];
	  for (i=0;i<(int)v[x].size();++i) 
	  {
	  	  int p=v[x][i];
	  	  if(fa[x]==p) continue;
	  	  fa[p]=x;
          dfs(p);
          size[x]+=size[p];
          if (big[p]) sum[x]+=sum[p];
          else big[x]=0,Max=max(Max,sum[p]);
      }
      sum[x]+=Max+1;
      if(!vis[x]) sum[x]=0;
      size[x]++;
}
void Dfs(int x,int isbig,int sumx)
{
	 int i,Sum=0,Max=0,wos=0,W=0;  int M[2]={0},id[2]={0};
	 if (isbig) Sum+=sumx,W+=sumx; else Max=max(Max,sumx),M[0]=sumx,wos++;
	 for (i=0;i<(int)v[x].size();++i)
	 {
	 	  int p=v[x][i];
	 	  if (fa[x]==p) continue;
	 	  if (big[p]) W+=sum[p],Sum+=sum[p];
          else 
		  {
		     ++wos,Max=max(Max,sum[p]);
		     if (sum[p]>M[0]) swap(M[0],M[1]),swap(id[0],id[1]),M[0]=sum[p],id[0]=p;
		     else if(sum[p]>M[1]) M[1]=sum[p],id[1]=p;
		  }
	 }
	 if (vis[x]) ans=max(ans,Max+Sum+1);
	 for (i=0;i<(int)v[x].size();++i)
	 {
	 	   int p=v[x][i];
	 	   if (fa[x]==p) continue;
	 	   if(!vis[x]) Dfs(p,0,0);
	 	   else if (!wos||(wos==1&&id[0]==p)) Dfs(p,1,n-size[p]);
	 	   else if (big[p]) Dfs(p,0,W+M[0]+1-sum[p]);
	 	   else if (id[0]==p) Dfs(p,0,W+M[1]+1);
	 	   else Dfs(p,0,W+M[0]+1);
	 }
}
inline int check(int x)
{
	  int i;
	  ans=0;
	  for (i=1;i<=n;++i) vis[i]=(a[i]>=x);
		  memset(fa,0,sizeof(fa));
	  memset(sum,0,sizeof(sum));
	  memset(big,0,sizeof(big));
	  memset(size,0,sizeof(size));
	  dfs(1);
	  Dfs(1,1,0);
	  return ans;
}
int main()
{
	 scanf("%d%d",&n,&k);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]);
	 for (i=1;i<n;++i)
	 {
	 	 scanf("%d%d",&x,&y);
	 	 v[x].push_back(y); v[y].push_back(x);
	 }
	 int l=0,r=1000005,mid=0;
	 while ((l+r)>>1!=mid)
	 {
	    mid=(l+r)>>1;
		if (check(mid)>=k) l=mid;
		else r=mid;
	}
	printf("%d\n",l);
}