#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> dsu;

int get(int v) {
  if (dsu[v] == v)
    return v;
  return dsu[v] = get(dsu[v]);
}

void merge(int u, int v) {
  u = get(u), v = get(v);
  dsu[u] = v;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  vector <int> d(n);
  for (int i = 0; i < n; i++)
    cin >> d[i];
  dsu.resize(n);
  for (int i = 0; i < n; i++)
    dsu[i] = i;
  for (int i = 0; i < n; i++) {
    if (i - d[i] >= 0)
      merge(i, i - d[i]);
    if (i + d[i] < n)
      merge(i, i + d[i]);
  }
  for (int i = 0; i < n; i++) {
    int a = get(p[i]), b = get(i);
    if (a != b) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}