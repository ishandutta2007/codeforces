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

#define INF 2000000000

using namespace std;

typedef long long lint;

const int maxv = 1e9;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> vals(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &vals[i]);
  vals.push_back(maxv+1);
  ++n;

  int m;
  scanf("%d", &m);
  vector<int> fillers(m);
  for (int i = 0; i < m; ++i)
    scanf("%d", &fillers[i]);
  sort(fillers.begin(), fillers.end());

  struct prev_t {
    int pos, nskip;
  };
  vector<prev_t> previous(n);
  struct end_t {
    int value;
    prev_t prev;
  };
  vector<end_t> bestend(n+1, end_t{INF, prev_t{-2, 0}});
  bestend[0] = end_t{-INF, prev_t{-1, 0}};

  for (int i = 0; i < n; ++i) {
    if (vals[i] != -1) {
      int size = lower_bound(bestend.begin(), bestend.end(),
			     end_t{vals[i], prev_t{-1, 0}},
			     [](const end_t &a, const end_t &b) {
			       return a.value < b.value;
			     }) - bestend.begin();
      previous[i] = bestend[size-1].prev;
      bestend[size] = end_t{vals[i], prev_t{i, 0}};
    } else {
      int size = bestend.size();
      for (int j = m-1; j >= 0; --j) {
	int value = fillers[j];
	while (size-1 >= 0 && bestend[size-1].value >= value) --size;
	prev_t prev = bestend[size-1].prev;
	++prev.nskip;
	bestend[size] = end_t{value, prev};
      }
    }
  }

  int k = (int)fillers.size()-1;
  for (int i = n-1; i != -1; i = previous[i].pos) {
    int remain = previous[i].nskip;
    int maxval = vals[i]-1;
    for (int j = i; j >= previous[i].pos && remain > 0; --j)
      if (vals[j] == -1) {
	while (fillers[k] > maxval) --k;
	vals[j] = fillers[k];
	maxval = vals[j]-1;
	swap(fillers[k], fillers.back());
	fillers.pop_back();
	--k;
	--remain;
      }
  }

  for (int i = 0; i < n; ++i)
    if (vals[i] == -1) {
      vals[i] = fillers.back();
      fillers.pop_back();
    }

  for (int i = 0; i < n-1; ++i) {
    if (i > 0) printf(" ");
    printf("%d", vals[i]);
  }
  printf("\n");

  return 0;
}