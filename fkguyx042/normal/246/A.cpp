#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,i;
int main()
{ scanf("%d",&n); if (n<=2) printf("-1\n");
else {  printf("2 3 1");
   for (i=4;i<=n;i++) printf(" %d",i);
   printf("\n"); }
}