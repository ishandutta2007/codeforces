#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (n > a * b) {
    cout << -1 << endl;
    return 0;
  }
  int arr[102][102] = {0};
  for (int i = 0; i < a; ++i) {
    if (i & 1) {
      for (int j = b - 1; j >= 0 && n; --j)
        arr[i][j] = n--;
    } else {
      for (int j = 0; j < b && n; ++j)
        arr[i][j] = n--;
    }
  }
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}