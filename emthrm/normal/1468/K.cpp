#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};

map<char, int> D{{'U', 0}, {'L', 1}, {'D', 2}, {'R', 3}};

void solve() {
  string s; cin >> s;
  auto f = [&](int ox, int oy) {
    int x = 0, y = 0;
    for (char c : s) {
      int d = D[c];
      x += dx[d];
      y += dy[d];
      if (x == ox && y == oy) {
        x -= dx[d];
        y -= dy[d];
      }
    }
    return x == 0 && y == 0;
  };
  if (f(1000000000, 1000000000)) {
    cout << 1000000000 << ' ' << 1000000000 << '\n';
    return;
  }
  int x = 0, y = 0;
  for (char c : s) {
    int d = D[c];
    x += dx[d];
    y += dy[d];
    if (f(x, y)) {
      cout << x << ' ' << y << '\n';
      return;
    }
  }
  cout << "0 0\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}