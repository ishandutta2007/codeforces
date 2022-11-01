#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vi t(m), l(m), r(m);
  for (int i = 0; i < m; i++) {
    cin >> t[i] >> l[i] >> r[i];
    l[i]--, r[i]--;
  }
  vi a(n, -1);
  for (int i = 0; i < m; i++) {
    if (t[i] == 0)
      continue;
    for (int j = l[i]; j < r[i]; j++) {
      a[j + 1] = 0;
    }
  }
  a[0] = n;
  for (int i = 1; i < n; i++)
    a[i] += a[i - 1];
  for (int i = 0; i < m; i++) {
    if (t[i] == 1)
      continue;
    bool flag = true;
    for (int j = l[i]; j < r[i]; j++)
      if (a[j] != a[j + 1])
        flag = false;
    if (flag) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (auto &now : a)
    cout << now << ' ';
  return 0;
}