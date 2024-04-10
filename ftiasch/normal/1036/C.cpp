#line 1 "sol.cpp"
#include <bits/stdc++.h>

const uint64_t INF = 1e18;

std::vector<uint64_t> nums;

void gen(uint64_t n, int nz) {
  if (n <= INF) {
    nums.push_back(n);
    gen(n * 10, nz);
    if (nz < 3) {
      for (int d = 1; d < 10; ++d) {
        gen(n * 10 + d, nz + 1);
      }
    }
  }
}

int main() {
  for (int d = 1; d < 10; ++d) {
    gen(d, 1);
  }
  std::sort(nums.begin(), nums.end());
  int T;
  scanf("%d", &T);
  while (T--) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    printf("%d\n",
           static_cast<int>(std::upper_bound(nums.begin(), nums.end(), r) -
                            std::lower_bound(nums.begin(), nums.end(), l)));
  }
}