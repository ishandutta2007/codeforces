#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int main()
{ scanf("%d%d",&n,&k);
 if (n==1&&k==1) { printf("a"); } 
  else 
  if (k>n||k==1) printf("-1\n"); else
{    for (i=1;i<=(n-k+2)/2;i++) printf("ab");
     if ((n-k+2)%2==1) printf("a");
     for (i=1;i<=k-2;i++) printf("%c",'a'+i+1);
}
}