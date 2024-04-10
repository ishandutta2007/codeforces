#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> q;
  for (int i = 0; i < n; ++i) {
    q.push_back(1);
    while (q.size() > 1 && q.back() == q[q.size() - 2]) {
      int k = q.back() + 1;
      q.pop_back();
      q.pop_back();
      q.push_back(k);
    }
  }
  for (int x : q) {
    printf("%d ", x);
  }
  printf("\n");
  return 0;
}