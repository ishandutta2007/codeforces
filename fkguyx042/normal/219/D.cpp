#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,k1,sum,ans=(int)1e9,x,y;
int Q[200001];
int Tree[400001],fa[200001],fox[200001];
struct Node{int ed,before,kth;}s[400001];
void add(int p1,int p2,int p3)
{ s[++k1].ed=p2; s[k1].before=fox[p1]; fox[p1]=k1; s[k1].kth=p3; }
void dfs(int x)
{ int i;
  for (i=fox[x];i;i=s[i].before)
    if (s[i].ed!=fa[x])
    {    if (s[i].kth!=s[i].ed) sum++;
         fa[s[i].ed]=x;
        dfs(s[i].ed);
   }
}
void Dfs(int x,int A,int B)
{  int i; 
   int Sum=B+(sum-A);
   if (Sum<ans) ans=Sum,Q[Q[0]=1]=x;
   else if (Sum==ans) Q[++Q[0]]=x;
   for (i=fox[x];i;i=s[i].before)
     if (s[i].ed!=fa[x])
     {   if (s[i].kth!=s[i].ed) Dfs(s[i].ed,A+1,B);
         else Dfs(s[i].ed,A,B+1);
     }
}
int main()
{ scanf("%d",&n);
  for (i=1;i<n;i++)
  { scanf("%d%d",&x,&y); 
    add(x,y,y);add(y,x,y);
  }
  dfs(1);
  Dfs(1,0,0);
  printf("%d\n",ans);
  sort(Q+1,Q+Q[0]+1);
  for (i=1;i<=Q[0];i++) printf("%d ",Q[i]);
}