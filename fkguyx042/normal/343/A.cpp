#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long x,y;
long long ans;
long long Gcd(long long x,long long y) { 
     if (!y) return x; 
     ans+=x/y;
     return Gcd(y,x%y);
}
int main()
{ scanf("%I64d%I64d",&x,&y);
  Gcd(x,y);
  printf("%I64d\n",ans);
}