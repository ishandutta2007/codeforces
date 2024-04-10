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
  mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
  int n, k;
  cin >> n >> k;
  vector <int> c(n * k);
  vector <vector <int>> pos(n);
  for (int i = 0; i < n * k; ++i) {
    cin >> c[i];
    --c[i];
    pos[c[i]].push_back(i);
  }
  vector <int> pref(n * k + 1);
  vector <tuple <int, int, int>> gs;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j + 1 < k; ++j) {
      gs.push_back({pos[i][j], pos[i][j + 1], i});
    }
  }
  vector <int> used(n);
  sort(gs.begin(), gs.end(), [&] (auto f, auto s) {
    return get <1> (f) < get <1> (s);
  });
  vector <pair <int, int>> segs;
  vector <int> al(n), ar(n);
  int cnt = 0;
  while (cnt < n) {
    int lst = -1;
    for (auto t : gs) {
      int l = get <0> (t);
      int r = get <1> (t);
      int tp = get <2> (t);
      if (used[tp] || !(lst < l)) continue;
      ++cnt;
      used[tp] = 1;
      al[tp] = l;
      ar[tp] = r;
      ++pref[l];
      --pref[r + 1];
      lst = r;
    }
  }
  for (int i = 1; i <= n * k; ++i) pref[i] += pref[i - 1];
  bool ok = true;
  for (int i = 0; i <= n * k; ++i) ok &= (pref[i] <= (n + k - 1 - 1) / (k - 1));
  assert(ok);
  for (int i = 0; i < n; ++i) {
    cout << al[i] + 1 << ' ' << ar[i] + 1 << '\n';
  }
}