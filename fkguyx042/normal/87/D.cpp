#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

#define N 100005

using namespace std;

struct Node{int x,y,w,id;}B[N];
int i,j,m,n,p,k,deep[N],t_fa[N],sizea[N],sizeb[N],faa[N],fab[N];
long long Ans;
vector<int>v[N],ans;
void add(int x,int y) 
{
	v[x].push_back(y);
	v[y].push_back(x);
}
void dfs(int x)
{
     int i;
	 for (i=0;i<(int)v[x].size();++i)
	 {
	 		int p=v[x][i];
			if (t_fa[x]==p) continue;
			t_fa[p]=x; deep[p]=deep[x]+1; dfs(p);
	 }
}
inline bool cmp(Node a,Node b)
{
	  if (a.w!=b.w) return a.w<b.w;
	  return deep[a.y]>deep[b.y];
}
int geta(int x) { return faa[x]==x?x:faa[x]=geta(faa[x]); } 
int getb(int x) { return fab[x]==x?x:fab[x]=getb(fab[x]); } 
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<n;++i)
	  {
	      scanf("%d%d%d",&B[i].x,&B[i].y,&B[i].w);
		  add(B[i].x,B[i].y); B[i].id=i;
	  }
	  dfs(1);
	  for (i=1;i<n;++i) if (deep[B[i].x]>deep[B[i].y]) swap(B[i].x,B[i].y);
	  for (i=1;i<=n;++i) faa[i]=fab[i]=i,sizea[i]=sizeb[i]=1;
	  sort(B+1,B+n,cmp);
	  for (i=1;i<n;i=j)
	  {
	  	   for (j=i;j<n&&B[i].w==B[j].w;++j)
	  	   {
	  	   	    int x=geta(B[j].x),y=geta(B[j].y);
	  	   	    sizea[x]+=sizea[y];
	  	   	    faa[y]=x;
	  	   }
	  	   for (j=i;j<n&&B[i].w==B[j].w;++j)
	  	   {
	  	   	    int E=geta(B[j].x),res=sizea[E];
	  	   	    int x=B[j].y,y=getb(B[j].x);
	  	   	    sizeb[y]+=sizeb[x];
	  	   	    fab[x]=y;
	  	   	    if (1ll*(res-sizeb[x])*(sizeb[x])>Ans)
	  	   	    {  
	  	   	        Ans=1ll*(res-sizeb[x])*sizeb[x];
	  	   	        ans.clear(); ans.push_back(B[j].id);
	  	   	    }
	  	   	    else if (Ans==1ll*(res-sizeb[x])*sizeb[x])
	  	   	    ans.push_back(B[j].id);
	  	   }
	  }
	  printf("%I64d %d\n",2*Ans,ans.size());
	  sort(ans.begin(),ans.end());
	  for (i=0;i<(int)ans.size();++i) printf("%d ",ans[i]);
}