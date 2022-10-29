#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node{int x,y,z;}Bian[5000001];
int fa[2001],fox[2001],x,y;
long long dep[2001];
Node s[2000001];
int i,j,m,n,p,k,tot,k1,a[2001][2001];
inline bool cmp(Node a,Node b) {return a.z<b.z;}
void add(int x,int y,int z)
{s[++k1].x=y; s[k1].y=fox[x]; fox[x]=k1; s[k1].z=z;
 s[++k1].x=x; s[k1].y=fox[y]; fox[y]=k1; s[k1].z=z;
}
int getfa(int x) {return x==fa[x]?x:fa[x]=getfa(fa[x]);}
void dfs(int x,int y)
{  int i;
   for (i=fox[x];i;i=s[i].y)
     if (s[i].x!=y)
     {   dep[s[i].x]=dep[x]+s[i].z;
         dfs(s[i].x,x);
    }
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) for (j=1;j<=n;j++) scanf("%d",&a[i][j]);
  for (i=1;i<=n;i++) if (a[i][i]) { printf("NO\n"); return 0; }
  for (i=1;i<=n;i++) for (j=i+1;j<=n;j++)
   if (a[i][j]!=a[j][i]||!a[i][j]) { printf("NO\n"); return 0;}
  for (i=1;i<=n;i++)
    for (j=i+1;j<=n;j++) Bian[++tot].x=i,Bian[tot].y=j,Bian[tot].z=a[i][j];
    for (i=1;i<=n;i++) fa[i]=i;
    sort(Bian+1,Bian+tot+1,cmp);
    for (i=1;i<=tot;i++)
   {  x=getfa(Bian[i].x); 
      y=getfa(Bian[i].y);
      if (x!=y) fa[x]=y,add(Bian[i].x,Bian[i].y,Bian[i].z);
   }
   for (i=1;i<=n;i++)
   { memset(dep,0,sizeof(dep));
      dfs(i,0);
       for (j=1;j<=n;j++) if (a[i][j]!=dep[j]) { printf("NO\n"); return 0;}
   }
   printf("YES\n");
}