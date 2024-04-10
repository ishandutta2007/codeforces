#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 300005
using namespace std;
int i,j,m,n,p,k,x,y;
int Bian[N][5],v[N],belong[N];
void Do(int x)
{  int Ct=0,i;
   for (i=1;i<=v[x];i++) if (belong[Bian[x][i]]==belong[x]) Ct++;
   if (Ct>=2)
   { belong[x]^=1;  for (i=1;i<=v[x];i++)
       if (belong[x]==belong[Bian[x][i]]) Do(Bian[x][i]);
}
}
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=m;i++)
{  scanf("%d%d",&x,&y);
   Bian[x][++v[x]]=y;
   Bian[y][++v[y]]=x;
}
  for (i=1;i<=n;i++) Do(i);
  for (i=1;i<=n;i++) printf("%d",belong[i]);
}