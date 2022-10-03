#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  int cases;
  scanf("%d",&cases);
  for(;cases;cases--) {
  	ll s,a,b,c;
  	scanf("%I64d%I64d%I64d%I64d",&s,&a,&b,&c);
  	s/=c;
  	s+=s/a*b;
  	printf("%I64d\n",s);
  }
  return 0;
}