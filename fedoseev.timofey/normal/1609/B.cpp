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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int cnt = 0;
  auto check = [&](int i) {
    if (0 <= i && i < n && s[i] == 'a' && 0 <= i + 1 && i + 1 < n && s[i + 1] == 'b' && 0 <= i + 2 && i + 2 < n && s[i + 2] == 'c') {
      return true;
    } else {
      return false;
    }
  };
  for (int i = 0; i < n; ++i) if (check(i)) ++cnt;
  while (q--) {
    int pos; char c;
    cin >> pos >> c;
    --pos;
    for (int i = pos - 3; i <= pos + 3; ++i) if (check(i)) --cnt;
    s[pos] = c;
    for (int i = pos - 3; i <= pos + 3; ++i) if (check(i)) ++cnt;
    cout << cnt << '\n';
  }
}