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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    set<int> cur;

    for (int i = 0; i < n; ++i) {
      if (cur.count(a[i] + 1) == 0) {
        ++a[i];
      }
      cur.insert(a[i]);
    }
    sort(a.rbegin(), a.rend());

    a.erase(unique(a.begin(), a.end()), a.end());
    cout << (int) a.size() << '\n';
  }
}