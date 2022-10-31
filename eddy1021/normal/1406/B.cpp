#include <bits/stdc++.h>
using namespace std;
constexpr int N =1e5;
constexpr int K = 5;
typedef long long LL;
LL n;
vector<LL> pos, neg;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    pos.clear();
    neg.clear();
    for (int i = 0; i < n; ++i){
      LL ai;
      scanf("%lld", &ai);
      if (ai < 0) neg.push_back(ai);
      else pos.push_back(ai);
    }
    LL ans = -1e18;
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    for (int _p = 0; _p < 2; ++_p) {
      for (int _n = 0; _n < 2; ++_n) {
        for (int p = 0; p <= 5; ++p) {
          if ((int)pos.size() < p or (int)neg.size() < K - p) continue;
          LL res = 1;
          for (int ip = 0; ip < p; ++ip) res *= pos[ip];
          for (int in = 0; in < K - p; ++in) res *= neg[in];
          ans = max(ans, res);
        }
        reverse(neg.begin(), neg.end());
      }
      reverse(pos.begin(), pos.end());
    }
    printf("%lld\n", ans);
  }
}