#include <algorithm>
#include <array>
#include <bitset>
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
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int cur_answer = n;
  vector<int> nbigger(n, 0);

  auto add_friendship = [&](int a, int b) {
    if (a > b) swap(a, b);
    cur_answer -= (nbigger[a] == 0);
    nbigger[a] += 1;
    cur_answer += (nbigger[a] == 0);
  };
  auto del_friendship = [&](int a, int b) {
    if (a > b) swap(a, b);
    cur_answer -= (nbigger[a] == 0);
    nbigger[a] -= 1;
    cur_answer += (nbigger[a] == 0);
  };

  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    add_friendship(a, b);
  }
  int nq;
  scanf("%d", &nq);
  for (int q = 0; q < nq; ++q) {
    int kind;
    scanf("%d", &kind);
    if (kind == 1) {
      int a, b;
      scanf("%d %d", &a, &b), --a, --b;
      add_friendship(a, b);
    } else if (kind == 2) {
      int a, b;
      scanf("%d %d", &a, &b), --a, --b;
      del_friendship(a, b);
    } else {
      printf("%d\n", cur_answer);
    }
  }
  return 0;
}