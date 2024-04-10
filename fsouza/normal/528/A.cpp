#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <numeric>
#include <cassert>
#include <cmath>

typedef long long lint;

using namespace std;

struct st {
  set<int> pos;
  multiset<int> sizes;
  
  st(int a, int b) {
    pos.insert(a);
    pos.insert(b);
    sizes.insert(b - a);
  }
  void add(int v) {
    if (pos.find(v) != pos.end()) return;
    
    pos.insert(v);
    set<int>::iterator it = pos.find(v), it2, it3;
    it2 = it; it2--;
    it3 = it; it3++;
    
    sizes.erase(sizes.find(*it3 - *it2));
    sizes.insert(*it - *it2);
    sizes.insert(*it3 - *it);
  }

  lint maxv() {
    return *sizes.rbegin();
  }
};

int main() {
  int w, h, n;

  scanf("%d %d %d", &w, &h, &n);

  st sw(0, w);
  st sh(0, h);

  for (int i = 0; i < n; i++) {
    char op;
    int pos;
    scanf(" %c %d", &op, &pos);

    if (op == 'H') sh.add(pos);
    else sw.add(pos);

    lint ret = sw.maxv() * sh.maxv();

    printf("%I64d\n", ret);
  }
  
  return 0;
}