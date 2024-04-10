#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = 500 + 7;
int n, m, a[N][N];

void read() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      a[i][j] = (s[j - 1] == 'X');
    }
  }
}

void print() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) cout << "X";
      else cout << ".";
    }
    cout << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
 /// freopen ("input", "r", stdin);
  int tt;
  cin >> tt;
  while (tt--) {
    read();
    int what_mod = 1;
    if (m % 3 == 0) what_mod = 2;
    for (int j = 1; j <= m; j++) {
      if (j % 3 == what_mod) {
        for (int i = 1; i <= n; i++) {
          a[i][j] = 1;
        }
        if (j + 3 <= m) {
          bool found = 0;
          for (int i = 1; i <= n; i++) {
            if (a[i][j + 1] || a[i][j + 2]) {
              a[i][j + 2] = 1;
              a[i][j + 1] = 1;
              found = 1;
              break;
            }
          }
          if (!found) {
            a[1][j + 1] = a[1][j + 2] = 1;
          }
        }
      }
    }
    print();
  }
}