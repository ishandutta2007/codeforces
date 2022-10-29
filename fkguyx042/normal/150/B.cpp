#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

#define N 2005 

using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,n,p,k,sum,vis[N],Q[N];
vector<int>v[N];
using namespace std;
int power(int x,int y)
{
  int sum=1;
   for (;y;y>>=1)
   {
   	    if (y&1) sum=1ll*sum*x%Mo;
   	    x=1ll*x*x%Mo;
   }
   return sum;	  
}
void add(int x,int y)
{
	 v[x].push_back(y); 
	 v[y].push_back(x);
}
void bfs(int x)
{
	 vis[x]=1; Q[Q[0]=1]=x;
	 sum++;
	 int l,i;
	 for (l=1;l<=Q[0];++l)
	 {
	 	  p=Q[l];
	 	  for (i=0;i<v[p].size();++i) if (!vis[v[p][i]])
	 	  {
	 	  	vis[v[p][i]]=1;
	 	  	Q[++Q[0]]=v[p][i];
	 	  }
     }
}
int main()
{
	 scanf("%d%d%d",&n,&m,&k);
	 for (i=1;i<=n-k+1;++i)
	   for (j=0;j<k/2;++j)
	   add(i+j,i+k-1-j);
	for (i=1;i<=n;++i)
	  if (!vis[i]) bfs(i);
	printf("%d\n",power(m,sum));
}