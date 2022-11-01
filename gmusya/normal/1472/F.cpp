#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <int> r(m), c(m);
    for (int i = 0; i < m; i++)
      cin >> r[i] >> c[i];
    map <int, int> allx;
    for (int i = 0; i < m; i++) {
      allx[c[i]] = 0;
      allx[(c[i] & 1 ? c[i] + 1 : c[i] - 1)] = 0;
    }
    int cnt = 0;
    for (auto &now : allx)
      now.second = cnt++;
    for (int i = 0; i < m; i++)
      c[i] = allx[c[i]];
    vector <bool> used1(cnt), used2(cnt);
    for (int i = 0; i < m; i++) {
      if (r[i] == 1)
        used1[c[i]] = true;
      else
        used2[c[i]] = true;
    }
    bool flag = true;
    for (int i = 0; i < cnt; i++) {
      if (!used1[i] && !used2[i]) {
        used1[i] = true, used2[i] = true;
        continue;
      }
      if (used1[i] && used2[i])
        continue;
      if (i == cnt - 1) {
        flag = false;
        break;
      }
      if (!used1[i]) {
        if (!used1[i + 1])
          used1[i] = used1[i + 1] = true;
        else
          flag = false;
      } else {
        if (!used2[i + 1])
          used2[i] = used2[i + 1] = true;
        else
          flag = false;
      }
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}