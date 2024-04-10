#line 1 "sol.cpp"
#include <bits/stdc++.h>

using u64 = uint64_t;

const int N = 500'001;

int n, a[N], win_sz[N], cnt[N];
u64 g[N][2], pre_hash[N + 1];

int main() {
  scanf("%d", &n);
  std::mt19937_64 gen{0};
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    g[i][0] = gen();
    g[i][1] = gen();
  }
  pre_hash[0] = 0;
  std::map<u64, int> map;
  map[0] = 1;
  long long result = 0;
  for (int i = 1, j = 0; i <= n; ++i) {
    int x = a[i];
    int idx = (cnt[x]++) % 3 + 1;
    pre_hash[i] = pre_hash[i - 1];
    if (idx & 1) {
      pre_hash[i] ^= g[x][0];
    }
    if (idx & 2) {
      pre_hash[i] ^= g[x][1];
    }
    win_sz[x]++;
    while (win_sz[x] > 3) {
      map[pre_hash[j]]--;
      j++;
      win_sz[a[j]]--;
    }
    result += map[pre_hash[i]];
    map[pre_hash[i]]++;
  }
  printf("%lld\n", result);
}