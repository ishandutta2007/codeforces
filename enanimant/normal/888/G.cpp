/*
 * author:  ADMathNoob
 * created: 04/09/21 18:47:11
 * problem: https://www.acmicpc.net/problem/16901
 */

/*
g++ boj_16901.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ boj_16901.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors


*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int N = 200005;
const int H = 31;

int n;
int a[N];

int nodes = 1;
int trie[N * H][2];
int value[N * H];
int cnt[N * H];
int height[N * H];

void Insert(int x, int h, int v) {
  cnt[x] += 1;
  if (h == 0) {
    value[x] = v;
    return;
  }
  int d = ((v >> (h - 1)) & 1);
  if (trie[x][d] == -1) {
    trie[x][d] = nodes++;
  }
  Insert(trie[x][d], h - 1, v);
}

void Insert(int v) {
  Insert(0, H - 1, v);
}

int BestPair(int x1, int x2, int h) {
  if (h == 0) {
    return value[x1] ^ value[x2];
  }
  int res = INF;
  for (int d = 0; d < 2; d++) {
    int y1 = trie[x1][d];
    int y2 = trie[x2][d];
    if (y1 != -1 && y2 != -1) {
      res = min(res, BestPair(y1, y2, h - 1));
    }
  }
  if (res == INF) {
    for (int d = 0; d < 2; d++) {
      int y1 = trie[x1][d];
      int y2 = trie[x2][d ^ 1];
      if (y1 != -1 && y2 != -1) {
        res = min(res, BestPair(y1, y2, h - 1));
      }
    }
  }
  assert(res != INF);
  return res;
}

long long Solve(int x, int h) {
  int l = trie[x][0];
  int r = trie[x][1];
  long long res = 0;
  if (l != -1 && r != -1) {
    res += BestPair(l, r, h - 1);
  }
  if (l != -1) {
    res += Solve(l, h - 1);
  }
  if (r != -1) {
    res += Solve(r, h - 1);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  n = unique(a, a + n) - a;
  for (int i = 0; i < N * H; i++) {
    for (int d = 0; d < 2; d++) {
      trie[i][d] = -1;
    }
  }
  for (int i = 0; i < n; i++) {
    Insert(a[i]);
  }
  cout << Solve(0, H - 1) << '\n';
  return 0;
}