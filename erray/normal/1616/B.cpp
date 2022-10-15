// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
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
    if (N == 1 || S[0] == S[1]) {
      cout << ""s + S[0] + S[0] << '\n';
      continue;
    }
    int p = 0;
    while (p < N - 1 && S[p] >= S[p + 1]) {
      ++p;
    }
    string res = S.substr(0, p + 1);
    cout << res + string(res.rbegin(), res.rend()) << '\n';
  }
}