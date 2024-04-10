#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  int it = 0;
  vector <int> lans(n + 1, 0);
  for (int i = 0; i < n; i++) {
    if (it < m && s[i] == t[it])
      it++;
    lans[i + 1] = it;
  }
  int ans = 0;
  it = t.size() - 1;
  for (int i = n - 1; i >= 0; i--) {
    int pos = upper_bound(lans.begin(), lans.end(), it) - lans.begin();
    ans = max(i - pos + 1, ans);
    if (it >= 0 && s[i] == t[it])
      it--;
  }
  cout << ans;
  return 0;
}