#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> cnt(150003);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int ans = 0;
  for (int j = 1; j <= 150001; j++) {
    if (cnt[j - 1]) {
      ans++;
      cnt[j - 1]--;
      continue;
    }
    if (cnt[j]) {
      ans++;
      cnt[j]--;
      continue;
    }
    if (cnt[j + 1]) {
      ans++;
      cnt[j + 1]--;
    }
  }
  cout << ans;
  return 0;
}