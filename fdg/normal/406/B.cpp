#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

const int S = 1000000;
bool used[1000006];
vector<int> v;

int main() {
  int n, a;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    used[a] = true;
  }
  v.reserve(500000);
  int need = 0;
  for (int i = 1; i <= 500000; ++i) {
    if (used[i] && used[S - i + 1]) ++need;
    else {
      if (used[i]) v.push_back(S - i + 1);
      else if (used[S - i + 1]) v.push_back(i);
    }
  }
  for (int i = 1; i <= 500000 && need; ++i) {
    if (!used[i] && !used[S - i + 1]) {
      --need;
      v.push_back(i);
      v.push_back(S - i + 1);
    }
  }
  sort(v.begin(), v.end());
  printf("%d\n", (int)v.size());
  for (int i = 0; i < (int)v.size(); ++i) {
    if (i) printf(" ");
    printf("%d", v[i]);
  }
  printf("\n");
  return 0;
}