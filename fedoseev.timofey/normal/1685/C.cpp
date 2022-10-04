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
    int n;
    cin >> n;
    n *= 2;
    string s;
    cin >> s;
    vector<int> b = {0};
    int bal = 0;
    bool ok = true;
    for (auto c : s) {
      if (c == '(') ++bal;
      else --bal;
      b.push_back(bal);
      if (bal < 0) ok = false;
    }
    if (ok) {
      cout << "0\n";
      continue;
    }
    int lf = n, rg = 0;
    for (int i = 0; i <= n; ++i) {
      if (b[i] < 0) {
        lf = min(lf, i - 1);
        rg = max(rg, i + 1);
      }
    }
    int mx = 0;
    for (int i = lf; i <= rg; ++i) mx = max(mx, b[i]);
    vector<pair<int, int>> pos;
    for (int i = 0; i <= n; ++i) pos.push_back({b[i], i});
    sort(pos.begin(), pos.end());
    vector<int> have(n + 1);
    int l = lf, r = rg;
    pair<int, int> max_r = make_pair(0, rg);
    pair<int, int> max_l = make_pair(0, lf);
    bool fnd = false;
    for (auto p : pos) {
      have[p.second] = 1;
      while (l > 0 && have[l - 1]) {
        --l;
        max_l = max(max_l, make_pair(b[l], l));
      }
      while (r + 1 <= n && have[r + 1]) {
        ++r;
        max_r = max(max_r, make_pair(b[r], r));
      }
      if (p.first >= mx && max_l.first + max_r.first >= p.first) {
        cout << 1 << '\n';
        cout << max_l.second + 1 << ' ' << max_r.second << '\n';
        fnd = true;
        break;
      }
    }
    if (!fnd) {
      int id = 0;
      for (int i = 0; i <= n; ++i) if (b[i] > b[id]) id = i;
      cout << 2 << '\n';
      cout << 1 << ' ' << id << '\n';
      cout << id + 1 << ' ' << n << '\n';
    }
  }
}