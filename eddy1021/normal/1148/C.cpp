#include <bits/stdc++.h>
using namespace std;
constexpr int N = 303030;
int n, p[N], at[N];
vector<pair<int, int>> ans;
void Swap(int i, int j) {
  ans.push_back({i, j});
  swap(p[i], p[j]);
  at[p[i]] = i;
  at[p[j]] = j;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
    at[p[i]] = i;
  }
  int left = n / 2;
  for (int i = 1; i <= n; ++i) {
    if (i == p[i]) {
      continue;
    }
    if (2 * abs(i - at[i]) >= n) {
      Swap(i, at[i]);
      continue;
    }
    if (i <= left and at[i] <= left) {
      Swap(i, n);
      Swap(at[i], n);
      Swap(i, n);
      continue;
    }
    if (left < i and left < at[i]) {
      Swap(i, 1);
      Swap(at[i], 1);
      Swap(i, 1);
      continue;
    }
    int lh = min(i, at[i]);
    int rh = max(i, at[i]);
    assert(lh <= left and left < rh);
    Swap(1, rh);
    Swap(1, n);
    Swap(lh, n);
    Swap(1, n);
    Swap(1, rh);
  }
  printf("%d\n", (int)ans.size());
  for (auto i: ans) {
    printf("%d %d\n", i.first, i.second);
  }
}