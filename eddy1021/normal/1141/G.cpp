#include <bits/stdc++.h>
using namespace std;
constexpr int N = 202020;
vector<pair<int, int>> v[N];
int n, k, r, ans[N];
void con(int now, int prt, int uclr) {
  int nxt = 1;
  if (nxt == uclr) {
    ++ nxt;
  }
  if (nxt > r) {
    nxt = 1;
  }
  for (auto p: v[now]) {
    int son = p.first;
    if (son == prt) {
      continue;
    }
    ans[p.second] = nxt;
    con(son, now, nxt);
    ++ nxt;
    if (nxt == uclr) {
      ++ nxt;
    }
    if (nxt > r) {
      nxt = 1;
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; ++i) {
    int ui, vi;
    scanf("%d%d", &ui, &vi);
    v[ui].push_back({vi, i});
    v[vi].push_back({ui, i});
  }
  int bl = 1, br = n - 1;
  while (bl <= br) {
    int bmid = (bl + br) >> 1;
    int other = 0;
    for (int i = 1; i < n; ++ i) {
      if ((int)v[i].size() > bmid) {
        ++ other;
      }
    }
    if (other <= k) {
      r = bmid;
      br = bmid - 1;
    } else {
      bl = bmid + 1;
    }
  }
  con(1, -1, -1);
  printf("%d\n", r);
  for (int i = 1; i < n; ++i) {
    printf("%d%c", ans[i], " \n"[i + 1 == n]);
  }
}