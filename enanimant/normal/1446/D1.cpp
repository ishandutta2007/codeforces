// November 13, 2020
// https://codeforces.com/contest/1446/problem/D1

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1446D1.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1446D1.cpp -ggdb && gdb a
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


  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
    ++cnt[a[i]];
  }
  int b = (int) (max_element(cnt.begin(), cnt.end()) - cnt.begin());
  int ans = 0;
  for (int i = 0; i < 100; i++) {
    if (i == b) {
      continue;
    }
    vector<int> first(2 * n + 1, n);
    int pref = 0;
    first[n] = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] == b) {
        pref += 1;
      } else if (a[j] == i) {
        pref -= 1;
      }
      first[pref + n] = min(first[pref + n], j + 1);
      ans = max(ans, j + 1 - first[pref + n]);
    }
  }
  cout << ans << '\n';


  return 0;
}