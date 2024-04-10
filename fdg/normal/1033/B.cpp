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
  int T;
  cin >> T;
  while (T--) {
    long long a, b;
    cin >> a >> b;
    if (a - b == 1) {
      long long x = a + b, ok = 1;
      for (long long i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
          ok = 0;
          break;
        }
      }
      cout << (ok ? "YES" : "NO") << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}