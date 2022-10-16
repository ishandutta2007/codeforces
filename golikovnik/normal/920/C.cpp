#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
    --x;
  }
  string can;
  cin >> can;
  
  vector<bool> used(n);
  for (int l = 0; l < n - 1; ++l) {
    int r = l;
    while (r < n - 1 && can[r] == '1') {
      r++;
    }
    for (int i = l; i <= r; ++i) {
      used[a[i]] = true;
    }
    for (int i = l; i <= r; ++i) {
      if (!used[i]) {
        cout << "NO\n";
        return 0;
      }
    }
    l = r;
  }
  cout << "YES\n";
  return 0;
}