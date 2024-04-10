// December 30, 2020
// https://codeforces.com/contest/1466/problem/F

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1466F.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1466F.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


const int MOD = (int) 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n, m;
  cin >> n >> m;
  vector<bool> found(m, false); // unit vector found
  vector<int> p(m);
  for (int i = 0; i < m; i++) {
    p[i] = i;
  }
  function<int(int)> Get = [&](int x) {
    if (x == p[x]) {
      return x;
    }
    p[x] = Get(p[x]);
    return p[x];
  };
  auto Unite = [&](int x, int y) {
    x = Get(x);
    y = Get(y);
    if (x == y) {
      return false;
    }
    p[x] = y;
    return true;
  };

  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    if (k == 1) {
      int x;
      cin >> x;
      --x;
      x = Get(x);
      if (found[x]) {
        continue;
      }
      found[x] = true;
      ans.push_back(i);
    }
    if (k == 2) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      x = Get(x);
      y = Get(y);
      if (found[x] && found[y]) {
        continue;
      }
      if (!Unite(x, y)) {
        continue;
      }
      ans.push_back(i);
      if (found[x] || found[y]) {
        found[y] = true;
      }
    }
  }

  long long T = 1;
  int cnt = (int) ans.size();
  for (int i = 0; i < cnt; i++) {
    T = T * 2 % MOD;
  }
  cout << T << ' ' << cnt << '\n';
  for (int i = 0; i < cnt; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << ans[i] + 1;
  }
  cout << '\n';


  return 0;
}