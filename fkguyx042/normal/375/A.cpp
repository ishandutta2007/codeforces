#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int x[10];
int X[7]={1869, 6198, 1896, 1689, 1986, 1968, 1698};
char c;
int main()
{ for (c=getchar();c!='\n';c=getchar()) x[c-'0']++;
  x[1]--; x[6]--; x[8]--;x[9]--;
  for (i=1;i<=9;i++)
   while (x[i]--)
   { printf("%d",i);
     p=(p*10+i)%7;
   }
   printf("%d",X[p]);
   while (x[0]--) printf("0");
}