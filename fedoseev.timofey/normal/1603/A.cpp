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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int dead = 0;
    for (int i = 0; i < n; ++i) {
      int x = i + 2;
      bool ok = false;
      for (int j = x; j >= x - dead; --j) {
        if (a[i] % j != 0) {
          ok = true;
          break;
        }
      }
      if (ok) {
        ++dead;
      } else {
        break;
      }
    }
    if (dead == n) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}