// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    vector<pair<int, int>> s(4);
    for (int i = 0; i < 4; ++i) {
      cin >> s[i].first;
      s[i].second = i;
    }
    sort(s.rbegin(), s.rend());
    int sum = (s[0].second + s[1].second); 
    cout << (sum != 1 && sum != 5 ? "YES" : "NO") << '\n';
  }
}