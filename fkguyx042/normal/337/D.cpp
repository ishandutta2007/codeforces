#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node{int ed,before;}s[200001];
int i,j,m,n,p,k,d,x,y,k1,fox[100001],ans;
int f[100001][2];
int Kth[100001],fa[100001];
struct node{int x,y;}Q[100001];
void add(int p1,int p2)
{ s[++k1].ed=p2; s[k1].before=fox[p1]; fox[p1]=k1;
  s[++k1].ed=p1; s[k1].before=fox[p2]; fox[p2]=k1; }
inline bool cmp(node a,node b){  return a.y>b.y; }
void dfs(int x,int F)
{ fa[x]=F; int i;
  f[x][0]=-1;
  for (i=fox[x];i;i=s[i].before)
    if (s[i].ed!=fa[x])
   { dfs(s[i].ed,x);
      if (f[s[i].ed][0]!=-1) f[x][0]=max(f[x][0],f[s[i].ed][0]+1);
   }
  if (Kth[x]) f[x][0]=max(0,f[x][0]);
}
void Dfs(int x)
{  //f[x][1]=-1; 
   f[x][1]=max(f[x][1],f[fa[x]][1]==-1?-1:f[fa[x]][1]+1);
   int l=0,i;
   for (i=fox[x];i;i=s[i].before)
     if (s[i].ed!=fa[x])
     Q[++l].x=s[i].ed,Q[l].y=f[s[i].ed][0];
   if (l>1)
   {
    sort(Q+1,Q+l+1,cmp);
    for (i=fox[x];i;i=s[i].before)
      if (s[i].ed!=fa[x])
     if (Q[1].x==s[i].ed)
      f[s[i].ed][1]=max(f[s[i].ed][1],Q[2].y==-1?-1:Q[2].y+2);
      else f[s[i].ed][1]=max(f[s[i].ed][1],Q[1].y==-1?-1:Q[1].y+2);
   }
if (Kth[x]) f[x][1]=max(0,f[x][1]);
  for (i=fox[x];i;i=s[i].before)
  if (s[i].ed!=fa[x]) 
  Dfs(s[i].ed);
}
int main()
{  scanf("%d%d%d",&n,&m,&d);
   for (i=1;i<=m;i++) { scanf("%d",&p); Kth[p]=1; }
   for (i=1;i<n;i++) { scanf("%d%d",&x,&y); add(x,y); }
   for (i=1;i<=n;i++) f[i][1]=-1;
   f[0][0]=f[0][1]=-1;
   dfs(1,0);
   Dfs(1);
   for (i=1;i<=n;i++)
    if (max(f[i][0],f[i][1])<=d) ans++;
    printf("%d\n",ans);
}