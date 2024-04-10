#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 200005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,x,y,sx,sy,f[N][2],vis[N];
vector<int>v[N];
void add(int x,int y) { v[x].push_back(y); }
void dfs(int x)
{
   f[x][1]=0; f[x][0]=1;
   int Max=0,M1=0,M2=0; int i; vis[x]=1;
   for (i=0;i<(int)v[x].size();++i)
    {
    	  int p=v[x][i];
    	  if (vis[p]) continue;
    	  dfs(p);
    	  f[x][1]+=f[p][0]; Max=min(Max,f[p][1]-f[p][0]);
    	  f[x][0]+=f[p][0]; 
    	  int v=f[p][1]-f[p][0];
    	  if (v<M1) swap(M1,M2),M1=v;
    	  else if (v<M2) M2=v;
    }
    f[x][1]+=Max;
    f[x][0]=f[x][0]+M1+M2;
}
int main()
{
	  scanf("%d%d%d",&n,&sx,&sy);
	  for (i=1;i<n;++i) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	  if (sx>=sy)
	  {
	  	  int sum=0;
	  	   for (i=1;i<=n;++i) if (v[i].size()>1) ++sum;
	  	   if (sum<=1) printf("%I64d\n",1ll*(n-2)*sy+sx);
	  	   else printf("%I64d\n",1ll*(n-1)*sy);
	  }
	  else 
	  {
	  	dfs(1);
	  	printf("%I64d\n",1ll*(f[1][0]-1)*sy+1ll*(n-f[1][0])*sx);
	  }
}