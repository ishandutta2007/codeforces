#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a,b;
long long x;
int gcd(int x,int y) { return y==0?x:gcd(y,x%y); }
int main()
{scanf("%d%d%d",&n,&a,&b);
  for (i=1;i<=n;i++)
  { scanf("%I64d",&x);
    printf("%I64d ",1ll*(x*a)%b/a);
}
}