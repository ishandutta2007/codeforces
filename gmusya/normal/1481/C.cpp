#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vi a(n), b(n), c(m);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    for (int i = 0; i < m; i++)
      cin >> c[i];
    for (int i = 0; i < n; i++)
      a[i]--, b[i]--;
    for (int i = 0; i < m; i++)
      c[i]--;
    vvi need(n);
    for (int i = 0; i < n; i++)
      if (a[i] != b[i])
        need[b[i]].push_back(i);
    vector <bool> used(n);
    for (int i = 0; i < n; i++)
      used[b[i]] = true;
    if (!used[c[m - 1]]) {
      cout << "NO\n";
      continue;
    }
    int pos = 0;
    vi ans;
    for (int i = m - 1; i >= 0; i--) {
      if (i == m - 1) {
        if (need[c[i]].empty()) {
          for (int j = 0; j < n; j++) {
            if (b[j] == c[i])
              pos = j;
          }
        } else {
          pos = need[c[i]].back();
          a[pos] = c[i];
          need[c[i]].pop_back();
        }
        ans.push_back(pos);
        continue;
      }
      if (need[c[i]].empty()) {
        ans.push_back(pos);
      } else {
        ans.push_back(need[c[i]].back());
        a[ans.back()] = c[i];
        need[c[i]].pop_back();
      }
    }
    bool flag = true;
    for (int i = 0; i < n; i++)
      if (a[i] != b[i])
        flag = false;
    reverse(ans.begin(), ans.end());
    if (!flag) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int x : ans)
        cout << x + 1 << ' ';
      cout << '\n';
    }
  }
  return 0;
}