//  Copyright 2021 Nikita Golikov

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

void solve(int) {
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    char ch; cin >> ch;
    a[i] = (ch == '+' ? 1 : -1);
    if (i % 2 == 0) {
      a[i] *= -1;
    }
  }
  vector<int> pref(n + 1);
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + (a[i] > 0);
  }

  map<int, vector<int>> byValue;
  int s = 0;
  for (int i = 0; i < n; ++i) {
    byValue[2 * s + a[i]].push_back(i);
    s += a[i];
  }

  auto getMid = [&](int l, int r) {
    auto S = pref[r] - pref[l];
    S -= (r - l - S);
    auto A = 2 * (pref[l] - (l - pref[l]));

    auto& vec = byValue[S + A];
    auto it = lower_bound(vec.begin(), vec.end(), l);
    assert(it != vec.end() && *it < r);
    return *it + 1;
  };

  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    auto x = pref[r] - pref[l];
    auto y = r - l - x;
    if ((r - l) % 2 == 1) {
      cout << 1 << '\n' << getMid(l, r) << '\n';
      continue;
    }
    if (x == y) {
      cout << 0 << '\n';
      continue;
    }
    cout << 2 << '\n';
    cout << l + 1 << ' ' << getMid(l + 1, r) << '\n';
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
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}