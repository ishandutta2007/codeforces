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
  vector <int> a(n), b(n);
  vector <int> pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    --b[i];
    pos[b[i]] = i;
  }
  map <int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int j = pos[a[i]];
    ++cnt[(j - i + n) % n];
  }
  int ans = 0;
  for (auto p : cnt) ans = max(ans, p.second);
  cout << ans << '\n';
}