#include <iostream>
#include <vector>

using namespace std;

int k = 500;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector <int> cnt(2'000'001);
  for (int i = 0; i < n; i++)
    cnt[a[i]]++;
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    if (!cnt[i])
      continue;
    for (int j = 0; j < n; j++)
      if (a[j] >= i)
        ans = max(ans, a[j] % i);
  }
  for (int i = 1; i <= 2'000'000; i++) {
    if (!cnt[i])
      cnt[i] = cnt[i - 1];
    else
      cnt[i] = i;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] <= k)
      continue;
    for (int j = 2 * a[i] - 1; j - a[i] <= 1'000'000; j += a[i]) {
      int p = cnt[j];
      if (p < a[i])
        continue;
      ans = max(ans, p % a[i]);
    }
  }
  cout << ans;
  return 0;
}