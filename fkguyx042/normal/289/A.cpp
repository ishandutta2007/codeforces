#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int main()
{ scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++)
  { scanf("%d%d",&m,&p); 
     (j+=(p-m+1))%=k;
}
printf("%d\n",(k-j)%k);
}