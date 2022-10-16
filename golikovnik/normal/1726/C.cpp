//  Copyright 2022 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

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

void solveTest() {
  int n; cin >> n;
  vector<vector<int>> byBal(2 * n + 1);
  vector<int> bal(2 * n + 1);
  int b = 0;
  byBal[0].push_back(0);
  for (int i = 0; i < 2 * n; ++i) {
    char c; cin >> c;
    if (c == '(') {
      ++b;
    } else {
      --b;
    }
    assert(b >= 0);
    bal[i + 1] = b;
    byBal[b].push_back(i + 1);
  }
  int ans = 0;

  auto solve = [&](auto&& self, int l, int r) -> void {
    if (l >= r) {
      return;
    }
    ++ans;
    int p = l;
    for (auto it = upper_bound(byBal[bal[l]].begin(), byBal[bal[l]].end(), l); it != byBal[bal[l]].end(); ++it) {
      if (*it > r) {
        return;
      }
      self(self, p + 1, *it - 1);
      p = *it;
    }
  };

  solve(solve, 0, 2 * n);

  cout << ans << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _tests;
  cin >> _tests;
  for (int tt_ = 1; tt_ <= _tests; ++tt_) {
    solveTest();
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}