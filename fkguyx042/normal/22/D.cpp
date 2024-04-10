#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,vis[1005],Ans[1005];
struct Node{int x,y;}A[1005];
inline bool cmp(Node a,Node b) { return a.y<b.y; }
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i) 
	  {
	    scanf("%d%d",&A[i].x,&A[i].y);
	    if (A[i].x>A[i].y) swap(A[i].x,A[i].y);
	  }
	  sort(A+1,A+n+1,cmp);
	  for (i=1;i<=n;++i)
	    if (!vis[i])
	    {
	    	  Ans[++Ans[0]]=A[i].y;
	    	    for (j=1;j<=n;++j) if (A[j].x<=A[i].y&&A[i].y<=A[j].y) vis[j]=1;
	    }
	  printf("%d\n",Ans[0]);
	  for (i=1;i<=Ans[0];++i) printf("%d ",Ans[i]);
}