//  Copyright 2021 Nikita Golikov

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

int const INF = int(1e7);

struct fenwick {
  int n;
  vector<int> a;

  fenwick(int n_) : n(n_), a(n_, INF) {}

  void upd(int at, int value) {
    for (; at < n; at |= at + 1) {
      smin(a[at], value);
    }
  }

  int get(int r) {
    int ans = INF;
    for (; r >= 0; r = (r & (r + 1)) - 1) smin(ans, a[r]);
    return ans;
  }
};

void solve(int) {
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto& x : p) cin >> x, --x;

  int ans = 0;
  for (int it = 0; it < 2; ++it) {
    vector<fenwick> fenwL, fenwR;
    vector<vector<tuple<int, int, int>>> eventsLeft(n), eventsRight(n);
    auto updateLeft = [&](int i, int rightVal, int len) {
      smax(ans, len - (it == 1));
      if (i > 0) {
        eventsLeft[i - 1].emplace_back(len + 1, p[i], rightVal);
      }
      if (i - len >= 0) {
        eventsRight[i - len].emplace_back(len + 1, rightVal, p[i]);
      }
    };
    auto updateRight = [&](int i, int leftVal, int len) {
      smax(ans, len - (it == 1));
      if (i > 0) {
        eventsRight[i - 1].emplace_back(len + 1, p[i], leftVal);
      }
      if (i - len >= 0) {
        eventsLeft[i - len].emplace_back(len + 1, leftVal, p[i]);
      }
    };

    for (int i = n - 1; i >= 0; --i) {
      for (auto[len, bound, rightVal] : eventsLeft[i]) {
        //  < bound, min= rightVal
        while (int(fenwL.size()) <= len) {
          fenwL.emplace_back(n);
        }
        fenwL[len].upd(n - bound, rightVal);
      }
      for (auto[len, bound, leftVal] : eventsRight[i]) {
        //  > bound, max= leftVal
        while (int(fenwR.size()) <= len) {
          fenwR.emplace_back(n);
        }
        fenwR[len].upd(bound + 1, -leftVal);
      }
      if (it == 0) {
        if (i == n - 1) {
          updateLeft(i, p[i], 1);
        }
      } else if (i < n - 1) {
        updateLeft(i, p[i], 2);
        updateRight(i, p[i], 2);
      }
      for (int len = 2; len < int(fenwL.size()); ++len) {
        auto rightVal = fenwL[len].get(n - 1 - p[i]);
        if (rightVal != INF) {
          updateLeft(i, rightVal, len);
        }
      }
      for (int len = 2; len < int(fenwR.size()); ++len) {
        auto leftVal = fenwR[len].get(p[i]);
        if (leftVal != INF) {
          updateRight(i, -leftVal, len);
        }
      }
    }
  }

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