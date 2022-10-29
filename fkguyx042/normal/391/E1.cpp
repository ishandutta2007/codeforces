#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

#define N 100005

using namespace std;
int i,j,m,n,p,k,n1,n2,n3,x,y,vis[N];
long long ans;
struct Node{
	  int Size[N],size;
	  vector<int>v[N];
	  long long ans,f[N*3];
	  void add(int x,int y)
	  {
	  	  v[x].push_back(y);
	  	  v[y].push_back(x);
	  }
	  void dfs(int x)
	  {
	  	 Size[x]=0; f[x]=0;
	  	 vis[x]=1;
	  	 int i,p;
	  	 for (i=0;i<v[x].size();++i)
	  	   if (!vis[p=v[x][i]])
	  	   {
	  	   	    dfs(p);
	  	   	    Size[x]+=Size[p];
	  	   	    f[x]+=f[p]+Size[p];
	  	   }
	  	   Size[x]++;
      }
      void Dfs(int x,int fa)
      {
      	 vis[x]=1;
      	  if (fa) f[x]=f[fa]-Size[x]+(size-Size[x]);
      	  int i,p;
      	  for (i=0;i<v[x].size();++i)
      	    if (!vis[p=v[x][i]])
      	    {
      	    	  ans+=(f[p]+Size[p])*(Size[x]-Size[p]);
      	    	  Dfs(p,x);
      	    }
      }
	  void getsum()
	  {
	  	 memset(vis,0,sizeof(vis));
	  	 dfs(1);
	  	 memset(vis,0,sizeof(vis)); ans=0;
	  	 Dfs(1,0);
	  }
}A[5];
void Merge(Node &x,Node y)
{
	 int i,j; int id=1,Id=1;
	 x.getsum(); y.getsum();
	 for (i=1;i<=x.size;++i) if (x.f[i]>x.f[id]) id=i;
	 for (i=1;i<=y.size;++i) if (y.f[i]>y.f[Id]) Id=i;
	 x.add(id,Id+x.size);
	 for (i=1;i<=y.size;++i)
	   for (j=0;j<(int)y.v[i].size();j++)  x.add(i+x.size,y.v[i][j]+x.size);
	   x.size+=y.size;
}
int main()
{
	scanf("%d%d%d",&n1,&n2,&n3);
	for (i=1;i<n1;++i) scanf("%d%d",&x,&y),A[1].add(x,y); A[1].size=n1;
    for (i=1;i<n2;++i) scanf("%d%d",&x,&y),A[2].add(x,y); A[2].size=n2;
    for (i=1;i<n3;++i) scanf("%d%d",&x,&y),A[3].add(x,y); A[3].size=n3;
    for (i=1;i<=3;++i)
    {
    	  A[4]=A[i];
    	  for (j=1;j<=3;++j)
    	    if (i!=j) Merge(A[4],A[j]);
    	  A[4].getsum();
    	  ans=max(ans,A[4].ans);
    	  
    	  A[4]=A[i]; 
		  for (j=3;j;--j)
		    if (i!=j) Merge(A[4],A[j]);
		  A[4].getsum();
		  ans=max(ans,A[4].ans);
    }
    printf("%I64d\n",ans);
}