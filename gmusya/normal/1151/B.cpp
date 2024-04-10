#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(vector <int> a) {
  int x = 0;
  for (auto &now : a)
    x ^= now;
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <vector <int>> a(n, vector <int> (m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  vector <int> ids;
  for (int i = 0; i < n; i++)
    if (*min_element(a[i].begin(), a[i].end()) != *max_element(a[i].begin(), a[i].end()))
      ids.push_back(i);
  if (ids.empty()) {
    vector <int> arr;
    for (int i = 0; i < n; i++)
      arr.push_back(a[i][0]);
    if (check(arr)) {
      cout << "TAK\n";
      for (int i = 0; i < n; i++)
        cout << 1 << ' ';
      return 0;
    }
    cout << "NIE";
    return 0;
  }
  cout << "TAK\n";
  {
    vector <int> arr;
    for (int i = 0; i < n; i++) {
      if (i == ids[0])
        arr.push_back(*max_element(a[i].begin(), a[i].end()));
      else
        arr.push_back(a[i][0]);
    }
    if (check(arr)) {
      for (int i = 0; i < n; i++) {
        if (i == ids[0])
          cout << max_element(a[i].begin(), a[i].end()) - a[i].begin() + 1 << ' ';
        else
          cout << 1 << ' ';
      }
      return 0;
    }
  }
  {
    vector <int> arr;
    for (int i = 0; i < n; i++) {
      if (i == ids[0])
        arr.push_back(*min_element(a[i].begin(), a[i].end()));
      else
        arr.push_back(a[i][0]);
    }
    if (check(arr)) {
      for (int i = 0; i < n; i++) {
        if (i == ids[0])
          cout << min_element(a[i].begin(), a[i].end()) - a[i].begin() + 1 << ' ';
        else
          cout << 1 << ' ';
      }
      return 0;
    }
  }
  return 0;
}