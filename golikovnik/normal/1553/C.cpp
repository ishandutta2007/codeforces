//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

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
  string s;
  cin >> s;
  int ans = 10;
  for (int m = 0; m < (1 << 10); ++m) {
    vector<int> score(2);

    auto win = [&](int i, int who) {
      int can = 0;
      for (int j = i + 1; j < 10; ++j) {
        can += j % 2 != who;
      }
      return can + score[1 - who] < score[who];
    };

    for (int i = 0; i < 10; ++i) {
      auto who = s[i] == '?' ? (m >> i & 1) : s[i] - '0';
      if (who == 1) {
        score[i % 2] += 1;
      }
      if (win(i, 0) || win(i, 1)) {
        smin(ans, i + 1);
        break;
      }
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