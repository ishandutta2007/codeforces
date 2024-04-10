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
    map<int,int> cnt;
    for(int i=0; i<n; i++) {
      int v;
      cin >> v;
      cnt[v] += 1;
    }

    vector<int> f;
    transform(begin(cnt), end(cnt), back_inserter(f),
        [](const auto& v) { return v.second; });
    sort(begin(f), end(f));

    int ans = n;
    for(int i=1, j=0; i<=n; i++) {
      while(j < size(f) && f[j] < i) {
        j++;
      }
      ans = min(ans, n - i * ((int)size(f) - j));
    }
    cout << ans << nl;
  }

  return 0;
}