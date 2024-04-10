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
    string S;
    int N;
    cin >> N >> S;
    int c = count(S.begin(), S.end(), '0');
    vector<vector<int>> ans;
    while (!is_sorted(S.begin(), S.end())) {
      vector<int> m;
      for (int i = 0; i < N; ++i) {
        if (S[i] - '0' != i >= c) {
          m.push_back(i);
        }
      }

      for (int i = 0; i < int(m.size()) / 2; ++i) {
        swap(S[m[i]], S[m[int(m.size()) - i - 1]]);
      }
      ans.push_back(m);
    }

    cout << int(ans.size()) << '\n';
    for (auto v : ans) {
      cout << int(v.size()) << ' ';
      for (auto e : v) {
        cout << e + 1 << ' ';
      }
      cout << '\n';
    }
  }
}