#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <map>
#include <queue>
#include <ctime>

using namespace std;

int a[100002], b[100002];
vector<int> g[50005];

int whT[1000002], whP[50005];

bool go(int n, int m) {
  for (int i = 0; i < n; ++i) {
    whP[i] = g[i][rand() % g[i].size()];
    whT[whP[i]] = rand() & 1;
  }

  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    if (whT[whP[a[i]]] != whT[whP[b[i]]]) ++cnt;
  }
  // cout << cnt << endl;
  return cnt >= (m + 1) / 2;
}

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i];
    --a[i]; --b[i];
  }
  int T = 0;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    g[i].resize(k);
    for (int j = 0; j < k; ++j) {
      cin >> g[i][j];
      T = max(T, g[i][j]);
    }
  }

  srand(time(NULL));
  for (int i = 1; i <= T; ++i)
    whT[i] = rand() & 1;

  while (!go(n, m));
  for (int i = 0; i < n; ++i)
    cout << whP[i] << " ";
  cout << endl;
  for (int i = 1; i <= T; ++i)
    cout << whT[i] + 1 << " ";
  cout << endl;

  return 0;
}