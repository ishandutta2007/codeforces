#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
long long l,r;
int main()
{ scanf("%I64d%I64d",&l,&r);
  for (i=63;i>=0;i--)
  if ((l&(1ll<<i))^(r&(1ll<<i))) break;
  printf("%I64d\n",(1ll<<(i+1))-1);
}