#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector <int> p(n);
  vector <vector <int>> g(n);
  for (int v = 1; v < n; v++) {
    cin >> p[v];
    p[v]--;
    g[p[v]].push_back(v);
  }
  vector <bool> leave(n);
  for (int v = 0; v < n; v++)
    leave[v] = (g[v].size() == 0);
  vector <int> cnt(n);
  for (int v = 0; v < n; v++)
    for (int u : g[v])
      cnt[v] += leave[u];
  for (int v = 0; v < n; v++)
    if (!leave[v] && cnt[v] < 3) {
      cout << "No";
      return 0;
    }
  cout << "Yes";
  return 0;
}