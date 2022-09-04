#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(x) begin(x),end(x)

pair<int,int> pos[1505*1505];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n; cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  vector<int> rows(n), cols(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      pos[a[i][j]] = {i, j};
    }
  }
  ll ans = 0;
  for (int a = 1; a <= n*n; a++) {
    auto [i, j] = pos[a];
    int x = rows[i];
    int y = cols[j];
    ll add = 1LL * x * (n-1-y) + 1LL * y * (n-1-x);
    ans += add;
    rows[i]++;
    cols[j]++;
  }
  ans /= 2;
  cout << ans << '\n';
}