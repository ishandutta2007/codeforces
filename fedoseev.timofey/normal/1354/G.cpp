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
#include <chrono>

using namespace std;

typedef long long ll;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    auto ask = [] (vector <int> a, vector <int> b) {
      cout << "? " << a.size() << ' ' << b.size() << endl;
      for (int i : a) cout << i + 1 << ' ';
      cout << endl;
      for (int i : b) cout << i + 1 << ' ';
      cout << endl;
      string s;
      cin >> s;
      if (s == "FIRST") return 1;
      if (s == "EQUAL") return 0;
      if (s == "SECOND") return -1;
      exit(1);
    };
    function <vector <int>(int, int)> get = [&] (int l, int r) {
      vector <int> a;
      for (int i = l; i < r; ++i) a.push_back(i);
      return a;
    };
    bool ok = false;
    for (int i = 0; i < 27; ++i) {
      int id = 1 + rnd() % (n - 1);
      if (ask({0}, {id}) == -1) {
        ok = true;
        break;
      }
    }
    if (ok) {
      cout << "! 1" << endl;
      continue;
    } 
    int sz = 1;
    while (2 * sz <= n) {
      if (ask(get(0, sz), get(sz, 2 * sz)) == 0) {
        sz *= 2;
      } else {
        break;
      }
    }
    int l = sz - 1, r = min(n - 1, 2 * sz - 1);
    while (r - l > 1) {
      int m = (l + r) >> 1;
      int cnt = m - (sz - 1);
      if (ask(get(0, cnt), get(sz, sz + cnt)) == 0) l = m;
      else r = m;
    }
    cout << "! " << r + 1 << endl;
  }
}