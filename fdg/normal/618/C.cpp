#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int x[100005], y[100005];

long long dist(int i, int j) {
  return 1LL * (x[i] - x[j]) * (x[i] - x[j]) + 1LL * (y[i] - y[j]) * (y[i] - y[j]);
}

long long dist(int i, int j, int t) {
  long long A = y[j] - y[i], B = x[i] - x[j], C = -A * x[i] - B * y[i];
  long long d = A * x[t] + B * y[t] + C;
  return d > 0 ? d : -d;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
  }

  int ind = 1;
  for (int i = 2; i < n; ++i) {
    if (dist(0, ind) > dist(0, i)) ind = i;
  }

  int ind2 = -1;
  for (int i = 1; i < n; ++i) {
    if (dist(0, ind, i) > 0 && (ind2 == -1 || dist(0, ind, ind2) > dist(0, ind, i)))
      ind2 = i;
  }

  cout << 1 << " " << ind + 1 << " " << ind2 + 1 << endl;

  return 0;
}