#include <bits/stdc++.h>

using namespace std;

const int N = 6006;

bitset<N> bs[N];

long long pick3(long long n) {
  long long ret = n * (n - 1) / 2;
  ret = ret * (n - 2) / 3;
  return ret;
}

long long pick2(long long n) {
  return n * (n - 1) / 2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  int cnt[2][2];
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    x[i] /= 2;
    y[i] /= 2;
    ++cnt[x[i] & 1][y[i] & 1];
  }
  long long ans = 0;
  for (int i = 0; i < 2; ++i) {
    int tot = cnt[i][0] + cnt[i][1];
    ans += pick3(tot);

    tot = cnt[0][i] + cnt[1][i];
    ans += pick3(tot);

    for (int j = 0; j < 2; ++j) {
      ans -= 1LL * pick3(cnt[i][j]);
      ans += pick2(cnt[i][j]) * cnt[i^1][j^1];
    }
  }

  cout << ans << '\n';
  return 0;
}