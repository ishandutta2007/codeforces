#include <iostream>
#include <vector>

using namespace std;

vector <int> a;

int n;

int get(int i) {
  if (i == 0 || i == n - 1)
    return 0;
  if (a[i] > a[i - 1] && a[i] > a[i + 1])
    return 1;
  if (a[i] < a[i - 1] && a[i] < a[i + 1])
    return 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    a.assign(n, 0);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    if (n <= 4) {
      cout << 0 << '\n';
      continue;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += get(i);
    int ans = sum;
    for (int i = 1; i + 1 < n; i++) {
      int cur = sum;
      cur -= get(i - 1);
      cur -= get(i);
      cur -= get(i + 1);
      int oldval = a[i];
      a[i] = a[i - 1];
      cur += get(i - 1);
      cur += get(i);
      cur += get(i + 1);
      ans = min(ans, cur);
      a[i] = oldval;
    }
    for (int i = 1; i + 1 < n; i++) {
      int cur = sum;
      cur -= get(i - 1);
      cur -= get(i);
      cur -= get(i + 1);
      int oldval = a[i];
      a[i] = a[i + 1];
      cur += get(i - 1);
      cur += get(i);
      cur += get(i + 1);
      ans = min(ans, cur);
      a[i] = oldval;
    }
    cout << ans << '\n';
  }
  return 0;
}