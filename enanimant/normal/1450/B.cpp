// December 6, 2020
// https://codeforces.com/contest/1450/problem/B

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1450B.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1450B.cpp -ggdb && gdb a
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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    if ((int) p.size() == 1) {
      cout << "0\n";
    } else {
      bool ok = false;
      for (int i = 0; i < n; i++) {
        bool works = true;
        for (int j = 0; j < n; j++) {
          if (abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second) > k) {
            works = false;
          }
        }
        if (works) {
          ok = true;
        }
      }
      cout << (ok ? 1 : -1) << '\n';
    }
  }


  return 0;
}