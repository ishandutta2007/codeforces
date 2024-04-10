// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    char c = '0';
    int cur = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
      if (i == 0 || s[i] == s[i - 1]) ++cur;
      else cur = 1;
      if (cur == n) c = s[i];    
    }
    cout << string(n, c) << '\n';
  }
}