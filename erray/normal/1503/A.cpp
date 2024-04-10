// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    int ct = count(s.begin(), s.end(), '0');
    int now = 0;
    string a(n, '(');
    string b(n, '(');
    int left = (n - ct) / 2;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        if (left == 0) {
          a[i] = ')';
          b[i] = ')';
        } else {
          --left;
        }
      } else {
        a[i] = (now ? '(' : ')');
        b[i] = (now ? ')' : '(');
        now ^= 1;
      }      
    }
    
    auto Check = [&](string x) {
      int sum = 0;
      bool res = true;
      for (char c : x) {
        sum += (c == '(' ? 1 : -1);
        res &= (sum >= 0);
      }  
      return res && sum == 0;
    };

    if (!Check(a) || !Check(b)) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n" << a << '\n' << b << '\n';
  }
}