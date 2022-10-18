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
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << a + b + c - 1 << endl;
  }
  return 0;
}