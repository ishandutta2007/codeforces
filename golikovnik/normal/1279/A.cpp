#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    i64 a, b, c;
    cin >> a >> b >> c;
    if (max({a, b, c}) > (1 + a + b + c - max({a, b, c}))) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
  return 0;
}