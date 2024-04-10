#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int f[1001][1001];
const int n = 1000;

void add(int x, int y) {
  // cout << x << "  " << y << endl;
  f[x][y] = f[y][x] = 1;
}

bool used[1002];
int ans[1002];

int calc(int u) {
  if (u == 1) return 1;
  if (used[u]) return ans[u];
  int ret = 0;
  used[u] = 1;
  for (int i = 0; i < u; ++i)
    if (f[u][i]) {
      ret += calc(i);
    }
  // cout << "U: " << u << " " << ret << endl;
  return ans[u] = ret;
}


int main() {
  int k;
  scanf("%d", &k);

  // for (int i = 0; i < 2; ++i)
  //   for (int j = 2; j < 4; ++j)
  //     f[i][j] = f[j][i] = 1;

  int deg[32] = {0};
  deg[0] = 2;
  add(2, 1);
  int cnt = 3;
  for (int i = 1; i <= 30; ++i) {
    add(cnt, deg[i - 1]);
    add(cnt + 1, deg[i - 1]);
    add(cnt + 2, cnt);
    add(cnt + 2, cnt + 1);
    deg[i] = cnt + 2;
    cnt += 3;
  }

  // cout << k << endl;
  int prev = cnt++;
  add(0, prev);
  for (int i = 30; i >= 0; --i) {
    // if (i == 0 && k % 2 == 0) {
    //   prev = ++cnt;
    //   // cout << "fuck\n";
    // }
    // else {
    //   add(cnt, prev); prev = cnt;
    //   ++cnt;
    // }
    add(cnt, prev); prev = cnt;
    ++cnt;
    add(cnt, prev); prev = cnt;
    ++cnt; 
    if (k & (1<<i)) {
      add(prev, deg[i]);
    }
  }

  // cout << calc(0) << endl;
  // cout << cnt << endl;
  // return 0;
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; ++i) {
    for (int j = 0; j < cnt; ++j) {
      if (f[i][j] == 1) printf("Y");
      else printf("N");
    }
    printf("\n");
  }
  return 0;
}