#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

// 

int main() {
  string s;
  cin >> s;
  int ret = 0;
  for(int i = 0; i < s.size(); i++) {
    for(int j = 1; i + j <= s.size(); j++) {
      string t = s.substr(i, j);
      string p = t;
      reverse(begin(p), end(p));
      if(t != p) ret = max(ret, (int) p.size());
    }
  }
  cout << ret << endl;
}