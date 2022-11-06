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

lint dist(int from, int to, int c5, int c1) {
  lint delta = to-from;
  if (5*c1 <= c5) {
    return delta * c1;
  } else {
    return (delta/5) * c5 + (delta%5) * c1;
  }
}

int mod(int a, int b) { return (a%b + b) % b; }

int main() {
  int n, k, xb, xc;
  scanf("%d %d %d %d", &n, &k, &xb, &xc);
  vector<int> vals[5], cands[5];

  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    vals[mod(v,5)].push_back(v);
    for (int j = 0; j < 5; ++j)
      cands[mod(v+j, 5)].push_back(v+j);
  }

  for (int j = 0; j < 5; ++j) {
    sort(vals[j].begin(), vals[j].end());
    sort(cands[j].begin(), cands[j].end());
    cands[j].resize(unique(cands[j].begin(), cands[j].end()) - cands[j].begin());
  }
  lint result = LLONG_MAX;

  for (int cj = 0; cj < 5; ++cj) {
    int nhave = 0;
    lint cost = 0;
    int left[5] = {0, 0, 0, 0, 0}, right[5] = {0, 0, 0, 0, 0};

    for (int ci = 0; ci < (int)cands[cj].size(); ++ci) {
      int cand = cands[cj][ci];

      if (ci > 0) {
	lint extrab = (cands[cj][ci] - cands[cj][ci-1]) / 5;
	lint c1 = xc, c5 = xb;
	if (5*c1 <= c5) cost += (lint)nhave * 5 * c1 * extrab;
	else cost += (lint)nhave * c5 * extrab;
      }

      for (int j = 0; j < 5; ++j) {
	while (right[j] < (int)vals[j].size()) {
	  int v = vals[j][right[j]];
	  if (v <= cand) {
	    ++nhave;
	    cost += dist(v, cand, xb, xc);
	    ++right[j];
	  } else break;
	}
      }

      while (nhave > k) {
	int worst = -1;
	lint worstv = LLONG_MIN;
	for (int j = 0; j < 5; ++j)
	  if (left[j] < right[j]) {
	    int v = vals[j][left[j]];
	    lint d = dist(v, cand, xb, xc);
	    if (d > worstv) {
	      worstv = d;
	      worst = j;
	    }
	  }
	--nhave;
	cost -= worstv;
	++left[worst];
      }

      if (nhave == k) result = min(result, cost);
    }
  }

  cout << result << endl;

  return 0;
}