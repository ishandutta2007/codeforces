#include <iostream>
#include <vector>

using namespace std;

int f(int x) {
  int res = (x / 2) * (x / 2 - 1);
  if (x % 2)
    res += x / 2;
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  int i = 0;
  int cur = 0;
  if (m == 0) {
    vector <int> a;
    while (a.size() < n)
      a.push_back(1e8 + (int)a.size() * n);
    for (auto &now : a)
      cout << now << ' ';
    return 0;
  }
  while (cur <= m) {
    i++;
    cur = f(i);
  }
  i--;
  cur = f(i);
  vector <int> a;
  for (int j = 1; j <= i; j++)
    a.push_back(j);
  if (i > n || (i == n && cur < m)) {
    cout << -1;
    return 0;
  }
  int ost = m - cur;
  if (ost)
    a.push_back(2 * i - 2 * ost + 1);
  while (a.size() < n)
    a.push_back(1e8 + (int)a.size() * n);
  for (auto &now : a)
    cout << now << ' ';
  return 0;
}