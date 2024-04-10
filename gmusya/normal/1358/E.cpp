#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < (n + 1) / 2; i++)
    cin >> a[i];
  int x;
  cin >> x;
  for (int i = (n + 1) / 2; i < n; i++)
    a[i] = x;
  vector <ll> pre(n + 1);
  for (int i = 1; i <= n; i++)
    pre[i] = pre[i - 1] + a[i - 1];
  if (x <= 0) {
    int k = 0;
    while (k <= n && pre[n] - pre[n - k - 1] <= 0)
      k++;
    bool flag = true;
    for (int i = (n + 1) / 2; i >= 1; i--)
      while (i + k <= n && pre[i + k] - pre[i - 1] <= 0)
        k++;
    if (!flag || k >= n)
      k = -2;
    cout << k + 1;
    return 0;
  }
  int k = 0;
  for (int i = (n + 1) / 2; i >= 1; i--) {
    while (i + k < n && pre[i + k] - pre[i - 1] <= 0)
      k++;
    if (pre[i + k] - pre[i - 1] <= 0)
      k++;
  }
  if (k >= n)
    k = -2;
  cout << k + 1;
  return 0;
}