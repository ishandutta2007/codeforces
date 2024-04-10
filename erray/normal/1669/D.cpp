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
    int N;
    string S;
    cin >> N >> S;
    S += 'W';
    int p = 0;
    bool ok = true;
    for (int i = 0; i <= N; ++i) {
      if (S[i] == 'W') {
        vector<int> a;
        while (p < i) {
          a.push_back(S[p] == 'B');
          ++p;
        }
        ++p;
        ok &= (a.empty() || count(a.begin(), a.end(), a[0] ^ 1) != 0);
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}