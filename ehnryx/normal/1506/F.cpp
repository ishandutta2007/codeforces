#include <bits/stdc++.h>
using namespace std;

constexpr char nl = '\n';
using ll = long long;
int T = -1;

int main() {
  if(T < 0) { cin.tie(0)->sync_with_stdio(0); cin >> T; }
  if(--T) main();

  int n;
  cin >> n;
  vector<int> row(n);
  for(int i=0; i<n; i++) {
    cin >> row[i];
  }
  vector<pair<int,int>> order;
  for(int i=0; i<n; i++) {
    int c;
    cin >> c;
    order.emplace_back(row[i], c);
  }
  sort(begin(order), end(order));
  if(order.front() != pair(1, 1)) {
    order.insert(begin(order), pair(1, 1));
  }

  int ans = 0;
  for(int i=1; i<size(order); i++) {
    auto [r, c] = order[i-1];
    auto [rto, cto] = order[i];
    if(r - c == rto - cto) {
      ans += ((r + c) % 2 == 0) * (rto - r);
    } else {
      ans += (rto - cto) / 2 - (r - c) / 2;
    }
  }
  cout << ans << nl;

  return 0;
}