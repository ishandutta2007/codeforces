#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
long long i,j,m,n,p,k;
long long a[100001];
bool doit(long long num) 
 {  long long i;
  for (i=2;i<=(long long)sqrt(num);i++) if (num%i==0) return false;
  return true;
}
int main()
{scanf("%I64d",&n);
 for (i=1;i<=n;i++)
  { scanf("%I64d",&a[i]);
    if (a[i]==1) { printf("NO\n"); }
    else {
     if ((long long)(sqrt(a[i]))*(long long)(sqrt(a[i]))!=a[i]) printf("NO\n");
     else {
       p=(long long)sqrt(a[i]);
     if (doit(p)) printf("YES\n"); else printf("NO\n");
}
}
}
return 0;
}