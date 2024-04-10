#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char c[1001];
int i,j,m,n,p,k;
int main()
 {scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++)
  { scanf("%s",&c); p=0;
    for (j=1;j<=strlen(c);j++)
      if (c[j-1]-'0'==4||c[j-1]-'0'==7) p++;
      if (p<=k) m++; }
  printf("%d\n",m);
 return 0;
}