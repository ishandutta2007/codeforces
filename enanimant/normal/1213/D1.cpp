// August 30, 2019
// https://codeforces.com/contest/1213/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int INF = (int) 1e9;
const int MAX = 200000;


int n, k;
vector<int> a;

int between(long long lo, long long hi) {
  return upper_bound(a.begin(), a.end(), hi) - lower_bound(a.begin(), a.end(), lo);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < k; i++) {
    ans += 32 - __builtin_clz(a[i]);
  }
  for (long long i = 1; i <= MAX; i++) {
    int rem = k, res = 0;
    for (int j = 0; j < 20; j++) {
      int cnt = between(i << j, (i << j) + (1 << j) - 1);
      int use = min(cnt, rem);
      rem -= use;
      res += j * use;
    }
    if (rem == 0) {
      ans = min(ans, res);
    }
  }
  cout << ans << '\n';


  return 0;
}