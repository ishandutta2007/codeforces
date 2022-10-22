#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

/// #define int ll

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int w1, w2;
    cin >> w1 >> w2;
    set<int> s;
    for (int step = 0; step < 2; step++) {
      int s1 = (w1 + w2) / 2, s2 = w1 + w2 - s1;
      for (int b1 = 0; b1 <= s2; b1++) {
        //for (int b2 = 0; b2 <= s1; b2++) {
          int b2 = b1 + s1 - w1;

          if (0 <= b2 && b2 <= s1 && w1 == b1 + s1 - b2 && w2 == b2 + s2 - b1) {
            s.insert(b1 + b2);
          }
        //}
      }
      swap(w1, w2);
    }
    cout << (int) s.size() << "\n";
    for (auto &i : s) {
      cout << i << " ";
    }
    cout << "\n";
  }

	return 0;
}