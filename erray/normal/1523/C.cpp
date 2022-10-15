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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    
    vector<bool> act(n, false);
    vector<string> ans(n, "-1");
    ans[0] = '1';
    act[0] = true;
    for (int i = 1; i < n; ++i) {
      if (a[i] == 1) {   
        ans[i] = ans[i - 1];
        ans[i] += ".1";
      } else {
        for (int j = i - 1; j >= 0; --j) {
          bool old = act[j];
          act[j] = false;
          if (old && a[j] == a[i] - 1) {
            ans[i] = ans[j];
            while (!ans[i].empty() && ans[i].back() != '.') {
              ans[i].pop_back();
            }
            ans[i] += to_string(a[i]);
            break;   
          }
        }
      }
      act[i] = true;
    }

    for (auto e : ans) {
      cout << e << '\n';
    }
  }
}