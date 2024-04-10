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
  vector<pair<int, int>> people(n);
  for (int i = 0; i < n; ++i) {
    int money;
    scanf("%d", &money);
    people[i] = make_pair(money + i, money);
  }
  sort(people.begin(), people.end());
  bool ok = true;
  for (int i = 0; i+1 < n; ++i)
    if (people[i].first == people[i+1].first) {
      ok = false;
      break;
    }
  if (!ok) printf(":(\n");
  else {
    for (int i = 0; i < n; ++i) {
      int newmoney = people[i].first - i;
      if (i > 0) printf(" ");
      printf("%d", newmoney);
    }
    printf("\n");
  }

  return 0;
}