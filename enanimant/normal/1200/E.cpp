// August 11, 2019
// https://codeforces.com/contest/1200/problem/E

/*

*/


#include <bits/stdc++.h>

using namespace std;


vector<int> z_function(const string &s) {
  int n = (int) s.size();
  vector<int> z(n, n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    z[i] = (i > r ? 0 : min(r - i + 1, z[i - l]));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n;
  cin >> n;
  vector<string> ss(n);
  for (int i = 0; i < n; i++) {
    cin >> ss[i];
  }
  string res = ss[0];
  for (int i = 1; i < n; i++) {
    int cur_len = res.size();
    int len = min(cur_len, (int) ss[i].size());
    string s = ss[i] + "#" + res.substr(cur_len - len);
    len = s.size();
    vector<int> z = z_function(s);
    bool added = false;
    for (int j = ss[i].size() + 1; j < len; j++) {
      if (z[j] == len - j) {
        res += ss[i].substr(z[j]);
        added = true;
        break;
      }
    }
    if (!added) {
      res += ss[i];
    }
  }
  cout << res << '\n';


  return 0;
}