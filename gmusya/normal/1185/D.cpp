#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  if (n <= 1000) {
    for (int j = 0; j < n; j++) {
      bool flag = true;
      vector <int> b;
      for (int i = 0; i < n; i++)
        if (i != j)
          b.push_back(a[i]);
      sort(b.begin(), b.end());
      for (int i = 0; i + 3 < n; i++)
        if (b[i + 1] - b[i] != b[i + 2] - b[i + 1])
          flag = false;
      if (flag) {
        cout << j + 1;
        return 0;
      }
    }
    cout << -1;
    return 0;
  }
  vector <pair <int, int>> b(n);
  for (int i = 0; i < n; i++)
    b[i] = {a[i], i};
  sort(b.begin(), b.end());
  vector <int> d;
  for (int i = 0; i + 1 < n; i++)
    d.push_back(b[i + 1].first - b[i].first);
  sort(d.begin(), d.end());
  if (d[10] != d[n - 10]) {
    cout << -1;
    return 0;
  }
  int D = d[25];
  vector <int> ind;
  for (int i = 0; i + 1 < n; i++)
    if (b[i + 1].first - b[i].first != D) {
      ind.push_back(b[i + 1].second), ind.push_back(b[i].second);
      if (i)
        ind.push_back(b[i - 1].second);
    }
  if (ind.empty()) {
    cout << b[0].second + 1;
    return 0;
  }
  for (int j : ind) {
    bool flag = true;
    vector <int> b;
    for (int i = 0; i < n; i++)
      if (i != j)
        b.push_back(a[i]);
    sort(b.begin(), b.end());
    for (int i = 0; i + 3 < n; i++)
      if (b[i + 1] - b[i] != b[i + 2] - b[i + 1])
        flag = false;
    if (flag) {
      cout << j + 1;
      return 0;
    }
  }
  cout << -1;
  return 0;
}