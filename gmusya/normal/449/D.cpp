#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <int> p2(1 << 20);
  p2[0] = 1;
  for (int i = 1; i < (1 << 20); i++) {
    p2[i] = p2[i - 1] * 2;
    if (p2[i] >= MOD)
      p2[i] -= MOD;
  }
  int n;
  cin >> n;
  vector <int> cnt(1 << 20);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  for (int p = 0; p < 20; p++)
    for (int i = 0; i < (1 << 20); i++)
      if (i & (1 << p))
        cnt[i ^ (1 << p)] += cnt[i];
  int ans = 0;
  for (int i = 0; i < (1 << 20); i++) {
    int tmp = 0;
    for (int p = 0; p < 20; p++)
      if (i & (1 << p))
        tmp++;
    if (tmp & 1)
      ans -= p2[cnt[i]];
    else
      ans += p2[cnt[i]];
    if (ans < 0)
      ans += MOD;
    if (ans >= MOD)
      ans -= MOD;
  }
  cout << ans;
  return 0;
}