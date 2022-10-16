#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

int n, m, s, p[200100], v[200100];
vector<int> e[200100], r[2];

void record(int k, int i) {
  while (i >= 0)
    r[k].push_back(i), i = p[i];
}

void dfs(int i, int ci, int cp) {
  if (v[i] == ci || v[i] > n)
    return;
  if (v[i] >= 0) {
    record(0, i);
    r[1].push_back(i);
    record(1, cp);
    return;
  }
  p[i] = cp;
  v[i] = ci;
  for (int j : e[i]) {
    dfs(j, ci, i);
    if (sz(r[0]))
      return;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n >> m >> s, s--;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b, a--, b--;
    e[a].push_back(b);
  }
  for (int i = 0; i < n; i++)
    v[i] = -1;
  v[s] = n + 1;
  p[s] = -1;
  for (int i : e[s]) {
    dfs(i, i, s);
    if (sz(r[0]))
      break;
  }
  cout << (sz(r[0]) ? "Possible\n" : "Impossible\n");
  if (sz(r[0])) {
    for (int i = 0; i < 2; i++) {
      reverse(r[i].begin(), r[i].end());
      cout << sz(r[i]) << "\n";
      for (int j : r[i])
        cout << j + 1 << " ";
      cout << "\n";
    }
  }
}