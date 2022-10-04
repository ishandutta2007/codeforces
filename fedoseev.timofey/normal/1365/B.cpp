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
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    set <int> who;
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
      who.insert(b[i]);
    }
    bool ok = ((int)who.size() == 2 || is_sorted(a.begin(), a.end()));
    cout << (ok ? "Yes" : "No") << '\n';
  }
}