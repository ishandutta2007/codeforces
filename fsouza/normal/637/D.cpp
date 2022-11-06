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

bool solve(const vector<int> &block, int end, int minrun, int maxjump, bool print = false) {
  int n = block.size();
  int pos = 0;
  if (n > 0) {
    int run0 = block[0]-1 - pos;
    if (run0 < minrun) return false;
    if (run0 > 0) {
      if (print) printf("RUN %d\n", run0);
      pos += run0;
    }

    for (int i = 0; i+1 < n; ++i) {
      int runlen = (block[i+1]-1) - (block[i]+1);
      if (runlen >= minrun && block[i]+1 - pos <= maxjump) {
	int jumplen = block[i]+1 - pos;
	if (jumplen > 0) {
	  if (print) printf("JUMP %d\n", jumplen);
	  pos += jumplen;
	}
	if (runlen > 0) {
	  if (print) printf("RUN %d\n", runlen);
	  pos += runlen;
	}
      }
    }

    int jumplen = block.back()+1 - pos;
    if (jumplen > maxjump) return false;
    if (jumplen > 0) {
      if (print) printf("JUMP %d\n", jumplen);
      pos += jumplen;
    }
  }
  if (pos < end) {
    if (print) printf("RUN %d\n", end-pos);
    pos = end;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, end, minrun, maxjump;
  cin >> n >> end >> minrun >> maxjump;
  vector<int> pos(n);
  for (int &p : pos) cin >> p;
  sort(pos.begin(), pos.end());

  if (solve(pos, end, minrun, maxjump)) solve(pos, end, minrun, maxjump, true);
  else printf("IMPOSSIBLE\n");

  return 0;
}