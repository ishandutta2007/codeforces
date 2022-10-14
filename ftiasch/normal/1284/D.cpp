#include <bits/stdc++.h>

using Map = std::map<int, int>;

const int N = 100000;

int n, a[N], b[N], c[N], d[N], orda[N], ordb[N];

int ask(Map &mp, int x) { return std::prev(mp.upper_bound(x))->second; }

void add(Map &mp, int x, int y) {
  if (ask(mp, x) >= y) {
    return;
  }
  mp[x] = y;
  auto iterator = std::next(mp.find(x));
  while (iterator != mp.end()) {
    if (y < iterator->second) {
      return;
    }
    auto backup = std::next(iterator);
    mp.erase(iterator);
    iterator = backup;
  }
}

bool find() {
  std::map<int, int> mp;
  mp[0] = 0;
  std::sort(orda, orda + n, [](int i, int j) { return a[i] < a[j]; });
  std::sort(ordb, ordb + n, [](int i, int j) { return b[i] < b[j]; });
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n && b[ordb[j]] < a[orda[i]]) {
      add(mp, c[ordb[j]], d[ordb[j]]);
      j++;
    }
    if (c[orda[i]] <= ask(mp, d[orda[i]])) {
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
  }
  std::iota(orda, orda + n, 0);
  std::iota(ordb, ordb + n, 0);
  bool ok = !find();
  for (int i = 0; i < n; ++i) {
    std::swap(a[i], c[i]);
    std::swap(b[i], d[i]);
  }
  ok &= !find();
  puts(ok ? "YES" : "NO");
}