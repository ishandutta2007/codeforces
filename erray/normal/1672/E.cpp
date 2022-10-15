// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  auto Ask = [&](int x) {
    cout << "? " << x << endl;
    int res;
    cin >> res;
    return res;
  };

  int low = 1, high = int(3e7);
  while (low < high) {
    int mid = (low + high) >> 1;
    if (Ask(mid) != 1) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  int mx = low;
  int ans = mx;
  for (int i = 2; i <= N; ++i) {
    int need = (mx - 1) / i;
    if (need > 0 && Ask(need) == i) {
      ans = min(ans, need * i);
    }
  }
  cout << "! " << ans << endl;
}