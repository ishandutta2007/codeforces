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
  int n, k;
  cin >> n >> k;
  vector<int> pos(k);
  for (auto& x : pos) cin >> x;
  sort(pos.begin(), pos.end());
  pos.push_back(n);

  auto can = [&](int from) {
    from = k - from;
    ll dist = pos[from];
    for (int i = from; i < k; ++i) {
      dist -= (i - from) * ll(pos[i + 1] - pos[i]);
      if (dist <= 0) {
        return false;
      }
    }
    return true;
  };

  int left = 0;
  int right = k + 1;
  while (left + 1 != right) {
    int mid = (left + right) / 2;
    (can(mid) ? left : right) = mid;
  }

  cout << left << '\n';
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