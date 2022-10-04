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
    string a, b;
    cin >> a >> b;
    vector <int> ans;
    for (int i = n - 1; i >= 0; --i) {
      if (a[i] == b[i]) continue;
      if (a[0] == b[i]) {
        ans.push_back(0);
        if (a[0] == '0') a[0] = '1';
        else a[0] = '0';
      }
      ans.push_back(i);
      for (int j = 0; j < (i + 1) / 2; ++j) {
        swap(a[j], a[i - j]);
      }
      for (int j = 0; j < i; ++j) {
        if (a[j] == '1') a[j] = '0';
        else a[j] = '1';
      }
    }
    cout << ans.size() << '\n';
    for (int x : ans) cout << x + 1 << ' ';
    cout << endl;
  }
}