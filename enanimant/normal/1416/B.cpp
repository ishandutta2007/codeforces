// September 27, 2020
// https://codeforces.com/contest/1416/problem/B

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1416B.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1416B.cpp -ggdb && gdb a
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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum % n != 0) {
      cout << "-1\n";
      continue;
    }
    vector<tuple<int, int, int>> ops;
    for (int i = 2; i <= n; i++) {
      int r = a[i] % i;
      if (r != 0) {
        assert(a[1] >= i - r);
        ops.emplace_back(1, i, i - r);
        a[1] -= i - r;
        a[i] += i - r;
      }
      assert(a[i] % i == 0);
      int x = a[i] / i;
      ops.emplace_back(i, 1, x);
      a[i] -= i * x;
      a[1] += i * x;
    }
    for (int i = 2; i <= n; i++) {
      ops.emplace_back(1, i, sum / n);
    }
    cout << ops.size() << '\n';
    for (const auto& t : ops) {
      int i, j, x;
      tie(i, j, x) = t;
      cout << i << ' ' << j << ' ' << x << '\n';
    }
  }


  return 0;
}