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
    vector <int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    set <int> gs;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        gs.insert(x[j] - x[i]);
      }
    }
    cout << gs.size() << '\n';
  }
}