#include <bits/stdc++.h>

using namespace std;

const int N = 101;

char s[N][N];

void solve() {
  int h, w;
  scanf("%d %d", &h, &w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      s[i][j] = '0';
    }
    s[i][w] = 0;
  }
  vector<pair<int, int>> pos;
  for (int i = 0; i < w; ++i) {
    pos.emplace_back(0, i);
  }
  for (int i = 1; i < h; ++i) {
    pos.emplace_back(i, w-1);
  }
  for (int i = w-2; i >= 0; --i) {
    pos.emplace_back(h-1, i);
  }
  for (int i = h-2; i > 0; --i) {
    pos.emplace_back(i, 0);
  }
  for (auto & p : pos) {
    bool ok = true;
    for (auto & other : pos) {
      if (s[other.first][other.second] == '0') continue;
      if (max(abs(other.first - p.first), abs(other.second - p.second)) <= 1) {
        ok = false;
        break;
      }
    }
    if (ok)
      s[p.first][p.second] = '1';
  }
  for (int i = 0; i < h; ++i) {
    printf("%s\n", s[i]);
  }
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
    if (tc)
      printf("\n");
  }
  return 0;
}