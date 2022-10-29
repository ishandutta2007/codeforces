#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,tot,k1;
int a[201],before[201],Before[201];
struct Node{int ed,before;}s[100001];
int fox[201];
void add(int p1,int p2) {s[++k1].ed=p2; s[k1].before=fox[p1]; fox[p1]=k1; }
int bfs(int Now)
{  int sum=-1,i,j,ft; 
  //memset(Before,before,sizeof(before));
   for (i=1;i<=n;i++) Before[i]=before[i]; tot=0;
   for (;;)
   {  sum++;
      ft=1;
      while (ft)
      {  ft=0;
      for (i=1;i<=n;i++) if (a[i]==Now&&Before[i]==0)
      { Before[i]=-1; tot++;   for (j=fox[i];j;j=s[j].before) Before[s[j].ed]--; ft=1;
        sum++;
         if (tot==n) return sum;
      }
 }
      Now=Now%3+1;
}
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (i=1;i<=n;i++)
  { scanf("%d",&before[i]);
     for (j=1;j<=before[i];j++) scanf("%d",&p),add(p,i);
  }
  int ans=(int)1e9;
  for (i=1;i<=3;i++)
   ans=min(ans,bfs(i));
  printf("%d\n",ans);
}