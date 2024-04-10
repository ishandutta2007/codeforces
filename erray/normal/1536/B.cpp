// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    set<string> in;
    for (int i = 0; i < n; ++i) {
      string cur;
      for (int j = i; j < n && int(cur.size()) < 5; ++j) {
        cur += s[j];
        in.insert(cur);
      }
    }

    vector<string> all = {""};
    string res = [&] {
      while (true) {
        vector<string> new_all;
        for (char c = 'a'; c <= 'z'; ++c) {
          for (auto e : all) {
            e = c + e;
            if (in.count(e) == 0) {
              return e;
            } 
            new_all.push_back(e);
          }
        } 
        swap(new_all, all);
      }
    }();

    cout << res << '\n';
  }
}