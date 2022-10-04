#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 1e3 + 7;

vector <int> g[N];

int cl[N];
bool used[N];

void dfs(int u) {
  used[u] = 1;
  for (auto v : g[u]) {
    if (!used[v]) {
      cl[v] = cl[u] ^ 1;
      dfs(v);
    } else if (cl[v] != (cl[u] ^ 1)) {
      exit(1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <ll> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  ll st = 2;
  while (true) {
    bool ok = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ll d = ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) % st;
        if (d == st / 2) {
          ok = true;
        }
      }
    }
    if (!ok) {
      st *= 2;
    } else {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          ll d = ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) % st;
          if (d == st / 2) {
            g[i].push_back(j);
            g[j].push_back(i);
          }
        }
      }
      for (int i = 0; i < n; ++i) {
        if (!used[i]) {
          cl[i] = 0;
          dfs(i);
        }
      }
      vector <int> a;
      for (int i = 0; i < n; ++i) {
        if (cl[i] == 0) {
          a.push_back(i);
        }
      }
      cout << a.size() << '\n';
      for (int x : a) {
        cout << x + 1 << ' ';
      }
      cout << '\n';
      return 0;
    }
  }
}