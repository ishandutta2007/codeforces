#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;


int main() {
  string s;
  cin >> s;
  int ret = INF;

  if(s.size() <= 2) {
    if(s == "25" || s == "50" || s == "75") {
      cout << 0 << endl;
      return 0;
    }
    if(s == "52" || s == "57") {
      cout << 1 << endl;
      return 0;
    }
    cout << -1 << endl;
    return 0;
  }
  for(int i = 0; i < s.size(); i++) {
    if(i == 1 && s[i] == '0') continue;

    if(s[i] != '0') {
      // 
      string t = s;
      int add = 0;
      for(int j = i; j > 0; j--) swap(t[j], t[j - 1]), ++add;
      // **0
      // 
      for(auto j : {"25", "50", "75", "00"}) {
        for(int k = 1; k < t.size(); k++) {
          if(t[k] == j[1]) { // 
            string u = t;
            int add2 = add;
            for(int l = k + 1; l < t.size(); l++) swap(u[l], u[l - 1]), ++add2;
            for(int l = 1; l + 1 < t.size(); l++) { // 
              if(u[l] == j[0]) {
                ret = min(ret, add2 + (int) t.size() - l - 2);
              }
            }
          }
        }
      }
    }
  }

  if(ret == INF) cout << -1 << endl;
  else cout << ret << endl;
}