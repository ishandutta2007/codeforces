// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int k;
    string s;
    cin >> k >> s;
    int one = -1;
    for (char& c : s) {
      c -= '0';
      if ((c % 2 == 0 && c != 2) || (c == 1) || (c == 9)) {
        one = c;
      }
    }

    if (one != -1) {
      cout << 1 << '\n' << one << '\n';
      continue;
    }
    
    int two = -1;
    for (int i = 0; i < k; ++i) {
      for (int j = i + 1; j < k; ++j) {
        int x = s[i] * 10 + s[j];
        if (x % 3 == 0 || x % 2 == 0 || x % 7 == 0 || x % 5 == 0) {
          two = x;
        } 
      }
    }
    assert(two != -1);
    cout << 2 << '\n' << two << '\n';

  }
}