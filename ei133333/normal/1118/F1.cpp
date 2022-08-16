#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 mod = 1e9 + 7;

int N, K, A[300000];
vector< int > g[300000];
int t[300000][3], all[3];

int rec(int idx, int par) {
  int ret = 0;
  for(auto to : g[idx]) {
    if(to == par) continue;
    ret += rec(to, idx);
    for(int i = 0; i < 3; i++) t[idx][i] += t[to][i];
  }
  for(auto to : g[idx]) {
    if(to == par) continue;
    if((all[1] - t[to][1] == 0 || all[2] - t[to][2] == 0) &&
       (t[to][1] == 0 || t[to][2] == 0)) {
      ++ret;
    }
  }
  t[idx][A[idx]]++;
  return ret;
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    all[A[i]]++;
  }
  for(int i = 1; i < N; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  printf("%d\n", rec(0, -1));
}