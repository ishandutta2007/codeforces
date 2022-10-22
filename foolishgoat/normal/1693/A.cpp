#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  while (a.size() > 0 && a.back() == 0) a.pop_back();
  n = a.size();
  if (n == 0) {
    puts("Yes");
    return;
  }
  bool ok = 1;
  long long tot = 0;
  for (int i = 0; i < n; ++i) {
    tot += a[i];
    ok &= (i+1 == n) ? tot == 0 : tot > 0;
  }
  puts(ok ? "Yes" : "No");
}

int main() {
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}