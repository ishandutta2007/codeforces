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
    cin >> N;
    set<string> two_two;
    set<string> three_two;
    set<string> three_three;
    bool ans = false;
    for (int i = 0; i < N; ++i) {
      string S;
      cin >> S;
      string r = string(S.rbegin(), S.rend());
      if (S == r) {
        ans = true;
      } else if (int(S.size()) == 2) {
        ans |= three_two.count(r) || two_two.count(r);
        two_two.insert(S);   
      } else {
        ans |= three_three.count(r) || two_two.count(string(r.begin(), r.begin() + 2));
        three_three.insert(S);
        three_two.insert(string(S.begin(), S.begin() + 2));
      }
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
}