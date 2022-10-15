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
    cin >> n;
    vector<int> ct(n);
    vector<bool> tie(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (ct[i] == (n - 1) / 2) {
          if (!tie[i] && !tie[j] && (n % 2 == 0)) {
            cout << 0 << ' ';
            tie[i] = tie[j] = true;
          } else {
            cout << -1 << ' ';
            ++ct[j];
          }
        } else {
          cout << 1 << ' ';
          ++ct[i];
        }
      }
    }

    cout << '\n';
  }
}