#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int x[102] = {0};

int main() {
  int n, a;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    x[a]++;
  }
  while (true) {
    bool found = false;
    for (int i = 100; i > 0; --i)
      if (x[i] > x[i - 1]) {
        found = true;
        int d = (x[i] - x[i - 1] + 1) / 2;
        x[i] -= d;
        x[i - 1] += d; 
      }
    if (!found) break;
  }
  cout << x[0] << endl;
  return 0;
}