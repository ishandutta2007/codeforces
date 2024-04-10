#include <bits/stdc++.h>

using namespace std;


void solve() {
  long long n, s;
  cin >> n >> s;
  n = n / 2 + 1;
  cout << s / n << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    solve();
  }
  return 0;
}