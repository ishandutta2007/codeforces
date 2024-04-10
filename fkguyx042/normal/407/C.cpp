#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,n,p,k,k1,sum,l,r,x,a[100001],sky[100001];
struct Node{int l,r,before;}s[1000001];
int f[100005][105];
int Last[100005],fox[1001],C[100100][101];
void add(int x,int l,int r)
{  s[++k1].l=l;s[k1].r=r; s[k1].before=fox[x]; fox[x]=k1; }
int change(int x)
{  while (x>=Mo) x-=Mo;
  while (x<0) x+=Mo;
  return x;
}
void CC()
{   for (i=0;i<=100100;i++)
   {  C[i][0]=1;
     if (i>0)
     for (j=1;j<=100;j++)
        C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mo;
   }
}
int main()
{ scanf("%d%d",&n,&m); CC();
  for (i=1;i<=n;i++)  scanf("%d",&a[i]);
  for (i=1;i<=m;i++)
  { scanf("%d%d%d",&l,&r,&x);
     for (j=0;j<=x;j++)
      { f[l][j]=change(f[l][j]+C[x][x-j]);
        f[r+1][j]=change(f[r+1][j]-C[r-l+1+x][x-j]);
    }
}
  for (i=1;i<=n;i++)
{ 
    for (j=0;j<=100;j++)
     sky[j]=change(sky[j]+f[i][j]);
  a[i]=change(a[i]+sky[0]);
  for (j=0;j<=100;j++)
   sky[j]=change(sky[j]+sky[j+1]);
}
for (i=1;i<=n;i++) printf("%d ",a[i]);
}
 /*10 1
0 0 0 0 0 0 0 0 0 0
7 9 4*/