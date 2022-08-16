#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int solve(string s) {
  s += s;
  int ret = 1, sum = 1;
  for(int i = 1; i < s.size(); i++) {
    if(s[i - 1] == s[i]) {
      sum = 1;
    } else {
      sum++;
      ret = max(ret, sum);
    }
  }
  return min((int) s.size() / 2, ret);
}

int main() {
  string s;
  cin >> s;
  int ret = solve(s);
  reverse(begin(s), end(s));
  ret = max(ret, solve(s));
  cout << ret << endl;
}