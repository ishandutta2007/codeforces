#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int m, n;
  cin >> m >> n;
  vector <vector <int>> a(n, vector <int> (m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
    for (int j = m - 2; j >= 0; --j) {
      a[i][j] -= a[i][m - 1];
    }
  }
  vector <int> best;
  for (int j = 0; j + 1 < m; ++j) {
    vector <int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&] (int f, int s) {
      return a[f][j] > a[s][j];
    });
    int sum = 0;
    vector <int> cur;
    for (int i : id) {
      if (sum + a[i][j] < 0) {
        break;
      } else {
        sum += a[i][j];
        cur.push_back(i);
      }
    }
    if (cur.size() > best.size()) best = cur;
  }
  set <int> who;
  for (int i = 0; i < n; ++i) who.insert(i);
  for (int i : best) who.erase(i);
  cout << who.size() << '\n';
  for (int i : who) {
    cout << i + 1 << ' ';
  }
}