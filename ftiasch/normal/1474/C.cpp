#include <bits/stdc++.h>

const int N = 2000;
const int M = 1000001;

int n, a[N], now, timestamp[M], count[M], history[N + 1];

int &get(int i) {
  if (timestamp[i] != now) {
    timestamp[i] = now;
    count[i] = 0;
  }
  return count[i];
}

bool check(int first) {
  history[0] = a[first] + a[n - 1];
  history[1] = a[n - 1];
  history[2] = a[first];
  ++now;
  for (int i = 0; i < n - 1; ++i) {
    if (i != first) {
      get(a[i])++;
    }
  }
  int length = 2, sum = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    if (get(a[i]) > 0) {
      count[a[i]]--;
      if (a[i] >= sum) {
        return false;
      }
      int other = sum - a[i];
      if (get(other) == 0) {
        return false;
      }
      count[other]--;
      history[++length] = a[i];
      history[++length] = other;
      sum = a[i];
    }
  }
  return true;
}

void work() {
  std::sort(a, a + n);
  for (int first = 0; first < n - 1; ++first) {
    if (check(first)) {
      puts("YES");
      printf("%d\n", history[0]);
      for (int i = 0; i < n; ++i) {
        printf("%d%c", history[i + 1], " \n"[i & 1]);
      }
      return;
    }
  }
  puts("NO");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    n <<= 1;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    work();
  }
}