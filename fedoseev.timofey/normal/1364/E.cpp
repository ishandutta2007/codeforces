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
  int n;
  cin >> n;
  auto ask = [&] (int i, int j) {
    assert(i != j);
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    int x;
    cin >> x;
    return x;
  };

  vector <int> have;
  for (int i = 0; i < n; ++i) {
    have.push_back(i);
  }

  shuffle(have.begin(), have.end(), rnd);

  int all = 0;
  for (int i = 0; i < n; ++i) all |= i;

  auto get = [&] (int id) {
    int ret = all;
    for (int tt = 0; tt < min(28, (int)have.size()); ++tt) {
      if (id != have[tt]) {
        int cur = ask(id, have[tt]);
        ret &= cur;
      }
    }
    return ret;
  };

  vector <int> gs(n);
  iota(gs.begin(), gs.end(), 0);
  shuffle(gs.begin(), gs.end(), rnd);
  int id = gs[0], x = get(gs[0]);
  for (int i = 1; i < (int)gs.size(); ++i) {
    if (ask(id, gs[i]) == x) {
      id = gs[i];
      x = get(gs[i]);
    }
  }
  assert(x == 0);
  vector <int> ans(n);
  for (int i = 0; i < n; ++i) {
    if (i == id) ans[i] = 0;
    else ans[i] = ask(id, i);
  }
  cout << "! ";
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
}