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

  int n, m;
  cin >> n >> m;
  vector a(n, vector<int>(m));
  for (auto& r : a) {
    for (auto& c : r) {
      cin >> c;
      --c;
    }
  }
  vector DX{1, 0, -1, 0};
  vector DY{0, 1, 0, -1};
  auto isBad = [&](int r, int c) {
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
      int rr = r + DX[i];
      int cc = c + DY[i];
      cnt += rr >= 0 && cc >= 0 && rr < n && cc < m && a[rr][cc] < a[r][c];
    }
    return a[r][c] != 0 && !cnt;
  };
  int nbad = 0;
  vector badId(n, vector<int>(m, -1));
  int ncheck = 0;
  auto activate = [&](int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= m || badId[r][c] != -1) {
      return;
    }
    badId[r][c] = ncheck++;
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (isBad(i, j)) {
        ++nbad;
        if (nbad == 1) {
          activate(i, j);
          for (int t = 0; t < 4; ++t) {
            activate(i + DX[t], j + DY[t]);
          }
        }
      }
    }
  }
  if (nbad == 0) {
    cout << 0 << '\n';
    return 0;
  }
  int ans = 0;

  vector used(n, vector<int>(m, -1));
  int iter = 0;

  auto process = [&](int r, int c, int delta) {
    if (r < 0 || c < 0 || r >= n || c >= m || used[r][c] == iter) {
      return;
    }
    used[r][c] = iter;
    nbad += delta * isBad(r, c);
  };
  auto add = [&](int r, int c, int delta) {
    process(r, c, delta);
    for (int i = 0; i < 4; ++i) {
      process(r + DX[i], c + DY[i], delta);
    }
  };
  auto Rem = [&](int r, int c) {
    add(r, c, -1);
  };
  auto Add = [&](int r, int c) {
    add(r, c, 1);
  };

  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      if (badId[r][c] < 0) {
        continue;
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (badId[i][j] >= 0 && badId[i][j] >= badId[r][c]) {
            continue;
          }
          ++iter;
          Rem(i, j);
          Rem(r, c);
          swap(a[i][j], a[r][c]);
          ++iter;
          Add(i, j);
          Add(r, c);
          ans += nbad == 0;
          ++iter;
          Rem(i, j);
          Rem(r, c);
          swap(a[i][j], a[r][c]);
          ++iter;
          Add(i, j);
          Add(r, c);
        }
      }
    }
  }
  
  if (ans > 0) {
    cout << 1 << ' ' << ans << '\n';
  } else {
    cout << 2 << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}