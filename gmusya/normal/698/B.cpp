#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <random>

using namespace std;

mt19937 gen(time(0));

vector <int> dsu;

int get(int v) {
  if (dsu[v] == v)
    return v;
  return dsu[v] = get(dsu[v]);
}

void merge(int u, int v) {
  u = get(u), v = get(v);
  if (gen() % 2)
    swap(u, v);
  dsu[u] = v;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  dsu.resize(n);
  iota(dsu.begin(), dsu.end(), 0);
  vector <int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  int root = -1;
  for (int i = 0; i < n; i++)
    if (i == p[i])
      root = i;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i == root)
      continue;
    int u = i, v = p[i];
    u = get(u), v = get(v);
    if (u == v)
      p[i] = root, ans++;
    merge(u, v);
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    if (p[i] == -1 && root == -1)
      root = i;
    if (p[i] == -1)
      p[i] = root;
    cout << p[i] + 1 << ' ';
  }
  return 0;
}