#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char c[1000001];
int a[100001];
int i,j,k;
using namespace std;
int main()
 { scanf("%s",&c);
   for (i=0;i<=strlen(c)-1;i++)
     if (c[i]!='+')  a[++k]=c[i]-'0';
sort(a+1,a+k+1);
  printf("%d",a[1]);
for (i=2;i<=k;i++)
  printf("+%d",a[i]);
printf("\n");
 return 0;
}