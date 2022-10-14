#include <bits/stdc++.h>

const int N = 100000;

int n, m, a[N], b[N];
std::pair<std::string, int> p[N];

int solve(int limit, int* b)
{
  int low = 0;
  int high = n - 1;
  while (low < high) {
    int middle = low + high >> 1;
    bool ok = true;
    int count = n - 1 - middle;
    for (int i = 0; i < count; ++ i) {
      ok &= a[i] + b[count  - 1 - i] <= limit;
    }
    if (ok) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }
  return high;
}

int main() {
  static char buffer[21];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s%d", buffer, &p[i].second);
    p[i].second <<= 1;
    p[i].first = buffer;
  }
  std::sort(p, p + n);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", b + i);
    b[i] <<= 1;
  }
  std::sort(b, b + n);
  scanf("%s", buffer);
  int who = std::lower_bound(p, p + n, std::make_pair(std::string(buffer), 0)) - p;
  for (int i = 0; i < who; ++i) {
    a[i] = p[i].second + 1;
  }
  for (int i = who + 1; i < n; ++i) {
    a[i - 1] = p[i].second - 1;
  }
  std::sort(a, a + n - 1);
  int highest = solve(p[who].second + b[n - 1], b);
  for (int i = 0; i < n; ++ i) {
    a[i] *= -1, b[i] *= -1;
  }
  std::reverse(a, a + n - 1);
  std::reverse(b, b + n);
  int lowest = solve(-p[who].second + b[n - 1], b);
  printf("%d %d\n", 1 + highest, n - lowest);
}