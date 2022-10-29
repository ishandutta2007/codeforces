#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,q;
int fa[1000008][21],deep[1000008];
int R,T,Max;
void add(int x,int y)
 { fa[x][0]=y;
   deep[x]=deep[y]+1;
   for (i=1;i<=20;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
 }
int lca(int x,int y) 
{   if (x==y) return x;
    if (deep[x]<deep[y]) swap(x,y);
    for (i=0;i<20;i++) if ((deep[x]-deep[y])&(1<<i)) x=fa[x][i];
    for (i=19;i>=0;i--) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int Ask(int x,int y)
{ return deep[x]+deep[y]-(deep[lca(x,y)]*2);}
int main()
{ scanf("%d",&q); n=4;
  fa[4][0]=fa[2][0]=fa[3][0]=1;
  R=2,T=3,Max=2;
  deep[2]=deep[3]=deep[4]=1;
  for (;q--;)
  { scanf("%d",&k);
    add(++n,k);
    add(++n,k);
    if (Ask(R,n)>Max) Max++,T=n;
    if (Ask(T,n)>Max) Max++,R=n;
    printf("%d\n",Max);
  }
}