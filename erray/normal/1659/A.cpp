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
  int TT;
  cin >> TT;
  while (TT--) {
    int N, R, B;
    cin >> N >> R >> B;
    vector<int> a(B + 1);
    for (int i = 1; i < B; ++i) {
      a[i] = 1;
      --R;
    }
    while (R--) {
      a[min_element(a.begin(), a.end()) - a.begin()] += 1;
    }
    for (int i = 0; i <= B; ++i) {
      if (i > 0) {
        cout << 'B';
      }
      cout << string(a[i], 'R');
    }
    cout << '\n';
  }
}