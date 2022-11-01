#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <int> cnt(16384);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  ll ans = 0;
  for (int mask = 0; mask < 16384; mask++) {
    int it = 0;
    for (int i = 0; i < 14; i++)
      if ((1 << i) & mask)
        it++;
    if (it != k)
      continue;
    for (int i = 0; i < 16384; i++) {
      if (mask == 0) {
        ans += cnt[i] * 1ll * (cnt[i] - 1) / 2;
        continue;
      }
      if ((i ^ mask) > i)
        continue;
      ans += cnt[i] * 1ll * cnt[i ^ mask];
    }
  }
  cout << ans;
  return 0;
}