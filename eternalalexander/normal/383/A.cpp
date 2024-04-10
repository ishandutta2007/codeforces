#include <cstdio>
int main() {long long n, a, sum=0, ans=0; scanf("%lld", &n); for (int i=1;i<=n;++i){ scanf("%lld", &a); if (a==1) sum++; else ans+=sum;} printf("%lld", ans); return 0;}