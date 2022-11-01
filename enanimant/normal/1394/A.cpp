// August 13, 2020
// https://codeforces.com/contest/1394/problem/A

/*

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
  
  
  int n, d, m;
  cin >> n >> d >> m;
  d++;
  vector<int> small, large;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a > m) {
      large.push_back(a);
    } else {
      small.push_back(a);
    }
  }
  sort(large.rbegin(), large.rend());
  sort(small.rbegin(), small.rend());
  vector<long long> f(small.size() + 1, 0);
  for (int i = 0; i < (int) small.size(); i++) {
    f[i + 1] = f[i] + small[i];
  }
  long long ans = 0;
  long long sum_large = 0;
  for (int i = 0; i <= (int) large.size(); i++) {
    int take = min(n + d - 1 - i * d, (int) small.size());
    if (take < 0) {
      break;
    }
    ans = max(ans, f[take] + sum_large);
    if (i == (int) large.size()) {
      break;
    }
    sum_large += large[i];
  }
  cout << ans << '\n';
  
  
  return 0;
}