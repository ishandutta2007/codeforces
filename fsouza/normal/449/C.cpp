#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  int n;

  scanf("%d", &n);

  vector<bool> prime(n+1, true), used(n+1, false);
  vector< pair<int,int> > ret;

  for (int v = 2; v <= n; v++)
    if (prime[v]) {
      for (int j = v+v; j <= n; j += v)
	prime[j] = false;
      
      if (v != 2) {
	int last = -1;
	for (int j = v; j <= n; j += v)
	  if (j != 2*v) {
	    if (!used[j]) {
	      if (last == -1) last = j;
	      else {
		ret.push_back(make_pair(last, j));
		used[last] = used[j] = true;
		last = -1;
	      }
	    }
	  }
	if (last != -1 && 2*v <= n) {
	  ret.push_back(make_pair(last, 2*v));
	  used[last] = used[2*v] = true;
	  last = -1;
	}
      }
    }

  if (2 <= n) {
    const int v = 2;
    int last = -1;
    for (int j = v; j <= n; j += v)
      if (!used[j]) {
	if (last == -1) last = j;
	else {
	  ret.push_back(make_pair(last, j));
	  used[last] = used[j] = true;
	  last = -1;
	}
      }
  }

  printf("%d\n", (int)ret.size());
  for (auto group : ret)
    printf("%d %d\n", group.first, group.second);
  
  return 0;
}