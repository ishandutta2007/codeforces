#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long i,j,m,n,p,k;
long long b,t;
int main()
{ scanf("%I64d%I64d%I64d%I64d",&k,&b,&n,&t);
  long long ans=0,sum=1;
  for (;sum<t;sum=sum*k+b) ans++;
  if (sum>t) ans--;
  n=n-ans;
  if (n<0) n=0;
  printf("%I64d\n",n);
return 0;
}