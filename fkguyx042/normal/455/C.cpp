#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int Ans[300001],fa[300001],dis[300001],flag[300001],Q[300001];
struct Node{int ed,before;}s[1000001];
int i,j,m,n,p,k,x,y,k1,fox[300001];
void add(int p1,int p2) { s[++k1].ed=p2; s[k1].before=fox[p1]; fox[p1]=k1; }
int getfa(int x) { return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int bfs(int x,int c)
{  dis[x]=0;
   flag[x]=x;
   int l=1,r=0; Q[++r]=x; int i;
   for (;l<=r;l++)
   {   int p=Q[l];
     for (i=fox[p];i;i=s[i].before)
      if (flag[s[i].ed]!=x)
      {  dis[s[i].ed]=dis[p]+1;
         flag[s[i].ed]=x;
         Q[++r]=s[i].ed;
    }
}
 if (c==1) return bfs(Q[r],2); else return dis[Q[r]];
}
int main()
{scanf("%d%d%d",&n,&m,&k);
 for (i=1;i<=n;i++) fa[i]=i;
 for (i=1;i<=m;i++)
 {  scanf("%d%d",&x,&y);
   if (getfa(x)!=getfa(y))
{
    add(x,y); add(y,x);
    x=getfa(x);
    y=getfa(y);
    if (x!=y) fa[x]=y; }
}
for (i=1;i<=n;i++) if (fa[i]==i) Ans[i]=bfs(i,1);
 for (i=1;i<=k;i++)
 { scanf("%d",&p);
   if (p==2)
   {  scanf("%d%d",&x,&y);
      x=getfa(x);y=getfa(y);
       if (x!=y)
    { fa[x]=y;
      Ans[y]=max(Ans[y],max(Ans[x],(Ans[x]+1)/2+(Ans[y]+1)/2+1));
}
}
else {  scanf("%d",&x);
       printf("%d\n",Ans[getfa(x)]);
}
}
}