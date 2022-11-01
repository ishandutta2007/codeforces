#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    b[i] = c - '0';
  }
  vector <int> pre(n);
  for (int i = 0; i < n; i++)
    pre[i] = (i ? pre[i - 1] : 0) + a[i];
  vector <int> suf(n), mi(n);
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = (i != n - 1 ? suf[i + 1] : 0) + (b[i] ? a[i] : 0);
    mi[i] = (b[i] ? min(a[i], (i != n - 1 ? mi[i + 1] : INF)) : (i != n - 1 ? mi[i + 1] : INF));
  }
  int ans = suf[0];
  for (int i = 0; i < n; i++)
    ans = max(ans, suf[i] - mi[i] + (i ? pre[i - 1] : 0));
  cout << ans;
  return 0;
}