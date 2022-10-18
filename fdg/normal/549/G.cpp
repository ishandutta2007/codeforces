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
  scanf("%d", &n);
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    v.push_back(a + i);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i + 1 < v.size(); ++i) {
    if (v[i] == v[i + 1]) {
      puts(":(");
        return 0;
    }
  }
  for (int i = 0; i < v.size(); ++i)
    printf("%d ", v[i] - i);
  printf("\n");
  return 0;
}