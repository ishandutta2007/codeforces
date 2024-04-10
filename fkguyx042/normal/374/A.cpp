#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=(int)1e9;
int i,j,m,n,p,k,ans=INF,a,b;
void Go(int x,int y)
{  if (x%a!=0||y%b!=0) return;
   int A=x/a,B=y/b;
   if (abs(A-B)%2==0) ans=min(ans,max(A,B));
}
int main()
{ scanf("%d%d%d%d%d%d",&n,&m,&i,&j,&a,&b);
  if (i==1&&j==m||i==n&&j==1||i==1&&j==1||i==n&&j==m) {printf("0\n"); return 0;}
  if (i-1<a&&n-i<a||j-1<b&&m-j<b){ printf("Poor Inna and pony!\n"); return 0;}
  Go(abs(i-1),abs(j-1));
  Go(abs(n-i),abs(j-1));
  Go(abs(n-i),abs(m-j));
  Go(abs(i-1),abs(m-j));
  if (ans==INF) printf("Poor Inna and pony!\n");
  else printf("%d\n",ans);
}