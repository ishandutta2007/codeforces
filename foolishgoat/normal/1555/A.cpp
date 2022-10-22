#include <bits/stdc++.h>

using namespace std;

int testcase(int tc) {
  long long n;
  cin >> n;
  long long ans = ((n + 1) / 2) * 5;
  ans = max(ans, 15LL);
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