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
    string S;
    cin >> S;
    int n = int(S.size());
    vector<int> pos;
    int o = 0;
    for (int i = 0; i < n; ++i) {
      if (S[i] != '?') {
        o += (S[i] == '(');
      } else {
        pos.push_back(i);
      }
    }
    auto Balanced = [&](string s) {
      int sum = 0;
      for (int i = 0; i < n; ++i) {
        sum += (s[i] == '(' ? +1 : -1);
        if (sum < 0) {
          return false;
        }
      }
      return sum == 0;
    };
    int last = n / 2 - o;
    auto good = S;
    for (int i = 0; i < int(pos.size()); ++i) {
      good[pos[i]] = (i < last ? '(' : ')');
    }
    assert(Balanced(good));
    if (last < int(pos.size())) {
      good[pos[last]] = '(';
    }
    if (last - 1 >= 0) {
      good[pos[last - 1]] = ')';
    }
    cout << (Balanced(good) && !pos.empty() ? "NO" : "YES") << '\n';
  }
}