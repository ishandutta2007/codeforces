#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,K;
char c[1001];
int a[31];
int main()
 { scanf("%d",&k);
  for (i=1;i<=4;i++)
   { scanf("%s",&c);
     for (j=1;j<=4;j++)       if (c[j-1]!='.')
       a[c[j-1]-'0']++;
   }
 for (i=1;i<=9;i++)
 if (a[i]>2*k) { printf("NO\n"); return 0;}
 printf("YES\n");
 return 0;
}