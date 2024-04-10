#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node{int ed,before;}s[200001];
int i,j,m,n,p,k,k1,fox[100001];
int a[100001],tot,Q[100001];
int ans[100001];
void add(int p1,int p2){s[++k1].ed=p2; s[k1].before=fox[p1]; fox[p1]=k1; }
void bfs()
{   int l=1,r=0,p;
   for (i=1;i<=n;i++)
     if (!a[i]) Q[++r]=i;
   for (;l<=r;l++)
    {  p=Q[l];
       ans[++tot]=p;
       for (i=fox[p];i;i=s[i].before) 
       {   a[s[i].ed]--;
         if (!a[s[i].ed]) Q[++r]=s[i].ed;
       }
}
}
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=m;i++) scanf("%d%d",&p,&k),add(p,k),add(k,p);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  bfs();
  printf("%d\n",tot);
  for (i=1;i<=tot;i++) printf("%d ",ans[i]);
}