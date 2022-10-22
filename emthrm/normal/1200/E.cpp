#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
/*-------------------------------------------------*/
template <typename T>
vector<int> z_algorithm(const T &str) {
  int n = str.size();
  vector<int> res(n);
  res[0] = n;
  int j = 0;
  for (int i = 1; i < n;) {
    while (i + j < n && str[j] == str[i + j]) ++j;
    res[i] = j;
    if (j == 0) {
      ++i;
      continue;
    }
    int k = 1;
    while (i + k < n && k + res[k] < j) {
      res[i + k] = res[k];
      ++k;
    }
    i += k;
    j -= k;
  }
  return res;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  string ans; cin >> ans;
  while (--n) {
    string s; cin >> s;
    string t = s;
    if (ans.length() <= s.length()) {
      t += ans;
    } else {
      FOR(i, ans.length() - s.length(), ans.length()) t += ans[i];
    }
    vector<int> z = z_algorithm(t);
    int overlap = 0;
    FOR(i, s.length(), t.length()) {
      if (z[i] == t.length() - i) {
        overlap = t.length() - i;
        break;
      }
    }
    ans += s.substr(overlap);
  }
  cout << ans << '\n';
  return 0;
}