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
  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  int ans = 0;
  int x = 0;
  int y = n;

  auto upd = [&](int L, int R, int cnt) {
    // cerr << cnt << ' ' << L << ' ' << R << '\n';
    if (smax(ans, cnt)) {
      x = L;
      y = n - R;
    }
  };
  
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      continue;
    }
    int j = i;
    int cnt = 0;
    int sign = 1;
    while (j < n && a[j] != 0) {
      cnt += abs(a[j]) == 2;
      if (a[j] < 0) {
        sign = -sign;
      }
      j++;
    }
    if (sign < 0) {
      int left = i;
      int cleft = 0;
      while (a[left] >= 0) {
        cleft += abs(a[left]) == 2;
        ++left;
      }
      assert(a[left] < 0);
      cleft += abs(a[left]) == 2;
      ++left;
      upd(left, j, cnt - cleft);

      int right = j - 1;
      int cright = 0;
      while (a[right] >= 0) {
        cright += abs(a[right]) == 2;
        --right;
      }
      assert(a[right] < 0);
      cright += abs(a[right]) == 2;
      --right;
      upd(i, right + 1, cnt - cright);

      cnt -= min(cleft, cright);
    } else {
      upd(i, j, cnt);
    }

    i = j;
  }

  cout << x << ' ' << y << '\n';
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