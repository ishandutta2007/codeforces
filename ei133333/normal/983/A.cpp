#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  scanf("%d", &N);
  while(N--) {
    int64 P, Q, B;
    scanf("%lld %lld %lld",&P, &Q, &B);
    if(P == 0) {
      puts("Finite" );
      continue;
    }
    auto Z = __gcd(P, Q);
    P /= Z;
    Q /= Z;
    while(__gcd(Q, B) > 1) {
      auto x = __gcd(Q, B);
      while(Q % x == 0) Q /= x;
    }
    if(Q == 1) puts("Finite");
    else puts("Infinite");
  }
}