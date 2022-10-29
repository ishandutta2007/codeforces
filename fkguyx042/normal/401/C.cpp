#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int main()
{ scanf("%d%d",&n,&m);
  if (m<n-1||m>2*(n+1)) printf("-1\n");
  else if (m==n-1) {
  	  for (i=1;i<=m;i++) printf("01"); printf("0");
  }
  else if (n==m) for (i=1;i<=n;i++) printf("01");
  else {
  	  int x=m/(n+1);
  	  int y=m%(n+1);
  	  for (i=1;i<=n;i++)
  	  {     for (j=1;j<=x;j++) printf("1");
  	       if (i<=y) printf("1");
  	       printf("0");
  	  }
  	  for (i=1;i<=x;i++) printf("1");
  }
}