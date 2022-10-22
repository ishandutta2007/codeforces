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
    vector<int> a(n);
    vector<int> cnt(3);
    for(int i=0; i<n; i++) {
      cin >> a[i];
      cnt[a[i] % 3] += 1;
    }
    int ans = 0;
    for(int i=0; i<5; i++) {
      int v = i % 3;
      int move = max(0, cnt[v] - n/3);
      cnt[v] -= move;
      cnt[(v+1)%3] += move;
      ans += move;
    }
    cout << ans << nl;
  }

  return 0;
}