#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int N = 1e7 + 3;
int n;
int has[N];
LL ans, ai, aj;
int main() {
  scanf("%d", &n);
  ans = 1e17;
  for (int i=1, x; i<=n; ++i) {
    scanf("%d", &x);
    if (has[x]){
      if (x < ans) {
        ans = x;
        ai = has[x];
        aj = i;
      }
    }
    has[x] = i;
  }
  for (int i=1; i<N; ++i) {
    LL bst[2], bc = 0;
    for (int j=i; j<N; j+=i) {
      if (not has[j]) continue;
      bst[bc ++] = j;
      if (bc == 2){
        LL tans = (bst[0] / i) * bst[1];
        if (tans < ans) {
          ans = tans;
          ai = has[bst[0]];
          aj = has[bst[1]];
        }
        break;
      }
    }
  }
  if (ai > aj) {
    swap(ai, aj);
  }
  printf("%lld %lld\n", ai, aj);
}