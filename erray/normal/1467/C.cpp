// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  const int N = 3;
  vector<int> size(N);
  for (int i = 0; i < N; ++i) {
    cin >> size[i];
  }

  vector<vector<int>> a(N);
  for (int i = 0; i < N; ++i) {
    a[i].resize(size[i]);
    for (int j = 0; j < size[i]; ++j) {
      cin >> a[i][j];
    }
    sort(a[i].begin(), a[i].end());
  }

  vector<long long> sum(N);
  for (int i = 0; i < N; ++i) {
    sum[i] = accumulate(a[i].begin(), a[i].end(), 0LL);
  }

  long long tot = sum[0] + sum[1] + sum[2];
  long long ans = 0;
  {
    vector<int> take = {a[0][0], a[1][0], a[2][0]};
    sort(take.begin(), take.end());
    ans = tot - 2 * (0LL + take[0] + take[1]);
  }

  for (int x = 0; x < N; ++x) {
    ans = max(ans, tot - 2 * sum[x]);
  }

  cout << ans << '\n';
}