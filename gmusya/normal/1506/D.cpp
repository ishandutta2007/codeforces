#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef pair <int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    map <int, int> cnt;
    for (int i = 0; i < n; i++) {
      cnt[a[i]]--;
    }
    set <pii> s;
    for (auto &now : cnt) {
      s.insert({now.second, now.first});
    }
    while (!s.empty()) {
      pii x = *s.begin();
      s.erase(x);
      if (s.empty()) {
        s.insert(x);
        break;
      }
      pii y = *s.begin();
      s.erase(y);
      x.first++, y.first++;
      if (x.first) {
        s.insert(x);
      }
      if (y.first) {
        s.insert(y);
      }
    }
    int ans = 0;
    for (pii now : s) {
      ans -= now.first;
    }
    cout << ans << '\n';
  }
  return 0;
}