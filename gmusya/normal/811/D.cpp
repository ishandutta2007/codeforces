#include <iostream>
#include <vector>

using namespace std;

string ans;
int n, m, f;
vector <bool> used;
vector <vector <char>> table;
vector <vector <pair <int, char>>> g;

void add_edge(int r1, int c1, int r2, int c2) {
  if (r1 >= n || r2 >= n || c1 >= m || c2 >= m)
    return;
  if (r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0)
    return;
  if (table[r1][c1] == '*' || table[r2][c2] == '*')
    return;
  int u = r1 * m + c1;
  int v = r2 * m + c2;
  if (v == u + m) {
    g[u].push_back({v, 'D'});
    g[v].push_back({u, 'U'});
  } else {
    g[u].push_back({v, 'R'});
    g[v].push_back({u, 'L'});
  }
}

void dfs(int v, string &x) {
  if (v == f)
    ans = x;
  used[v] = true;
  for (auto &now : g[v]) {
    int u = now.first;
    char c = now.second;
    if (used[u])
      continue;
    x += c;
    dfs(u, x);
    x.pop_back();
  }
}

int main() {
  cin >> n >> m;
  table = vector <vector <char>>(n, vector <char>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> table[i][j];
      if (table[i][j] == 'F')
        f = i * m + j;
    }
  g.resize(n * m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      add_edge(i, j, i + 1, j);
      add_edge(i, j, i, j + 1);
    }
  used.resize(n * m);
  string x = "";
  dfs(0, x);
  int swapLR = -1, swapUD = -1;
  int a = 1, b = 1;
  for (char c : ans) {
    if (c == 'L' || c == 'R') {
      if (swapLR == -1) {
        cout << c << endl;
        int newa, newb;
        cin >> newa >> newb;
        if (newa == a && newb == b) {
          swapLR = 1;
        } else {
          swapLR = 0;
          continue;
        }
      }
      if (swapLR == 0) {
        cout << c << endl;
        cin >> a >> b;
      }
      if (swapLR == 1) {
        if (c == 'L')
          c = 'R';
        else
          c = 'L';
        cout << c << endl;
        cin >> a >> b;
      }
    } else {
      if (swapUD == -1) {
        cout << c << endl;
        int newa, newb;
        cin >> newa >> newb;
        if (newa == a && newb == b) {
          swapUD = 1;
        } else {
          swapUD = 0;
          continue;
        }
      }
      if (swapUD == 0) {
        cout << c << endl;
        cin >> a >> b;
      }
      if (swapUD == 1) {
        if (c == 'U')
          c = 'D';
        else
          c = 'U';
        cout << c << endl;
        cin >> a >> b;
      }
    }
  }
  return 0;
}