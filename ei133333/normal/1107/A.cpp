#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int Q;
  cin >> Q;
  while(Q--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s.size() == 2 && s[0] >= s[1]) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << 2 << endl;
      cout << s[0] << " " << s.substr(1) << endl;
    }
  }

}