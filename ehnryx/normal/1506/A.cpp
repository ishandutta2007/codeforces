#include <bits/stdc++.h>
using namespace std;

constexpr char nl = '\n';
using ll = long long;
int T = -1;

int main() {
  if(T < 0) { cin.tie(0)->sync_with_stdio(0); cin >> T; }
  if(--T) main();

  int n, m; ll x;
  cin >> n >> m >> x;
  auto [i, j] = pair((x-1) / n, (x-1) % n);
  cout << j*m + i + 1 << nl;

  return 0;
}