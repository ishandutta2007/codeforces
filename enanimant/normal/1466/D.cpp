// December 30, 2020
// https://codeforces.com/contest/1466/problem/D

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1466D.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1466D.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
      cin >> w[i];
    }
    vector<int> deg(n, 0);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      deg[u] += 1;
      deg[v] += 1;
    }
    vector<int> add;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < deg[i] - 1; j++) {
        add.push_back(w[i]);
      }
    }
    sort(add.rbegin(), add.rend());
    long long ans = accumulate(w.begin(), w.end(), 0LL);
    cout << ans;
    for (int i = 0; i < n - 2; i++) {
      ans += add[i];
      cout << ' ' << ans;
    }
    cout << '\n';
  }


  return 0;
}