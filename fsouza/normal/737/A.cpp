#include <algorithm>
#include <bitset>
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

using namespace std;

typedef long long lint;

lint mintime(const vector<int> &segments, int tank) {
  lint result = 0;
  for (int seg : segments) {
    if (tank < seg)
      return LLONG_MAX;
    if (tank >= 2*seg) {
      result += seg;
    } else {
      int A = tank - seg;
      result += A + 2LL*(seg - A);
    }
  }
  return result;
}

int main() {
  int ncar, ngas, roadlen, maxtime;
  scanf("%d %d %d %d", &ncar, &ngas, &roadlen, &maxtime);

  vector<pair<int, int>> pricetank(ncar);
  for (int i = 0; i < ncar; ++i) {
    int price, tank;
    scanf("%d %d", &price, &tank);
    pricetank[i] = make_pair(price, tank);
  }

  vector<int> gaspos(ngas);
  for (int i = 0; i < ngas; ++i)
    scanf("%d", &gaspos[i]);
  sort(gaspos.begin(), gaspos.end());

  vector<int> segments(ngas+1);
  int lastpos = 0;
  for (int i = 0; i < ngas; ++i) {
    int pos = gaspos[i];
    segments[i] = pos-lastpos;
    lastpos = pos;
  }
  segments.back() = roadlen - lastpos;

  int l = 0, r = 2*roadlen+1;
  while (l < r) {
    int m = l + (r-l)/2;
    if (mintime(segments, m) <= maxtime) r = m;
    else l = m+1;
  }

  int result;
  if (l == 2*roadlen+1) result = -1;
  else {
    result = INT_MAX;
    for (int i = 0; i < ncar; ++i)
      if (pricetank[i].second >= l)
        result = min(result, pricetank[i].first);
    if (result == INT_MAX)
      result = -1;
  }

  printf("%d\n", result);

  return 0;
}