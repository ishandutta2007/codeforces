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
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    bool ok = true;
    if (n % 2 == 1 && a[n / 2] != b[n / 2]) ok = false;
    map <pair <int, int>, int> cnt;
    for (int i = 0; i < n / 2; ++i) {
      ++cnt[{min(a[i], a[n - i - 1]), max(a[i], a[n - i - 1])}];
    }
    for (int i = 0; i < n / 2; ++i) {
      if (cnt[{min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1])}] == 0){
        ok = false;
      }
      --cnt[{min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1])}];
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
}