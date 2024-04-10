#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector <int> l(t.size());
  vector <int> r(t.size());
  int it = 0;
  for (int i = 0; i < n; i++) {
    if (it == m)
      break;
    if (t[it] == s[i]) {
      l[it] = i;
      it++;
    }
  }
  it = m - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (it < 0)
      break;
    if (t[it] == s[i]) {
      r[it] = i;
      it--;
    }
  }
  int ans = 0;
  for (int i = 0; i + 1 < m; i++)
    ans = max(ans, r[i + 1] - l[i]);
  cout << ans;
  return 0;
}