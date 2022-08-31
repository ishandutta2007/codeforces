#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int64 LIM = 1e18;

bool issqr(int64 x) {
  int64 ok = -1, ng = 1 << 30;
  while(ng - ok > 1) {
    int64 mid = (ok + ng) >> 1;
    if(mid * mid <= x) ok = mid;
    else ng = mid;
  }
  return (ok * ok == x);
}

int64 sqrsum(int64 x) {
  int64 ok = -1, ng = 1 << 30;
  while(ng - ok > 1) {
    int64 mid = (ok + ng) >> 1;
    if(mid * mid <= x) ok = mid;
    else ng = mid;
  }
  return ok;
}


int main() {
  vector< int64 > add;
  for(int64 a = 2; a * a * a <= LIM; a++) {
    int64 b = a * a;
    double c = a * a;
    while(c <= LIM) {
      if(!issqr(b)) add.emplace_back(b);
      b *= a;
      c *= a;
    }
  }
  sort(begin(add), end(add));
  add.erase(unique(begin(add), end(add)), end(add));

  int Q;
  scanf("%d", &Q);
  int64 ret = 0;
  while(Q--) {
    int64 L, R;
    scanf("%lld %lld", &L, &R);
    auto p = lower_bound(begin(add), end(add), L) - begin(add);
    auto q = upper_bound(begin(add), end(add), R) - begin(add);
    int64 sz = q - p;
    printf("%lld\n", sz + sqrsum(R) - sqrsum(L - 1));
  }
}