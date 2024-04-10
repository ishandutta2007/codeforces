#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

template <typename T, typename Cmp = less<T>>
struct RMQ {
  vector<vector<T>> minv;
  RMQ(const vector<T> &vals) {
    minv.push_back(vals);
    for (int l = 1; 1<<l <= (int)vals.size(); ++l) {
      minv.push_back(vector<T>(vals.size() - (1<<l) + 1));
      for (int i = 0; i + (1<<l) <= (int)vals.size(); ++i)
	minv[l][i] = min(minv[l-1][i], minv[l-1][i+(1<<l-1)], Cmp());
    }
  }
  T query(int a, int b) {
    int size = b-a+1, maxl = __builtin_clz(1) - __builtin_clz(size);
    return min(minv[maxl][a], minv[maxl][b - (1<<maxl) + 1], Cmp());
  }
};

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> vis(n), rev(n);
  for (vector<int> &list : {ref(vis), ref(rev)})
    for (int i = 0; i < n; ++i)
      scanf("%d", &list[i]);

  RMQ<int, greater<int>> visrmq(vis);
  RMQ<int> revrmq(rev);
  vector<int> pot(n);

  for (int i = 0; i < n; ++i) {
    int l = i, r = n-1;
    while (r-l+1 > 2) {
      int m = (l+r)/2;
      int scorevis = 100*visrmq.query(i, m);
      int scorerev = revrmq.query(i, m);
      if (scorevis <= scorerev) l = m;
      else r = m;
    }
    pot[i] = INT_MIN;
    for (int m = l; m <= r; ++m) {
      int scorevis = 100*visrmq.query(i, m);
      int scorerev = revrmq.query(i, m);
      int score = min(scorevis, scorerev);
      pot[i] = max(pot[i], score);
    }
  }

  sort(pot.begin(), pot.end());

  vector<double> logfact(n+1);
  logfact[0] = 0;
  for (int v = 1; v <= n; ++v) logfact[v] = logfact[v-1] + log(v);

  auto logbinom = [&logfact](int a, int b) {
    return logfact[a] - logfact[b] - logfact[a-b];
  };
  
  double result = 0.0;
  for (int i = 0; i <= n-k; ++i) {
    const int r = n-i-1;
    double logprob = logbinom(r, k-1) - logbinom(n, k);
    double prob = exp(logprob);
    result += prob * pot[i];
  }

  printf("%.10f\n", result);
  
  return 0;
}