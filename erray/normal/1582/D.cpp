// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
      return a[x] < a[y];
    });

    vector<int> b(n);
    for (int i = 0; i < n - 1; i += 2) {
      int x = ord[i];
      int y = ord[i + 1];
      int l = lcm(a[x], a[y]);
      b[x] = -l / a[x];
      b[y] = l / a[y];
    }

    if (n % 2 == 1) {
      int x = ord[n - 3];
      int y = ord[n - 2];
      int z = ord[n - 1];
      /*
      do {
        array<int, 3> foo = {x, y, z};
        shuffle(foo.begin(), foo.end(), rng);
        x = foo[0];
        y = foo[1];
        z = foo[2];
        b[x] = b[y] = -a[z];
        b[z] = a[x] + a[y]; 
      } while (b[x] == 0 || b[y] == 0 || b[z] == 0);
      */
      if (a[x] + a[y] == 0) {
        swap(z, (a[x] == a[z] ? y : x));
      }
      b[x] = b[y] = -a[z];
      b[z] = a[x] + a[y]; 
    }

    for (int i = 0; i < n; ++i) {
      cout << b[i] << ' ';
    }
    cout << '\n';
  }
}