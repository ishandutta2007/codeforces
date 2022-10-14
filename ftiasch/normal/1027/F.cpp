#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1'000'000;

int n, m, a[N], b[N], parent[N + N + 1];
bool cycle[N + N + 1];

int find(int u) {
  if (parent[u] != u) {
    parent[u] = find(parent[u]);
  }
  return parent[u];
}

bool add(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) {
    if (cycle[a]) {
      return false;
    }
    cycle[a] = true;
  } else {
    if (cycle[a] && cycle[b]) {
      return false;
    }
    cycle[a] |= cycle[b];
    parent[b] = a;
  }
  return true;
}

bool check(int limit) {
  std::fill(cycle, cycle + m, false);
  std::iota(parent, parent + m, 0);
  add(0, 0);
  for (int i = 0; i < n; ++i) {
    if (!add(a[i], b[i] <= limit ? b[i] : 0)) {
      return false;
    }
  }
  return true;
}

int main() {
  scanf("%d", &n);
  std::vector<int> days{0};
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", a + i, b + i);
    days.push_back(a[i]);
    days.push_back(b[i]);
  }
  std::sort(days.begin(), days.end());
  days.erase(std::unique(days.begin(), days.end()), days.end());
  int low = 0;
  for (int i = 0; i < n; ++i) {
    a[i] = std::lower_bound(days.begin(), days.end(), a[i]) - days.begin();
    low = std::max(low, a[i]);
    b[i] = std::lower_bound(days.begin(), days.end(), b[i]) - days.begin();
  }
  int high = m = days.size();
  while (low < high) {
    int middle = (low + high) >> 1;
    if (check(middle)) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }
  printf("%d\n", high < m ? days[high] : -1);
}