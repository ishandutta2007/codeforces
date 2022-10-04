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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> ans;
    ans.push_back(0);
    for (int i = 1; i < n - 1; ++i) {
      if (a[i - 1] < a[i] && a[i] < a[i + 1]) continue;
      if (a[i - 1] > a[i] && a[i] > a[i + 1]) continue;
      ans.push_back(i);
    }
    ans.push_back(n - 1);
    cout << ans.size() << '\n';
    for (int id : ans) {
      cout << a[id] << ' ';
    }
    cout << '\n';
  }
}