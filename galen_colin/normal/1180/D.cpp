#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;
const ll mod = 1e9 + 7;

int h, w;

/* this is confusing, h and w should switch */
void solve(int x1, int x2, int x, int y) {
  if (x1 > x2) return;

  int cx, cy;

  if (x1 == x2) {
    f0r(i, h) {
      if (y == h) {
        if (i % 2 == 0) cy = h - (i / 2);
        else cy = 1 + (i / 2);
      } else {
        if (i % 2 == 1) cy = h - (i / 2);
        else cy = 1 + (i / 2);
      }
      cout << x << " " << cy << '\n';
    }
    return;
  }

  f0r(i, 2 * h) {
    if (y == h) {
      if (i % 2 == 0) cy = h - (i / 2);
      else cy = 1 + (i / 2);
    } else {
      if (i % 2 == 1) cy = h - (i / 2);
      else cy = 1 + (i / 2);
    }
    if (x == x1) {
      cx = (i % 2 == 0) ? x1 : x2;
    } else {
      cx = (i % 2 == 1) ? x1 : x2;
    }
    cout << cx << " " << cy << '\n';
  }

  int nx, ny;
  nx = (cx == x1) ? x2 - 1 : x1 + 1;
  ny = (cy == h) ? 1 : h;
  solve(x1 + 1, x2 - 1, nx, ny);
}

int main() {
  io;
  cin >> w >> h;
  if (h > 1) solve(1, w, 1, 1);
  else {
    if (w == 1 && h == 1) cout << "1 1" << '\n';
    else {
      int cx;
      f0r(i, w) {
        if (i % 2 == 0) cx = 1 + (i / 2);
        else cx = w - (i / 2);
        cout << cx << " 1" << '\n';
      }
    }
  }
  cout.flush();
}