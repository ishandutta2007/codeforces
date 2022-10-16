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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<set<char>> st(k);
  for (int i = 0; i < n; ++i) {
    auto x = s[i];
    if (x != '?') {
      st[i % k].insert(x);
    }
  }
  for (int i = 0; i < k; ++i) {
    if (st[i].size() == 2) {
      cout << "NO\n";
      return;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (!st[i % k].empty()) {
      s[i] = *st[i % k].begin();
    }
  }
  vector<int> cnt(2);
  for (int i = 0; i < k; ++i) {
    if (s[i] != '?') {
      ++cnt[s[i] - '0'];
    }
  }
  for (int i = 0; i < k; ++i) {
    if (s[i] == '?') {
      if (cnt[0] < cnt[1]) {
        s[i] = '0';
        ++cnt[0];
        st[i].insert('0');
      } else {
        s[i] = '1';
        ++cnt[1];
        st[i].insert('1');
      }
    }
  }
  if (cnt[0] != cnt[1]) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
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