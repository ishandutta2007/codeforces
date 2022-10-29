#include<cstdio>
#include<algorithm>
using namespace std;
int i,j,m,n,f1,f2,min1,max1;
int f[10001];
int main()
 {scanf("%d%d%d%d",&n,&m,&min1,&max1);
  for (i=1;i<=m;i++)
   {scanf("%d",&f[i]);
      if (f[i]<min1||f[i]>max1) {  printf("Incorrect\n"); return 0;}
      if (f[i]==min1) f1=1;
      if (f[i]==max1) f2=1;
}
  if (f1&&f2){ printf("Correct\n"); return 0;}
  if ((f1||f2)&&n-m>=1) { printf("Correct\n"); return 0;}
  if (n-m>=2) {printf("Correct\n"); return 0;}
  printf("Incorrect\n");
  return 0;
}