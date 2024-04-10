//  Copyright 2020 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

void solve(int) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  auto it = find(s.begin(), s.end(), 'L' ^ 'R' ^ s[0]);
  if (it == s.end()) {
    cout << (n + 2) / 3 << '\n';
    return;
  }
  rotate(s.begin(), it, s.end());
  vector<int> blocks;
  int c = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i - 1]) {
      blocks.push_back(c);
      c = 0;
    }
    ++c;
  }
  if (s[0] == s.back()) {
    blocks[0] += c;
  } else {
    blocks.push_back(c);
  }
  int ans = 0;
  for (auto x : blocks) ans += x / 3;
  cout << ans << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;
  for (int _tt = 1; _tt <= tests; ++_tt) {
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}