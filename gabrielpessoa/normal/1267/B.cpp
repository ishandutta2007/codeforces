#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 5e5+5;

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  string s;
  cin >> s;
  vector<pair<char, int>> v;
  char cur = s[0];
  int q = 0;
  for(char c : s) {
    if(c == cur) q++;
    else {
      v.emplace_back(cur, q);
      cur = c;
      q = 1;
    }
  }
  v.emplace_back(cur, q);
  int n = v.size();
  if(n % 2 == 0) {
    cout << 0 << '\n';
    return 0;
  }
  for(int i = 0; i < n/2; i++) {
    if(v[i].first != v[n-i-1].first || (v[i].second == 1 && v[n-i-1].second == 1)) {
      cout << 0 << '\n';
      return 0;
    }
  }
  if(v[n/2].second == 1) cout << 0 << '\n';
  else cout << v[n/2].second+1 << '\n';
}