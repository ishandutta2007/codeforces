#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int Q;
int64 v_shift[100000];

void rec(int64 idx, int64 dep) {
  printf("%lld ", idx);
  if(dep == 0) return;

  int64 real = idx;
  real -= 1LL << dep;
  real += v_shift[dep];
  real %= 1LL << dep;
  real += 1LL << dep;
  real /= 2;

  real -= 1LL << (dep - 1);
  real += (1LL << (dep - 1)) - v_shift[dep - 1];
  real %= 1LL << (dep - 1);
  real += 1LL << (dep - 1);

  rec(real, dep - 1);
}

int main() {


  scanf("%d", &Q);
  for(int i = 0; i < Q; i++) {
    int64 T, X, K;
    scanf("%lld %lld", &T, &X);
    if(T == 1) {
      scanf("%lld", &K);
      for(int64 j = 60; j >= 0; j--) {
        if((X >> j) & 1) {
          int64 add = K;
          add += 1LL << 61;
          add %= 1LL << j;
          v_shift[j] += add;
          v_shift[j] %= 1LL << j;
          break;
        }
      }
    } else if(T == 2) {
      scanf("%lld", &K);
      int64 last = 0;
      for(int64 j = 1; j <= 60; j++) {
        if((X >> j) & 1) last = j;
      }
      int64 add = K;

      for(int64 j = last; j <= 60; j++) {
        add += 1LL << 61;
        add %= 1LL << j;
        v_shift[j] += add;
        v_shift[j] %= (1LL << j);
        add *= 2;
      }
    } else {
      for(int64 j = 60; j >= 0; j--) {
        if((X >> j) & 1) {
          rec(X, j);
          break;
        }
      }
      puts("");
      fflush(stdout);
    }
  }

}