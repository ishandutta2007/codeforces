#include<cstdio>
#include<algorithm>
#include<cstring>
const int Mo=(int)(1e9)+7;
using namespace std;
int i,j,m,n,p,k;
int f[2001][2001];
int main()
{ scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++) f[1][i]=1;
  for (j=1;j<k;j++)
    for (i=1;i<=n;i++)
      for (p=i;p<=n;p+=i)
       (f[j+1][p]+=f[j][i])%=Mo; p=0;
for (i=1;i<=n;i++)
  p=(p+f[k][i])%Mo;
  printf("%d\n",p);
}