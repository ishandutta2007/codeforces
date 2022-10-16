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

struct parent_t {
  int me;
  int rem;
};

void solve(int) {
  int n, A, B;
  cin >> n >> A >> B;
  vector<int> a(n);
  for (auto& x : a) {
    char ch; cin >> ch; x = ch - '0';
  }

  vector dp(n + 1, vector(n + 1, vector(A, vector<bool>(B))));
  vector par(n + 1, vector(n + 1, vector(A, vector<parent_t>(B))));
  dp[0][0][0][0] = true;
  for (int i = 0; i < n; ++i) {
    for (int cnta = 0; cnta <= i; ++cnta) {
      for (int rema = 0; rema < A; ++rema) {
        for (int remb = 0; remb < B; ++remb) {
          if (!dp[i][cnta][rema][remb]) {
            continue;
          }

          {
            int nrem = (rema * 10 + a[i]) % A;
            dp[i + 1][cnta + 1][nrem][remb] = true;
            par[i + 1][cnta + 1][nrem][remb] = {0, rema};
          }

          {
            int nrem = (remb * 10 + a[i]) % B;
            dp[i + 1][cnta][rema][nrem] = true;
            par[i + 1][cnta][rema][nrem] = {1, remb};
          }
        }
      }
    }
  }

  int candiff = INT_MAX;
  int who = -1;
  for (int takea = 1; takea < n; ++takea) {
    if (dp[n][takea][0][0]) {
      if (smin(candiff, abs(takea - (n - takea)))) {
        who = takea;
      }
    }
  }

  if (who < 0) {
    cout << -1 << '\n';
    return;
  }

  int rema = 0;
  int remb = 0;
  int takea = who;  
  string ans;
  for (int i = n; i > 0; --i) {
    assert(dp[i][takea][rema][remb]);
    auto pr = par[i][takea][rema][remb];
    if (pr.me == 0) {
      ans += 'R';
      --takea;
      rema = pr.rem;
    } else {
      ans += 'B';
      remb = pr.rem;
    }
  }
  reverse(ans.begin(), ans.end());
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