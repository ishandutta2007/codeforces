#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> pos;

bool cmp(vector <int> a, vector <int> b) {
  return pos[a[0]] < pos[b[0]];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> ans(n, vector <int>(m));
    pos.resize(n * m + 1);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> ans[i][j];
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        int x;
        cin >> x;
        pos[x] = j;
      }
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << ans[i][j] << ' ';
      cout << '\n';
    }
  }
  return 0;
}