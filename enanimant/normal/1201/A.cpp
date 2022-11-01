// August 4, 2019
// https://codeforces.com/contest/1201/problem/A

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


  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    vector<int> cnt(5, 0);
    for (int j = 0; j < n; j++) {
      cnt[v[j][i] - 'A']++;
    }
    int M = 0;
    for (int j = 0; j < 5; j++) {
      M = max(M, cnt[j]);
    }
    int p;
    cin >> p;
    ans += p * M;
  }
  cout << ans << '\n';


  return 0;
}