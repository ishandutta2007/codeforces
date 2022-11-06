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
  int n;
  scanf("%d", &n);
  struct child_t {
    int c, v, d;
  };
  vector<child_t> children(n);
  for (child_t &child : children)
    scanf("%d %d %d", &child.v, &child.d, &child.c);

  vector<bool> active(n, true);
  queue<int> running;
  vector<int> result;
  for (int i = 0; i < n; ++i)
    if (active[i]) {
      result.push_back(i);
      int value = children[i].v;
      for (int j = i+1; j < n; ++j)
	if (active[j]) {
	  children[j].c -= value;
	  if (children[j].c < 0) {
	    active[j] = false;
	    running.push(j);
	  }
	  --value;
	  if (value <= 0) break;
	}
      while (!running.empty()) {
	int j = running.front(); running.pop();
	for (int k = j+1; k < n; ++k)
	  if (active[k]) {
	    children[k].c -= children[j].d;
	    if (children[k].c < 0) {
	      active[k] = false;
	      running.push(k);
	    }
	  }
      }
    }

  printf("%d\n", (int)result.size());
  for (int i = 0; i < (int)result.size(); ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i]+1);
  }
  printf("\n");

  return 0;
}