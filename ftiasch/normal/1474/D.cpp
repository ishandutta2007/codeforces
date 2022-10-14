#include <bits/stdc++.h>

const int N = 200000;
const long long LIMIT = N * 1e9 + 1;

int n, a[N];
long long sum[N], suf[N + 2];

// (-1)^n
int pm(int n) { return n & 1 ? -1 : 1; }

bool check() {
  sum[0] = a[0];
  for (int i = 1; i < n; ++i) {
    sum[i] = a[i] - sum[i - 1];
  }
  suf[n] = suf[n + 1] = LIMIT;
  for (int i = n; i--;) {
    suf[i] = std::min(suf[i + 2], sum[i]);
  }
  if (sum[n - 1] == 0 && suf[0] >= 0 && suf[1] >= 0) {
    return true;
  }
  long long alt_sum = pm(n - 1) * sum[n - 1], pre[]{LIMIT, LIMIT};
  for (int k = 0; k + 1 < n; ++k) {
    if (k && sum[k - 1] < 0) {
      break;
    }
    int delta = a[k] - a[k + 1];
    if (alt_sum - 2 * pm(k) * delta != 0) {
      continue;
    }
    long long pre_sum = k ? sum[k - 1] : 0;
    if (a[k + 1] - pre_sum < 0) {
      continue;
    }
    if (a[k] - a[k + 1] + pre_sum < 0) {
      continue;
    }
    if (suf[k + 2] - 2 * delta < 0) {
      continue;
    }
    if (suf[k + 3] + 2 * delta < 0) {
      continue;
    }
    return true;
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    puts(check() ? "YES" : "NO");
  }
}