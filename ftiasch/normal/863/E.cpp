#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

int n, l[N], r[N];

int solve() {
  std::vector<int> values;
  values.reserve(n << 1);
  for (int i = 0; i < n; ++i) {
    values.push_back(l[i]);
    values.push_back(r[i] + 1);
  }
  std::sort(values.begin(), values.end());
  values.erase(std::unique(values.begin(), values.end()), values.end());
  int m = values.size();
  std::vector<int> sum(m);
  for (int i = 0; i < n; ++i) {
    sum[l[i] = std::lower_bound(values.begin(), values.end(), l[i]) -
               values.begin()]++;
    sum[r[i] = std::lower_bound(values.begin(), values.end(), r[i] + 1) -
               values.begin()]--;
  }
  for (int i = 1; i < m; ++i) {
    sum[i] += sum[i - 1];
  }
  for (int i = m; i--;) {
    sum[i] = sum[i] < 2 ? i : sum[i + 1];
  }
  for (int i = 0; i < n; ++i) {
    if (r[i] <= sum[l[i]]) {
      return i + 1;
    }
  }
  return -1;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", l + i, r + i);
  }
  printf("%d\n", solve());
}