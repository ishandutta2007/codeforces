#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,vis[100001],x,y,k1;
struct Node{int ed,before;}s[2000001];
int fox[100001];
double ans;
void dfs(int x,int dep)
{ vis[x]=1; int i;
  ans+=1.0/(double)dep;
  for (i=fox[x];i;i=s[i].before)
    if (!vis[s[i].ed])
      dfs(s[i].ed,dep+1);
}
void add(int x,int y)
{ s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; }
int main()
{ scanf("%d",&n);
  for (i=1;i<n;i++)
  { scanf("%d%d",&x,&y); add(x,y);add(y,x); }
  dfs(1,1);
  printf("%.20lf\n",ans);
}