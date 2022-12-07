#include <iostream>
#include <list>
#include <cmath>

using namespace std;

int n, m, k;
int b[500];
list<pair<int, int> > e[100000];
int ee[500][500];
int c = 0;
int vc[100000];
int vv[100000];
bool vis[500];
int md[500];

void dfs(int v) {
  vc[v] = c;
  for (list<pair<int, int> >::iterator it = e[v].begin(); it != e[v].end(); ++it)
    if ((it->second == 0) && (vc[it->first] == -1))
      dfs(it->first);
}

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i)
    cin >> b[i];
  int x, y, z;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y >> z;
    --x;
    --y;
    e[x].push_back(make_pair(y, z));
    e[y].push_back(make_pair(x, z));
  }
  for (int i = 0; i < n; ++i)
    vc[i] = -1;
  for (int i = 0; i < n; ++i)
    if (vc[i] == -1) {
      dfs(i);
      ++c;
    }
  int sum = 0;
  for (int i = 0; i < k; ++i) {
    for (int j = 1; j < b[i]; ++j)
      if (vc[sum + j] != vc[sum + j - 1]) {
        cout << "No" << endl;
        return 0;
      }
    for (int j = 0; j < b[i]; ++j)
      vv[sum + j] = i;
    sum += b[i];
  }
  for (int i = 0; i < k; ++i)
    for (int j = 0; j < k; ++j)
      ee[i][j] = -1;
  for (int i = 0; i < k; ++i)
    ee[i][i] = 0;
  int aa, bb, cc;
  for (int i = 0; i < n; ++i)
    for (list<pair<int, int> >::iterator it = e[i].begin(); it != e[i].end(); ++it)
    {
      aa = vv[i];
      bb = vv[it->first];
      cc = it->second;
      if ((ee[aa][bb] == -1) || (ee[aa][bb] > cc))
        ee[aa][bb] = cc;
    }
  for (int z = 0; z < k; ++z)
    for (int i = 0; i < k; ++i)
      for (int j = 0; j < k; ++j)
        if ((ee[i][z] != -1) && (ee[z][j] != -1))
          if ((ee[i][j] == -1) || (ee[i][j] > ee[i][z] + ee[z][j]))
          ee[i][j] = ee[i][z] + ee[z][j];
  cout << "Yes" << endl;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j)
      cout << ee[i][j] << ' ';
    cout << endl;
  }
  return 0;
}