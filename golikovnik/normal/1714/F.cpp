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
  int n;
  cin >> n;
  vector dist(3, vector<int>(3));
  cin >> dist[0][1];
  dist[1][0] = dist[0][1];
  cin >> dist[1][2];
  dist[2][1] = dist[1][2];
  cin >> dist[0][2];
  dist[2][0] = dist[0][2];
  for (int root = 0; root < 3; ++root) {
    int u = n - 1;
    int x = dist[root][(root + 1) % 3];
    int y = dist[root][(root + 2) % 3];
    for (int a = 0; a < n; ++a) {
      int b = x - a;
      int c = y - a;
      if (b > 0 && c > 0 && a + (c - 1) + (b - 1) + 3 <= n && b + c == dist[(root + 1) % 3][(root + 2) % 3]) {
        cout << "YES\n";
        int pv = root;
        while (a--) {
          cout << pv + 1 << ' ' << u + 1 << '\n';
          pv = u--;
        }
        int qv = pv;
        while (--b) {
          cout << qv + 1 << ' ' << u + 1 << '\n';
          qv = u--;
        }
        cout << qv + 1 << ' ' << (root + 1) % 3 + 1 << '\n';
        qv = pv;
        while (--c) {
          cout << qv + 1 << ' ' << u + 1 << '\n';
          qv = u--;
        }
        cout << qv + 1 << ' ' << (root + 2) % 3 + 1 << '\n';
        while (u > 2) {
          cout << 1 << ' ' << u + 1 << '\n';
          --u;
        }
        return;
      }
    }
  }
  cout << "NO\n";
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