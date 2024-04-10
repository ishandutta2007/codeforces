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
  int n;
  cin >> n;
  auto ask = [&] (int v) {
    cout << "? " << v + 1 << endl;
    vector <int> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i];
    return d;
  };
  vector <int> c(n);
  vector <int> cnt(2);
  auto st = ask(0);
  for (int i = 0; i < n; ++i) {
    c[i] = st[i] % 2;
    ++cnt[c[i]];
  }
  int cl = -1;
  if (cnt[0] <= cnt[1]) {
    cl = 0;
  } else {
    cl = 1;
  }
  vector <pair <int, int>> ans;
  for (int i = 0; i < n; ++i) {
    if (c[i] == cl) {
      vector <int> d;
      if (i == 0) d = st;
      else d = ask(i);
      for (int j = 0; j < n; ++j) {
        if (d[j] == 1) {
          ans.push_back({i, j});
        }
      }
    }
  }
  cout << "!" << endl;
  for (auto p : ans) {
    cout << p.first + 1 << ' ' << p.second + 1 << endl;
  }
}