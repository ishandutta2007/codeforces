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
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  while (true) {
    int ok = 1;
    for (int i = 0; i < n; ++i) {
      ok &= (a[i] % 2 == 0);
    }
    if (ok) {
      for (int i = 0; i < n; ++i) a[i] /= 2;
    } else {
      break;
    }
  }
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
  }
  if (sum % 2 == 1) {
    cout << "0\n";
  } else {
    bitset <2007 * 100> can;
    can[0] = 1;
    for (auto x : a) {
      can |= can << x;
    }
    if (can[sum / 2] == 0) {
      cout << "0\n";
    } else {
      for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 1) {
          cout << "1\n" << i + 1 << '\n';
          return 0;
        }
      }
      assert(false);
    }
  }
}