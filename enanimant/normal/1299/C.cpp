// March 20, 2020
// https://codeforces.com/contest/1299/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<long long, int>> res;
  for (int i = 0; i < n; i++) {
    long long x = a[i];
    int cnt = 1;
    while (!res.empty() && x * res.back().second < res.back().first * cnt) {
      x += res.back().first;
      cnt += res.back().second;
      res.pop_back();
    }
    res.emplace_back(x, cnt);
  }
  cout.precision(10);
  cout << fixed;
  for (const auto &p : res) {
    for (int i = 0; i < p.second; i++) {
      cout << (double) p.first / p.second << '\n';
    }
  }


  return 0;
}