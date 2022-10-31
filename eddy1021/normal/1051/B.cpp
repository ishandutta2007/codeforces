#include <stdio.h>
long long l, r;
int main(){
  scanf("%lld%lld", &l, &r);
  puts("YES");
  for(long long i=l; i<=r; i+=2) printf("%lld %lld\n", i, i+1);
}