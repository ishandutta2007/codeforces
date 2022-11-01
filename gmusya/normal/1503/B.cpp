#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int ask() {
  int x;
  cin >> x;
  return x;
}

vvi ans;

void color(int c, int x, int y) {
  cout << c << ' ' << x + 1 << ' ' << y + 1 << endl;
  ans[x][y] = c;
}

int main() {
  int n;
  cin >> n;
  ans = vvi(n, vi(n, -1));
  int cnt1 = (n * n + 1) / 2;
  int cnt2 = n * n - cnt1;
  for (int it = 0; it < n * n; it++) {
    int x = ask();
    if (x != 1 && cnt1 > 0) {
      cnt1--;
      bool flag = false;
      for (int i = 0; i < n && !flag; i++) {
        for (int j = 0; j < n && !flag; j++) {
          if ((i + j) & 1 || ans[i][j] != -1) {
            continue;
          }
          color(1, i, j);
          flag = true;
        }
      }
      continue;
    }
    if (x != 2 && cnt2 > 0) {
      cnt2--;
      bool flag = false;
      for (int i = 0; i < n && !flag; i++) {
        for (int j = 0; j < n && !flag; j++) {
          if ((i + j) % 2 == 0 || ans[i][j] != -1) {
            continue;
          }
          color(2, i, j);
          flag = true;
        }
      }
      continue;
    }
    if (x != 3) {
      x = 3;
    } else if (cnt1 == 0) {
      x = 2;
    } else {
      x = 1;
    }
    bool flag = false;
    for (int i = 0; i < n && !flag; i++) {
      for (int j = 0; j < n && !flag; j++) {
        if (ans[i][j] != -1) {
          continue;
        }
        color(x, i, j);
        flag = true;
      }
    }
  }
  return 0;
}