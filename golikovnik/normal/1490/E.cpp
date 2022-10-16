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
  for (auto& x : a) {
    cin >> x;
  }
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) {
    return a[i] < a[j];
  });

  auto can = [&](int who) {
    i64 me = a[ord[who]];
    for (int i = 0; i < n; ++i) {
      if (i != who) {
        if (a[ord[i]] > me) return false;
        me += a[ord[i]];
      }
    }
    return true;
  };

  int left = -1;
  int right = n;
  while (left + 1 != right) {
    int middle = (left + right) / 2;
    if (can(middle)) {
      right = middle;
    } else {
      left = middle;
    }
  }
  vector<int> who;
  for (int i = right; i < n; ++i) who.push_back(ord[i]);
  sort(who.begin(), who.end());
  cout << who.size() << '\n';
  for (auto i : who) cout << i + 1 << ' ';
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