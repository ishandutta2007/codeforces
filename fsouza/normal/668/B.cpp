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
  int n, nq;
  scanf("%d %d", &n, &nq);

  vector<int> even;
  int deltae = 0;
  vector<int> odd;
  int deltao = 0;

  for (int i = 0; i < n; ++i)
    if (i%2 == 0) even.push_back(i);
    else odd.push_back(i);

  for (int q = 0; q < nq; ++q) {
    int kind;
    scanf("%d", &kind);
    if (kind == 1) {
      int value;
      scanf("%d", &value);
      value = (n + value) % n;
      deltae += value/2; deltae %= (n/2);
      deltao += value/2; deltao %= (n/2);
      if (value%2 == 1) {
	swap(even, odd);
	swap(deltae, deltao);
	++deltae; deltae %= (n/2);
      }
    } else {
      swap(even, odd);
      swap(deltae, deltao);
    }
  }

  rotate(even.begin(), even.begin() + ((-deltae)%(n/2) + (n/2)) % (n/2), even.end()); deltae = 0;
  rotate(odd.begin(), odd.begin() + ((-deltao)%(n/2) + (n/2)) % (n/2), odd.end()); deltao = 0;

  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    if (i%2 == 0) printf("%d", even[i/2]+1);
    else printf("%d", odd[i/2]+1);
  }
  printf("\n");

  return 0;
}