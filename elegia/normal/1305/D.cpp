#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int N = 1010;

int n;
int deg[N], prt[N];
bool vis[N];
vector<int> g[N];

int ask(int u, int v) {
  cout << "? " << u << ' ' << v << '\n';
  cout.flush();
  int w;
  cin >> w;
  return w;
}

void answer(int r) {
  cout << "! " << r << '\n';
  cout.flush();
  exit(0);
}

void solve(int u) {
  memset(deg, 0, sizeof(deg));
  vector<int> nodes;
  function<void(int)> dfs = [&](int u) {
    vis[u] = true;
    nodes.push_back(u);
    for (int v : g[u])
      if (!vis[v]) {
        ++deg[u];
        ++deg[v];
        prt[v] = u;
        dfs(v);
      }
    vis[u] = false;
  };
  dfs(u);
  if (nodes.size() == 1) {
    answer(u);
    return;
  }
  vector<int> ez;
  for (int v : nodes) if (deg[v] == 1) ez.push_back(v);
  int r = ask(ez[0], ez[1]);
  dfs(r);
  while (ez[0] != r) {
    vis[ez[0]] = true;
    ez[0] = prt[ez[0]];
  }
  while (ez[1] != r) {
    vis[ez[1]] = true;
    ez[1] = prt[ez[1]];
  }
  solve(r);
}

int main() {
  cin >> n;
  for (int rep = 1; rep < n; ++rep) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  solve(1);

  return 0;
}