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
 
struct Seg {
  int l, r, i;
  bool operator <(const Seg &other) const {
    if (r != other.r) return r < other.r;
    return l < other.l;
  }
};

const int N = 2e5 + 7;
pair <int, int> t[4 * N];

void modify(int id, pair <int, int> val, int l, int r, int v) {
  if (l == r) {
    t[v] = val;
  } else {
    int m = (l + r) >> 1;
    if (id <= m) modify(id, val, l, m, 2 * v + 1);
    else modify(id, val, m + 1, r, 2 * v + 2);
    t[v] = max(t[2 * v + 1], t[2 * v + 2]);
  }
}

pair <int, int> get(int ql, int qr, int l, int r, int v) {
  if (qr < l || r < ql) return {-1, -1};
  if (ql <= l && r <= qr) return t[v];
  int m = (l + r) >> 1;
  return max(get(ql, qr, l, m, 2 * v + 1), get(ql, qr, m + 1, r, 2 * v + 2));
} 

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  for (int i = 0; i < 4 * N; ++i) t[i] = {-1, -1};
  int n;
  cin >> n;
  vector <Seg> s;
  set <int> fr;
  for (int i = 0; i < n; ++i) fr.insert(i);
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    s.push_back({l, r, i});
  }
  sort(s.begin(), s.end());
  vector <int> ans1(n), ans2(n);
  bool fnd = false;
  for (auto sg : s) {
    auto it = fr.lower_bound(sg.l);
    int i = sg.i;
    int x = *it;
    ans1[i] = x;
    ans2[i] = x;
    fr.erase(it);
    if (!fnd && get(sg.l, x, 0, n - 1, 0).first >= x) {
      fnd = true;
      int id = get(sg.l, x, 0, n - 1, 0).second;
      swap(ans2[id], ans2[i]);
    }
    modify(x, make_pair(sg.r, i), 0, n - 1, 0);
  }
  if (fnd) {
    cout << "NO\n";
    for (int i = 0; i < n; ++i) cout << ans1[i] + 1 << ' ';
    cout << '\n';
    for (int i = 0; i < n; ++i) cout << ans2[i] + 1 << ' ';
    cout << '\n';
  } else {
    cout << "YES\n";
    for (int i = 0; i < n; ++i) cout << ans1[i] + 1 << ' ';
    cout << '\n';
  }
}