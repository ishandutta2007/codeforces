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
  set<int> st;
  for (int i = 0; i < n; ++i) st.insert(i);
  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
    --x;
  }
  if (n == 1) {
    cout << -1 << '\n';
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (i + 1 == n) {
      int x = *st.begin();
      assert(x != a[i]);
      cout << x + 1 << '\n';
      break;
    }
    if (i + 2 < n) {
      int res = -1;
      for (int x : st) {
        if (x != a[i]) {
          res = x;
          break;
        }
      }
      cout << res + 1 << ' ';
      assert(res >= 0);
      st.erase(res);
      continue;
    }
    assert(i + 2 == n);
    int x = *st.begin();
    int y = *(next(st.begin()));
    if (x == a[i + 1] || y == a[i + 1]) {
      int res = a[i + 1];
      cout << res + 1 << ' ';
      st.erase(res);
      continue;
    }
    int res = (x == a[i] ? y : x);
    cout << res + 1 << ' ';
    st.erase(res);
  }
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