#include <cstdio>

using namespace std;

const int N = 300010;

int n, m;
int a[N];

bool pred(int x) {
  int cur = 0;
  for (int i = 1; i <= n; ++i) {
    while ((cur - a[i] + m) % m > x) {
      ++cur;
      if (cur == m) return false;
    }
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  int l = 0, r = m - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (pred(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}