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
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

bool reach(int from[3], int to[3], vector<vector<string>> &works) {
  if (works[from[0]][from[1]][from[2]] == '0') return false;
  if (from[0] == to[0] && from[1] == to[1] && from[2] == to[2]) return true;
  for (int d = 0; d < 3; ++d)
    if (from[d] < to[d]) {
      ++from[d];
      bool res = reach(from, to, works);
      --from[d];
      if (res) return true;
    }
  return false;
}

int main() {
  int lim[3];
  for (int i = 0; i < 3; ++i) scanf("%d", &lim[i]);

  vector<vector<string>> works(lim[0], vector<string>(lim[1], string(lim[2], ' ')));
  for (int i = 0; i < lim[0]; ++i)
    for (int j = 0; j < lim[1]; ++j)
      scanf("%s", &works[i][j][0]);

  int result = 0;
  for (int i = 0; i < lim[0]; ++i)
    for (int j = 0; j < lim[1]; ++j)
      for (int k = 0; k < lim[2]; ++k)
	if (works[i][j][k] == '1') {
	  int at[3] = {i, j, k};
	  bool critical = false;

	  for (int fromd = 0; fromd < 3; ++fromd)
	    if (at[fromd] >= 1) {
	      int from[3] = {i, j, k};
	      --from[fromd];
	      for (int tod = 0; tod < 3; ++tod)
		if (at[tod]+1 < lim[tod]) {
		  int to[3] = {i, j, k};
		  ++to[tod];
		  bool before = reach(from, to, works);
		  works[i][j][k] = '0';
		  bool after = reach(from, to, works);
		  works[i][j][k] = '1';
		  if (before && !after) critical = true;
		}
	    }

	  if (critical) ++ result;
	}
  printf("%d\n", result);

  return 0;
}