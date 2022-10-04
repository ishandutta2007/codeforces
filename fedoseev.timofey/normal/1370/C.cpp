#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

bool prime(int x) {
  for (int d = 2; d * d <= x; ++d) if (x % d == 0) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "FastestFinger\n";
    } else {
      if (n % 2 == 1) {
        cout << "Ashishgup\n";
      } else {
        int cnt = 0;
        while (n % 2 == 0) {
          n /= 2;
          ++cnt;
        }
        if (n == 1) {
          if (cnt == 1) {
            cout << "Ashishgup\n";
          } else {
            cout << "FastestFinger\n";
          }
        } else {
          if (cnt > 1) {
            cout << "Ashishgup\n";
          } else {
            if (prime(n)) {
              cout << "FastestFinger\n";
            } else {
              cout << "Ashishgup\n";
            }
          }
        }
      }
    }
  }
}