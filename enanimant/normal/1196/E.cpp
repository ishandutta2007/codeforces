// July 24, 2019
// https://codeforces.com/contest/1196/problem/E

/*

*/


#include <bits/stdc++.h>

using namespace std;


pair<int, int> dirs[3] = {{-1, 0}, {1, 0}, {0, 1}};

void print(int x, int y) {
  cout << x << ' ' << y << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int q;
  cin >> q;
  while (q--) {
    int b, w;
    cin >> b >> w;
    int m = min(b, w), M = max(b, w);
    if (M - 1 > 3 * m) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    if (b == w) {
      for (int i = 1; i <= 2 * b; i++) {
        print(1, i);
      }
      continue;
    }
    int r = (b > w ? 2 : 3);
    int c = 2; // centre of the current "flower"
    // b, w >= 1 :D
    print(r, c - 1);
    M--;
    while (m < M) {
      print(r, c);
      m--;
      int d = 0;
      while (d < 3 && m < M) {
        int dr, dc;
        tie(dr, dc) = dirs[d];
        print(r + dr, c + dc);
        M--;
        d++;
      }
      c += (d == 3 ? 2 : 1);
    }
    for (int i = 0; i < 2 * m; i++) {
      print(r, c + i);
    }
  }


  return 0;
}