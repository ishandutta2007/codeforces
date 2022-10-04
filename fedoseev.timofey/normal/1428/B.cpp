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
    string s;
    cin >> s;
    set <char> have;
    for (auto c : s) {
      if (c != '-') {
        have.insert(c);
      }
    }
    if ((int)have.size() <= 1) {
      cout << n << '\n';
      continue;
    }
    vector <int> good(n);
    for (int i = 0; i < n; ++i) {
      if (s[i] == '-') {
        good[i] = 1;
        good[(i + 1) % n] = 1;
      }
    }
    int ans = 0;
    for (int x : good) ans += x;
    cout << ans << '\n';
  }
}