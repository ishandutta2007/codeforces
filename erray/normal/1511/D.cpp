// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> next(k);
  int now = k - 1;
  string ans(n, '*');
  for (int i = 0; i < n; ++i) {
    ans[i] = now + 'a';
    now = next[now]++ % k;
  } 
  cout << ans << '\n';
}