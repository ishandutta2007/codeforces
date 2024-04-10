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
  int n, m;
  cin >> n >> m;
  vector <int> l(m);
  ll sum = 0;
  for (int i = 0; i < m; ++i) {
    cin >> l[i];
    sum += l[i];
  }
  if (sum < n) {
    cout << "-1\n";
    return 0;
  }
  vector <int> ans(m);
  for (int i = 0; i < m; ++i) {
    ans[i] = i;
    if (i + l[i] > n) {
      cout << "-1\n";
      return 0;
    }
  }
  int lend = n;
  for (int i = m - 1; i >= 0; --i) {
    if (ans[i] + l[i] < lend) {
      ans[i] = lend - l[i];
    } else {
      break;
    }
    lend = ans[i];
  } 
  for (int i = 0; i < m; ++i) {
    cout << ans[i] + 1 << ' ';
  }
}