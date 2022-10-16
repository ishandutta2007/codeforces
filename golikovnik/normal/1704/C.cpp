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
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  vector<int> lens;
  for (int i = 0; i + 1 < m; ++i) {
    if (a[i] + 1 != a[i + 1]) {
      lens.push_back(a[i + 1] - a[i] - 1);
    }
  }
  int s = a[0] - 1 + (n - a[m - 1]);
  if (s != 0) {
    lens.push_back(s);
  }
  sort(lens.rbegin(), lens.rend());
  int ans = m;
  int steps = 0;
  int i = 0;

  for (; i < int(lens.size()); ++i) {
    auto go = [&] {
      steps++;
      ans += 2 * (int(lens.size()) - i);
      while (int(lens.size()) > i && lens.back() <= 2 * steps) {
        int x = lens.back();
        lens.pop_back();
        if (x == 2 * steps - 1) {
          --ans;
        }
      }
    };
    int cur = lens[i] - 2 * steps;
    assert(cur > 0);
    go();
    --ans;
    if (i < int(lens.size())) {
      cur = lens[i] - 2 * steps;
      go();
      ans -= 1 + (cur > 1);
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

  int _tests;
  cin >> _tests;
  for (int _tt = 1; _tt <= _tests; ++_tt) {
    solveTest();
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}