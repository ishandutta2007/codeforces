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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> have;
  vector<pair<int, int>> ans;
  auto do_merge = [&](auto& x, auto& y) {
    assert(x.size() == y.size());
    vector<int> res(x.size() + y.size());
    for (int i = 0; i < (int) x.size(); ++i) {
      ans.emplace_back(x[i], y[i]);
      res[2 * i] = x[i];
      res[2 * i + 1] = y[i];
    }
    return res;
  };
  auto reduce = [&]() {
    while (have.size() > 1) {
      auto& last = have.back();
      auto& plast = have[have.size() - 2];
      if (last.size() != plast.size()) break;
      auto nw = do_merge(last, plast);
      have.pop_back();
      have.pop_back();
      have.emplace_back(move(nw));
    }
  };
  for (int i = 0; i < n; ++i) {
    have.emplace_back();
    have.back().push_back(i);
    reduce();
  }
  while (have.size() > 2) {
    auto y = have.back().size();
    auto it = have[0].end() - y;
    have.emplace_back(it, have[0].end());
    have[0].erase(it, have[0].end());
    reduce();
  }
  cout << ans.size() << '\n';
  for (auto[x, y] : ans) {
    cout << x + 1 << ' ' << y + 1 << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}