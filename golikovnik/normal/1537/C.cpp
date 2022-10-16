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

void solve(int) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());

  if (n == 2) {
    cout << a[0] << ' ' << a[1] << '\n';
    return;
  }

  int ans = -1;
  vector<int> res;

  multiset<int> vals(a.begin(), a.end());
  int mn = INT_MAX;
  for (int i = 0; i + 1 < n; ++i) {
    smin(mn, a[i + 1] - a[i]);
  }
  for (int i = 0; i + 1 < n; ++i) {
    if (a[i + 1] - a[i] == mn) {
      vals.erase(vals.find(a[i]));
      vals.erase(vals.find(a[i + 1]));

      if (smax(ans, n - 3 + (a[i] <= *vals.begin()) + (*vals.rbegin() <= a[i + 1]))) {
        res.clear();
        res.push_back(a[i]);
        res.insert(res.end(), vals.begin(), vals.end());
        res.push_back(a[i + 1]);
      }
      if (i > 0 && i + 1 < n && smax(ans, n - 2 + (a.back() <= a[0]))) {
        res.clear();
        res.push_back(a[i]);
        for (int j = i + 2; j < n; ++j) res.push_back(a[j]);
        for (int j = 0; j < i; ++j) res.push_back(a[j]);
        res.push_back(a[i + 1]);
      }

      vals.insert(a[i]);
      vals.insert(a[i + 1]);
    }
  }

  for (auto x : res) cout << x << ' ';
  cout << '\n';
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