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
  auto sn = to_string(n);
  int sz = int(sn.size());
  ll ans = 1e18;
  for (int msk = 2; msk < (1 << 10); ++msk) {
    if (__builtin_popcount(msk) != k) {
      continue;
    }
    int sm = 1;
    while (!(msk >> sm & 1)) sm++;
    int sm2 = 0;
    while (!(msk >> sm2 & 1)) sm2++;
    {
      ll cur = 0;
      for (int it = 0; it < sz + 1; ++it) {
        cur *= 10;
        cur += sm;
      }
      smin(ans, cur);
    }
    int f = 0;
    while (f < sz && (msk >> (sn[f] - '0') & 1)) {
      ++f;
    }
    if (f == sz) {
      ans = n;
      break;
    }
    for (int i = f; i >= 0; --i) {
      int ch = sn[i] - '0' + 1;
      while (ch < 10 && !(msk >> ch & 1)) ++ch;
      if (ch == 10) continue;
      auto cur = sn;
      cur[i] = ch + '0';
      for (int j = i + 1; j < sz; ++j) {
        cur[j] = sm2 + '0';
      }
      smin(ans, atoll(cur.c_str()));
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
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}