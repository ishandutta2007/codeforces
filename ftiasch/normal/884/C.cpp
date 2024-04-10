#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  std::vector<int> cycles;
  for (int i = 0; i < n; ++i) {
    if (~p[i]) {
      int size = 0;
      int j = i;
      do {
        size++;
        int backup = p[j];
        p[j] = -1;
        j = backup;
      } while (j != i);
      cycles.push_back(size);
    }
  }
  if (cycles.size() >= 2) {
    std::nth_element(cycles.begin(), cycles.begin() + cycles.size() - 2,
                     cycles.end());
    auto largest = cycles.back();
    cycles.pop_back();
    cycles.back() += largest;
  }
  long long result = 0;
  for (int c: cycles) {
      result += 1LL * c * c;
  }
  printf("%lld\n", result);
}