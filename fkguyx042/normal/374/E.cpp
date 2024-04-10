#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node{int x,y,sum;}A[2001];
Node B[2001];
struct Nde{int st,ed,sum;}Q[2001];
Nde Q1[2001];
struct Bian{int before,ed;}s[4000001];
int i,j,m,n,p,k,tot,Tot,k1,fox[4001],size[4001],Que[4001],vis[4001];
inline bool cmp(Node a,Node b) { if (a.sum!=b.sum) return a.sum<b.sum; return a.x<b.x;}
void add(int x,int y) {s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; size[x]++; }
bool Do(int x,int y)
{   double R=(Q[x].sum+Q1[y].sum)/2.0;
    R=R-Q1[y].sum;
    if (R>=Q[x].st&&R<=Q[x].ed&&R>=Q1[y].st&&R<=Q1[y].ed) return true;
    return false;
}
bool Tp()
{ int i,j,p,k,l=1,r=0;
  memset(vis,0,sizeof(vis));
  for (i=1;i<=tot+Tot;i++)
   if (size[i]<=1) Que[++r]=i,vis[i]=1;
   for (;l<=r;l++)
{  p=Que[l];
  for (i=fox[p];i;i=s[i].before)
  { size[s[i].ed]--;
    if (!vis[s[i].ed]&&size[s[i].ed]<=1)
    {   Que[++r]=s[i].ed;
        vis[s[i].ed]=1;
    }
   }
}
return r!=tot+Tot;
}
bool check(int x)
{ tot=Tot=0,k1=0;
  memset(fox,0,sizeof(fox));
  memset(size,0,sizeof(size));
   for (i=1;i<=n;i=j)
   {  Q[++tot].sum=A[i].sum;
      Q[tot].st=A[i].x-x;
      Q[tot].ed=A[i].x+x;
      for (j=i+1;j<=n&&A[j].sum==A[i].sum&&A[j].x-x<=Q[tot].ed;j++) Q[tot].ed=A[j].x+x; 
   }
    for (i=1;i<=m;i=j)
   {  Q1[++Tot].sum=B[i].sum;
      Q1[Tot].st=B[i].x-x;
      Q1[Tot].ed=B[i].x+x;
      for (j=i+1;j<=m&&B[j].sum==B[i].sum&&B[j].x-x<=Q1[Tot].ed;j++) Q1[Tot].ed=B[j].x+x; 
   }
   for (i=1;i<=tot;i++)
     for (j=1;j<=Tot;j++)
        if(Do(i,j))
        add(i,j+tot),add(j+tot,i);
   return Tp();
}
int main()
{ scanf("%d%d",&n,&m);
 for (i=1;i<=n;i++)
 { scanf("%d%d",&A[i].x,&A[i].y);
   A[i].sum=A[i].x+A[i].y;
 }
 for (i=1;i<=m;i++)
 { scanf("%d%d",&B[i].x,&B[i].y); 
   B[i].sum=B[i].y-B[i].x;
 }
 sort(A+1,A+n+1,cmp);
 sort(B+1,B+m+1,cmp);
 int l=0,r=(int)1e8,mid=0;
 for (;(l+r)>>1!=mid;)
 {  mid=(l+r)>>1;
   if (check(mid)) r=mid;
   else l=mid;
 }
 if (r==(int)1e8) printf("Poor Sereja!\n");
 else printf("%d\n",r);
}