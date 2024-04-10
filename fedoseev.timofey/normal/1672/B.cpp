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
    string s;
    cin >> s;
    int n = s.size();
    bool ok = true;
    if (s[0] == 'B') ok = false;
    if (s[n - 1] != 'B') ok = false;
    if (n < 2) ok = false;
    int bal = 0;
    for (auto c : s) {
      if (c == 'A') ++bal;
      if (c == 'B') --bal;
      if (bal < 0) ok = false;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}