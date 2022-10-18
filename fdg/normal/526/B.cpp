#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int cnt[10002], last, mx, mem[10002];

int get(int i) {
  if (i > last) return 0;
  return mem[i] = max(cnt[2 * i] + get(2 * i), cnt[2 * i + 1] + get(2 * i + 1));
}

int ans = 0;

void dfs(int v) {
  if (2 * v > last) return;
  int left = mem[v];
  ans += left - mem[2 * v] - cnt[2 * v];
  ans += left - mem[2 * v + 1] - cnt[2 * v + 1];
  dfs(2 * v);
  dfs(2 * v + 1);
}

int main() {
  int n;
  scanf("%d", &n);
  last = (2 << n) - 1;
  for (int i = 2; i <= last; ++i)
    scanf("%d", &cnt[i]);

  mx = get(1);
  dfs(1);
  cout << ans << endl;

  return 0;
}