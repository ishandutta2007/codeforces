#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> cnt(6);
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 4)
      a[i] = 0;
    if (x == 8)
      a[i] = 1;
    if (x == 15)
      a[i] = 2;
    if (x == 16)
      a[i] = 3;
    if (x == 23)
      a[i] = 4;
    if (x == 42)
      a[i] = 5;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      cnt[0]++;
      continue;
    }
    cnt[a[i]] = min(cnt[a[i]] + 1, cnt[a[i] - 1]);
  }
  cout << n - 6 * cnt[5];
  return 0;
}