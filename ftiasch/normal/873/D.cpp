#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;

int n, cnt, a[N];

void recur(int l, int r, int offset) {
  if (l + 1 == r) {
    a[l] = offset;
  } else if (cnt == 0) {
    std::iota(a + l, a + r, offset);
  } else {
    cnt--;
    int m = (l + r) >> 1;
    recur(l, m, offset + (r - m));
    recur(m, r, offset);
  }
}

bool work() {
  if (~cnt & 1) {
    return false;
  }
  cnt = (cnt - 1) >> 1;
  recur(0, n, 1);
  if (cnt > 0) {
      return false;
  }
  for (int i = 0; i < n; ++ i) {
      printf("%d%c", a[i], " \n"[i + 1 == n]);
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &cnt);
  if (!work()) {
    puts("-1");
  }
}