// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int>> pos(2);
    for (int i = 0; i < n; ++i) {
      pos[s[i] - '0'].push_back(i);
    }
    for (int i = 0; i < q; ++i) {
      int l, r;
      cin >> l >> r;
      --l, --r;
      cout << (r != pos[s[r] - '0'].back() || l != pos[s[l] - '0'].front() ? "YES" : "NO") << '\n';
    }
  }
}