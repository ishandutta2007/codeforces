#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  map <int, vector <int>> m;
  set <int> used;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    m[u].push_back(v);
    m[v].push_back(u);
  }
  int start;
  for (auto &now : m)
    if (now.second.size() == 1)
      start = now.first;
  cout << start << ' ';
  used.insert(start);
  do {
    if (used.find(m[start][0]) != used.end())
      start = m[start][1];
    else
      start = m[start][0];
    cout << start << ' ';
    used.insert(start);
  } while (m[start].size() != 1);
  return 0;
}