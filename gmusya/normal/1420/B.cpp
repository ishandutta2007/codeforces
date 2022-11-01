#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector <long long> cnt(31);
    for (int i = 0; i < n; i++)
      for (int pow = 30; pow >= 0; pow--)
        if (a[i] & (1 << pow)) {
          cnt[pow]++;
          break;
        }
    long long ans = 0;
    for (int i = 0; i <= 30; i++)
      ans += cnt[i] * (cnt[i] - 1) / 2;
    cout << ans << '\n';
  }
  return 0;
}