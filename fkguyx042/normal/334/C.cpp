#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,p,k,tot;
long long n,m,ans;
int Q[51];
int main()
{ scanf("%I64d",&n);
  m=n;
  for (;n;n/=3)
   Q[++tot]=n%3;
  n=1;
  ans=1;
  for (tot=1;!Q[tot];tot++) ans=ans*3ll;ans*=3ll;
  printf("%I64d\n",m/ans+1);
}