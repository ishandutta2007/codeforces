#include<cstdio>
#include<algorithm>
int main(){
   long long n, m, a, b;
   scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
   printf("%lld", std::min(n % m * b, (m - n % m) * a));
   
}