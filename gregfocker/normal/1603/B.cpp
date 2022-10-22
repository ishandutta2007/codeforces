#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

bool ok(int x, int y, int n) {
  return (n > 0 && n % x == y % n);
}

int solve(int x, int y) {
  for (int i = y; i >= x; i--) {
    if (ok(x, y, i)) return i;
  }
  assert(0);
}

int help = 0;

bool now;

int my(int x, int y) {
  now = 0;
  if (x > y) return x + y;
  if (y % x == 0) return x;
  if (x > y / 3) {
    return y / 2 + x / 2;
  }
  now = 1;
  help++;
  return solve(x, y);
}



signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  int l = 100;


  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
      int a;
      if (x > y) a = x + y;
    else {
      int val = y / (y / x);
    //  assert(ok(x, y, a));
      int hx = x / 2;
      int hy = y / 2;
      int vl = hy / hx;
      a = y - (y / x) * ((val - x) / 2) - (hy % vl);

    }
      assert(ok(x, y, a));
      cout << a << "\n";
  }
  return 0;

  int good = 0, bad = 0;
  for (int x = 2; x <= l; x += 2) {

    int smth = 0;
    for (int y = 2; y <= l; y += 2) {
      if (x > y) continue;
      assert(ok(x, y, my(x, y)));
      if (1 || now) {
        int n = solve(x, y);
        assert(x <= y);
        assert(x <= n && n <= y);
     //   cout << n << " : " << x << " " << y << " " << "\n";
       /// assert(n - y + ((y - x) / 2) - x == 0);

        if (x > y / 3) {
          int a = 0;
          cout << x << " " << y << " : " << n << " vs " << a << ", dif = " << n - a << "\n";
          smth = 1;
        }
        continue;

        if (n - y / 2 + 3 * x / 2 != 0) {
          ///cout << n - y + ((y - x) / 2) - x << " : " << x / 2 << " and " << y / 2 << " " << "\n";
          //cout << n << " " << 4 * x / 2 - 2 * y / 2 << "\n";
          int a = 4 * x / 2;
          cout << x << " " << y << " : " << n << " vs " << a << ", dif = " << n - a << "\n";
          smth++;
        }
         else {
          assert(n == 3 * x / 2 - y / 2);
        }
      //  cout << n << " " << (y - x) / 2 + y / 3 << "\n";
      }
    ///  assert(ok(x, y, solve(x, y)));
    }
    if (smth)
    cout << "\n";
  }
  //cout << "all ok!\n";
  cout << "help = " << help << "\n";
  return 0;


  return 0;
}