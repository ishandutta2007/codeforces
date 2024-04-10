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
  int N, M;
  cin >> N >> M;
  auto Ask = [&](string s) {
    cout << "? " << s << endl;
    int res;
    cin >> res;
    return res;
  };

  vector<int> l(M);
  for (int i = 0; i < M; ++i) {
    string s(M, '0');
    s[i] = '1';
    l[i] = Ask(s);
  }

  vector<int> ord(M);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int x, int y) {
    return l[x] < l[y];
  });

  int ans = 0;
  string s(M, '0');
  for (auto i : ord) {
    s[i] = '1';
    if (Ask(s) == ans + l[i]) {
      ans += l[i];
    } else {
      s[i] = '0';
    }
  }
  cout << "! " << ans << endl;
}