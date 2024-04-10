#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector <int> z_function(string &s) {
  int n = s.size();
  vector <int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    z[i] = max(0, min(r - i, z[i - l]));
    while (i < n && s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] > r) l = i, r = i + z[i];
  }
  return z;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  while (true) {
    n = s.size();
    vector <int> z = z_function(s);
    for (int i = 1; i < n; i++) {
      if (i + z[i] != n && s[i + z[i]] > s[z[i]]) {
        s.resize(i);
        break;
      }
    }
    if ((int)s.size() >= k) {
      break;
    }
    s += s;
  }
  s.resize(k);
  cout << s;
  return 0;
}