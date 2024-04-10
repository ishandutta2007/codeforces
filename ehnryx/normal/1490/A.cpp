#include <bits/stdc++.h>
using namespace std;

constexpr char nl = '\n';

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
      cin >> a[i];
      if(i > 0) {
        int x = a[i];
        int y = a[i-1];
        if(x > y) swap(x, y);
        for(x *= 2; x < y; x *= 2) {
          ans++;
        }
      }
    }
    cout << ans << nl;
  }

  return 0;
}