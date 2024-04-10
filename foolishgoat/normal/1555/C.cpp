#include <bits/stdc++.h>

using namespace std;

int testcase(int tc) {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i)
    cin >> b[i];
  long long lef = 0, rig = 0;
  for (int i = 0; i < n; ++i)
    rig += a[i];
  long long ans = max(lef, rig);
  for (int i = 0; i < n; ++i) {
    rig -= a[i];
    ans = min(ans, max(lef, rig));
    lef += b[i];
  }
  cout << ans << '\n';
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tnum = 1;
  cin >> tnum;
  for (int tc = 1; tc <= tnum; ++tc)
    testcase(tc);
  return 0;
}