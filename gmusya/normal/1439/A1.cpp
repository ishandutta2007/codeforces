#include <iostream>
#include <vector>

using namespace std;

vector <pair <int, int>> id0, id1, ans;
vector <vector <char>> c;

void pus(int i, int j) {
  if (c[i][j] == '0')
    id0.push_back({i, j});
  else
    id1.push_back({i, j});
}

void pus(pair <int, int> a) {
  int i = a.first, j = a.second;
  pus(i, j);
}

void upd(int i, int j, int x) {
  c[i][j] = '0' + x;
  ans.push_back({i + 1, j + 1});
}

void upd(pair <int, int> a, int x) {
  int i = a.first, j = a.second;
  upd(i, j, x);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    c.assign(n, vector<char>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> c[i][j];
    ans.resize(0);
    for (int i = 0; i < n; i += 2) {
      if (i + 1 == n)
        i--;
      for (int j = 0; j < m; j += 2) {
        if (j + 1 == m)
          j--;
        id0.resize(0), id1.resize(0);
        pus(i, j);
        pus(i + 1, j);
        pus(i, j + 1);
        pus(i + 1, j + 1);
        while (!id1.empty()) {
          if (id1.size() >= 3) {
            for (int it = 0; it < 3; it++) {
              upd(id1.back(), 0);
              id0.push_back(id1.back());
              id1.pop_back();
            }
            continue;
          }
          if (id1.size() == 2) {
            upd(id1[1], 0);
            upd(id0[0], 1);
            upd(id0[1], 1);
            pair <int, int> a = id1[1];
            pair <int, int> b = id0[0];
            pair <int, int> c = id0[1];
            id1.pop_back();
            id0.pop_back();
            id0.pop_back();
            id0.push_back(a);
            id1.push_back(b);
            id1.push_back(c);
            continue;
          }
          if (id1.size() == 1) {
            upd(id1[0], 0);
            upd(id0[1], 1);
            upd(id0[2], 1);
            pair <int, int> a = id1[0];
            pair <int, int> b = id0[1];
            pair <int, int> c = id0[2];
            id1.pop_back();
            id0.pop_back();
            id0.pop_back();
            id1.push_back(b);
            id1.push_back(c);
            id0.push_back(a);
          }
        }
      }
    }
    cout << ans.size() / 3 << '\n';
    for (int i = 0; i < (int)ans.size(); i += 3) {
      cout << ans[i].first << ' ' << ans[i].second << ' ';
      cout << ans[i + 1].first << ' ' << ans[i + 1].second << ' ';
      cout << ans[i + 2].first << ' ' << ans[i + 2].second << '\n';
    }
  }
  return 0;
}