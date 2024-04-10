#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int ver = 0, hor = 0;
  vector <pair <int, int>> a;
  vector <int> allx, ally;
  for (int i = 0; i < 4; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2)
      ver++;
    if (y1 == y2)
      hor++;
    if (x1 == x2 && y1 == y2)
      hor += 10, ver += 10;
    a.push_back({x1, y1});
    a.push_back({x2, y2});
    allx.push_back(x1), allx.push_back(x2);
    ally.push_back(y1), ally.push_back(y2);
  }
  if (ver != 2 || hor != 2) {
    cout << "NO";
    return 0;
  }
  sort(a.begin(), a.end());
  sort(allx.begin(), allx.end());
  sort(ally.begin(), ally.end());
  allx.resize(unique(allx.begin(), allx.end()) - allx.begin());
  ally.resize(unique(ally.begin(), ally.end()) - ally.begin());
  if (allx.size() != 2 || ally.size() != 2) {
    cout << "NO";
    return 0;
  }
  bool flag = true;
  for (int i = 0; i < 7; i++)
    if (((a[i] == a[i + 1]) ^ (i % 2)) == 0)
      flag = false;
  if (flag)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}