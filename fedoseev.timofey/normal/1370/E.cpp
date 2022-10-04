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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      a.push_back(s[i] - '0');
    }
  }   
  n = a.size();
  int sum = 0;
  for (int i = 0; i < n; ++i) sum += a[i];
  if (2 * sum != n) {
    cout << "-1\n";
    return 0;
  }
  int ans = 0;
  int ca = 0, cb = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      if (cb > 0) {
        --cb;
        ++ca;
      } else {
        ++ca;
        ++ans;
      }
    } else {
      if (ca > 0) {
        --ca;
        ++cb;
      } else {
        ++cb;
        ++ans;
      }
    }
  }
  cout << ans << '\n';
}