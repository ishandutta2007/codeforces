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

bool first_closer(int x, int y) {
  printf("1 %d %d\n", x + 1, y + 1);
  fflush(stdout);
  char res[3 + 1];
  scanf("%s", res);
  return res[0] == 'T';
}

int find(int a, int b) {
  int size = b - a + 1;
  if (size == 1) {
    return a;
  } else if (size % 2 == 0) {
    int midl = (a + b - 1) / 2;
    int midr = (a + b + 1) / 2;
    if (first_closer(midl, midr)) return find(a, midl);
    else return find(midr, b);
  } else {
    int mid = (a + b) / 2;
    if (first_closer(mid - 1, mid + 1)) return find(a, mid);
    else return find(mid, b);
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  int dish_a = find(0, n-1);
  int dish_b;
  if (dish_a == 0) dish_b = find(1, n-1);
  else if (dish_a == n-1) dish_b = find(0, n-2);
  else {
    int cand0 = find(0, dish_a - 1);
    int cand1 = find(dish_a + 1, n - 1);
    if (first_closer(cand0, cand1)) dish_b = cand0;
    else dish_b = cand1;
  }

  printf("2 %d %d\n", dish_a + 1, dish_b + 1);

  return 0;
}