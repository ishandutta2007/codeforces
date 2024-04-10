#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <ll> cnt(n + 2);
    for (int i = 0; i < n; i++) {
      ll x;
      cin >> x;
      cnt[x]++;
    }
    ll sum123 = 0, sum112 = 0, sum122 = 0, sum111 = 0, sum113 = 0, sum133 = 0;
    for (int i = 1; i <= n; i++) {
      sum111 += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
      sum123 += cnt[i] * (cnt[i - 1]) * (cnt[i + 1]);
      sum112 += cnt[i - 1] * (cnt[i - 1] - 1) * cnt[i] / 2;
      sum122 += cnt[i - 1] * cnt[i] * (cnt[i] - 1) / 2;
      sum113 += cnt[i - 1] * (cnt[i - 1] - 1) * cnt[i + 1] / 2;
      sum133 += cnt[i - 1] * cnt[i + 1] * (cnt[i + 1] - 1) / 2;
    }
    cout << sum111 + sum123 + sum112 + sum122 + sum113 + sum133 << '\n';
  }
  return 0;
}