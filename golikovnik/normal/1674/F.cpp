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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;
  vector have(n, vector<bool>(m));
  int nstar = 0;
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    for (int j = 0; j < m; ++j) {
      have[i][j] = (s[j] == '*');
      nstar += have[i][j];
    }
  }

  auto ById = [&](int x) {
    return make_pair(x % n, x / n);
  };
  auto GetId = [&](int r, int c) {
    return c * n + r;
  };

  int match = 0;
  for (int i = 0; i < nstar; ++i) {
    match += have[i % n][i / n];
  }
  debug(match);
  debug(nstar);
  while (q--) {
    int r, c;
    cin >> r >> c;
    --r, --c;
    if (have[r][c]) {
      have[r][c] = false;
      int idme = GetId(r, c);
      auto[rr, cc] = ById(nstar - 1);
      if (idme < nstar) {
        --match;
      }
      if ((rr != r || cc != c) && have[rr][cc]) {
        --match;
      }
      --nstar;
    } else {
      have[r][c] = true;
      int idme = GetId(r, c);
      auto[rr, cc] = ById(nstar);
      if (idme <= nstar) {
        ++match;
      }
      if ((rr != r || cc != c) && have[rr][cc]) {
        ++match;
      }
      ++nstar;
    }
    cout << nstar - match << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}