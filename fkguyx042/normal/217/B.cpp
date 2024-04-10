#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=(int)1e9;
int i,j,m,n,p,k,ans=INF;
int Ans[2000001],K[2000001];
void update(int x,int y)
{ int Len=1; int i;
  for (;x!=y&&x>=0&&y>=0&&Len<=n;)
   if (x>y) K[Len++]=1,x-=y;
   else K[Len++]=2,y-=x;
  if (Len!=n||y!=1) return;
    K[Len]=1; int Sum=0;
  for (i=1;i<Len;i++)
     if (K[i]==K[i+1]) Sum++;
     if (Sum<ans)
     { ans=Sum;
       for (i=0;i<Len;i++) Ans[i]=K[Len-i];
    }
}
int main()
{  //  freopen("1.out","w",stdout);
  scanf("%d%d",&n,&m);
  for (i=1;i<=m;i++)
  {  update(i,m);
     update(m,i);
  } 
  if (ans==INF) printf("IMPOSSIBLE\n");
  else { printf("%d\n",ans);
    for (i=0;i<n;i++) printf(Ans[i]==1?"T":"B");
}
}