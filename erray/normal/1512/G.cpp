// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  const int N = (int) 1e7;
  vector<int> ans(N + 1, -1);
  vector<long long> me(N + 1);
  for (int i = 1; i * i <= N; ++i) {
    for (int j = i * i; j <= N; j += i) {
      me[j] += i;
      if (j != i * i) {
        me[j] += j / i;
      }
    }
  }
  for (int i = N; i > 0; --i) {
    if (me[i] > N) {
      continue;
    }
    ans[me[i]] = i;
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << ans[n] << '\n';
  }
}