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
  int n, k;

  scanf("%d %d", &n, &k);

  vector<int> ret;

  int now = 0;
  int dir = 1;
  
  ret.push_back(now);
  for (int i = 0; i < k; i++) {
    if (dir == 1) {
      now += (i+1);
      ret.push_back(now);
      dir = 0;
    } else {
      now -= (i+1);
      ret.push_back(now);
      dir = 1;
    }
  }

  while ((int)ret.size() < n) {
    if (dir == 0) {
      now++;
      ret.push_back(now);
    } else {
      now--;
      ret.push_back(now);
    }
  }

  int delta = -*min_element(ret.begin(), ret.end()) + 1;

  for (int i = 0; i < (int)ret.size(); i++) {
    ret[i] += delta;
    if (i-1 >= 0) printf(" ");
    printf("%d", ret[i]);
  }
  printf("\n");

  return 0;
}