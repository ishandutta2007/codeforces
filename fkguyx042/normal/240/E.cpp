#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,k1,x,y,z;
int vis[100005],fox[100005],Q[10000005],l,Ans[1000005];
struct Node{int ed,before,cost;}s[100005];
void add(int x,int y,int z)
{ 
 s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; s[k1].cost=z;
}
int main()
{
	  freopen("input.txt","r",stdin);
	  freopen("output.txt","w",stdout);
	  scanf("%d%d",&n,&m);
	  for (i=1;i<=m;i++)
	{ 
	    scanf("%d%d%d",&x,&y,&z);
	    add(x,y,z);
    }
    vis[1]=-1; Q[Q[0]=1]=1;
    for (l=1;l<=Q[0];++l)
    {
    	  p=Q[l];
    	  for (i=fox[p];i;i=s[i].before) 
    	    if (!vis[s[i].ed]||vis[s[i].ed]!=-1&&s[i].cost==0)
    	    {
    	    	   vis[s[i].ed]=s[i].cost==0?-1:i;
    	    	   Q[++Q[0]]=s[i].ed;
    	    }
    }
    for (i=1;i<=n;++i)
      if (!vis[i]) {
      	  printf("-1\n");
      	  return 0;
      }
      else if (vis[i]!=-1) Ans[++Ans[0]]=vis[i];
    printf("%d\n",Ans[0]);
    for (i=1;i<=Ans[0];i++) printf("%d ",Ans[i]);
}