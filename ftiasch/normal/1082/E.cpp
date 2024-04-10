#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 500'000;

int n, c, a[N], before[N], after[N];
std::vector<int> bucket[N];

int main() {
  scanf("%d%d", &n, &c);
  c--;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    a[i]--;
    bucket[a[i]].push_back(i);
  }
  before[0] = 0;
  for (int i = 0; i + 1 < n; ++i) {
    before[i + 1] = before[i] + (a[i] == c);
  }
  after[n - 1] = 0;
  for (int i = n - 2; i >= 0; --i) {
    after[i] = (a[i + 1] == c) + after[i + 1];
  }
  int result = 0;
  for (int k = 0; k < N; ++k) {
    const auto &indices = bucket[k];
    // i <= j, before[indices[i]] + (j - i + 1) + after[indices[j]]
    int maxpf = INT_MIN;
    for (int i = 0; i < static_cast<int>(indices.size()); ++i) {
      maxpf = std::max(maxpf, before[indices[i]] - i);
      result = std::max(result, maxpf + i + 1 + after[indices[i]]);
    }
  }
  printf("%d\n", result);
}