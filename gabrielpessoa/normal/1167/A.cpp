#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    int n;
    cin >> n;
    cin >> s;
    bool valid = false;
    for(int i = 0; i < (int) (s.size()) - 10; i++) {
      if(s[i] == '8') valid = true;
    }
    if(valid) cout << "YES\n";
    else cout << "NO\n";
  }
}