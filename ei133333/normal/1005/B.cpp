#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 59;

int main() {
  string s, t;
  cin >> s >> t;
  int match = 0;
  reverse(begin(s), end(s));
  reverse(begin(t), end(t));
  for(int i = 0; i < min(s.size(), t.size()); i++) {
    if(s[i] != t[i]) {
      break;
    } else {
      ++match;
    }
  }
  cout << s.size() + t.size() - match * 2 << endl;
}