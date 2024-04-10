#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#define MAXN 500

using namespace std;

typedef long long lint;

const int dy[] = {0, 0, -1, 1}, dx[] = {1, -1, 0, 0};

int n;
bool mark[MAXN][MAXN];
char field[MAXN][MAXN+1];
int cntof[MAXN][MAXN];
vector<int> cntsize;

inline bool empty(int y, int x) {
  return 0 <= y && y < n && 0 <= x && x < n && field[y][x] == '.';
}

void dfs(int y, int x) {
  mark[y][x] = true;
  cntof[y][x] = cntsize.size()-1;
  ++cntsize[cntof[y][x]];

  for (int d = 0; d < 4; ++d) {
    int y2 = y + dy[d], x2 = x + dx[d];
    if (empty(y2, x2) && !mark[y2][x2]) {
      dfs(y2, x2);
    }
  }
}

int main() {
  int k;
  scanf("%d %d", &n, &k);

  for (int y = 0; y < n; ++y) {
    scanf("%s", field[y]);
  }

  memset(mark, 0, sizeof(mark));

  for (int y = 0; y < n; ++y)
    for (int x = 0; x < n; ++x)
      if (field[y][x] == '.' && !mark[y][x]) {
	cntsize.push_back(0);
	dfs(y, x);
      }

  vector<int> natcnt(cntsize.size(), 0);
  int nempty = 0, cntsum = 0, result = 0;

  auto add2 = [&](int y, int x) {
    if (empty(y, x) && ++natcnt[cntof[y][x]] == 1) {
      cntsum += cntsize[cntof[y][x]];
    }
  };
  auto add = [&](int y, int x) {
    if (empty(y, x)) ++nempty;
  };
  auto del2 = [&](int y, int x) {
    if (empty(y, x) && --natcnt[cntof[y][x]] == 0) {
      cntsum -= cntsize[cntof[y][x]];
    }
  };
  auto del = [&](int y, int x) {
    if (empty(y, x)) --nempty;
  };

  for (int y = 0; y+k-1 < n; ++y) {
    for (int x = 0; x < n; ++x) {
      add2(y-1, x);
      add2(y+k, x);
      del2(y-1, x-k);
      del2(y+k, x-k);

      for (int y2 = y; y2 < y+k; ++y2) {
	add2(y2, x-1);
	add2(y2, x);
	add2(y2, x+1);

	add(y2, x);
	del(y2, x-k);

	if (x-k >= 0) {
	  del2(y2, x-k-1);
	  del2(y2, x-k);
	  del2(y2, x-k+1);
	}
      }
      if (k-1 <= x) {
	result = max(result, cntsum + (k*k - nempty));
      }
    }

    fill(natcnt.begin(), natcnt.end(), 0);
    nempty = cntsum = 0;
  }

  printf("%d\n", result);

  return 0;
}