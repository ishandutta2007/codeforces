// October 16, 2020
// https://codeforces.com/contest/1428/problem/E

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1428E.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1428E.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


long long Solve(int x, int p) {
  long long m = x / p;
  return m * m * p + (m * 2 + 1) * (x % p);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> cnt(n, 1);
  priority_queue<pair<long long, int>> q;
  for (int i = 0; i < n; i++) {
    q.emplace(Solve(a[i], cnt[i]) - Solve(a[i], cnt[i] + 1), i);
  }
  for (int r = n; r < k; r++) {
    int i = q.top().second;
    q.pop();
    cnt[i]++;
    q.emplace(Solve(a[i], cnt[i]) - Solve(a[i], cnt[i] + 1), i);
  }
  for (int i = 0; i < n; i++) cerr << cnt[i] << ' '; cerr << '\n';
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += Solve(a[i], cnt[i]);
  }
  cout << ans << '\n';


  return 0;
}