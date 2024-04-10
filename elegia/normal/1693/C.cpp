#include <cmath>
#include <cstring>

#include <algorithm>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

using ull = unsigned long long;
using ll = long long;

const int P = 1000000007;

int norm(int x) {
  return x >= P ? x - P : x;
}
void add(int& a, int b) {
  if ((a += b) >= P) {
    a -= P;
  }
}
void sub(int& a, int b) {
  if ((a -= b) < 0) {
    a += P;
  }
}
void fam(int& a, int b, int c) {
  a = (a + b * (ull)c) % P;
}
int mpow(int a, int k) {
  if (k == 0) {
    return 1;
  }
  int ret = mpow(a * (ull)a % P, k >> 1);
  if (k & 1) {
    ret = ret * (ull)a % P;
  }
  return ret;
}

const int _ = 200005;

int N, M;
int out[_], ans[_];
vector<int> g[_];
bool vis[_];

priority_queue<pair<int, int>> Q;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M;
  for (int i = 1; i <= N; ++i) ans[i] = M + 1;
  while (M--) {
    int u, v; cin >> u >> v;
    g[v].push_back(u); ++out[u];
  }
  ans[N] = 0; Q.emplace(0, N);
  while (!Q.empty()) {
    int u = Q.top().second; Q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (int v : g[u]) {
      --out[v];
      if (ans[v] > ans[u] + out[v] + 1) {
        ans[v] = ans[u] + out[v] + 1;
        Q.emplace(-ans[v], v);
      }
    }
  }
  cout << ans[1] << '\n';

  return 0;
}