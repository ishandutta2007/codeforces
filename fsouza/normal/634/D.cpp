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

int main() {
  int final, maxtank, n;
  scanf("%d %d %d", &final, &maxtank, &n);
  struct gas_t {
    int pos, price;
    bool operator < (const gas_t &o) const { return pos < o.pos; }
  };
  vector<gas_t> gas(n);
  for (gas_t &g : gas) scanf("%d %d", &g.pos, &g.price);
  sort(gas.begin(), gas.end());

  vector<int> next(n), st;
  for (int i = n-1; i >= 0; --i) {
    while (!st.empty() && gas[st.back()].price >= gas[i].price) st.pop_back();
    if (st.empty()) next[i] = -1;
    else next[i] = st.back();
    st.push_back(i);
  }

  lint result = 0;
  int tank = maxtank - gas[0].pos;
  int id = 0;
  if (tank < 0) {
    printf("-1\n");
    return 0;
  }
  while (id < n) {
    int to = next[id];
    if (to == -1 || gas[to].pos > gas[id].pos + maxtank) {
      if (final <= gas[id].pos + maxtank) {
	int dist = final - gas[id].pos;
	int need = max(0, dist - tank);
	result += (lint)need * gas[id].price;
	tank += need;

	tank -= dist;
	id = n;

	printf("%lld\n", result);
	return 0;
      } else {
	int need = maxtank - tank;
	result += (lint)need * gas[id].price;
	tank += need;

	if (id+1 < n) {
	  int dist = gas[id+1].pos - gas[id].pos;
	  tank -= dist;
	  ++id;
	  if (tank < 0) {
	    printf("-1\n");
	    return 0;
	  }
	} else {
	  printf("-1\n");
	  return 0;
	}
      }
    } else {
      int dist = gas[to].pos - gas[id].pos;
      int need = max(0, dist - tank);
      result += (lint)need * gas[id].price;
      tank += need;

      id = to;
      tank -= dist;
    }
  }

  printf("-1\n");

  return 0;
}