#line 1 "sol.cpp"
#include <bits/stdc++.h>

using List = std::vector<std::pair<int, int>>;

double take(List &candidates, long long limit) {
  std::sort(candidates.begin(), candidates.end());
  double result = 0.;
  for (auto [t, a] : candidates) {
    if (1LL * t * a <= limit) {
      limit -= 1LL * t * a;
      result += a;
    } else {
      return result + 1.0 * limit / t;
    }
  }
  return result;
}

int main() {
  int n, T;
  scanf("%d%d", &n, &T);
  std::vector<int> a(n), t(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  long long psum = 0, nsum = 0;
  double result = 0;
  List positives, negatives;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t[i]);
    t[i] -= T;
    if (t[i] < 0) {
      nsum -= 1LL * t[i] * a[i];
      negatives.emplace_back(-t[i], a[i]);
    } else if (t[i] > 0) {
      psum += 1LL * t[i] * a[i];
      positives.emplace_back(t[i], a[i]);
    } else {
      result += a[i];
    }
  }
  long long limit = std::min(psum, nsum);
  result += take(positives, limit);
  result += take(negatives, limit);
  printf("%.9f\n", result);
}