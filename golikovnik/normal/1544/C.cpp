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
  int const MAX = 100;
  array<int, MAX + 1> cntMe{}, cntHe{};
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; cntMe[x]++;
  }
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; cntHe[x]++;
  }

  auto calc = [&](array<int, MAX + 1>& arr, int need) {
    i64 score = 0;
    for (int it = MAX; it >= 0; --it) {
      auto take = min(need, arr[it]);
      score += i64(take) * it;
      need -= take;
    }
    return score;
  };

  int left = -1;
  int right = int(1e9);
  while (left + 1 != right) {
    int mid = (left + right) / 2;
    auto nme = cntMe;
    nme.back() += mid;
    auto nhe = cntHe;
    nhe[0] += mid;
    int total = n + mid;
    int need = total - total / 4;
    if (calc(nme, need) >= calc(nhe, need)) {
      right = mid;
    } else {
      left = mid;
    }
  }
  cout << right << '\n';
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