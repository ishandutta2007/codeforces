#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k1, k2, k3;
  cin >> k1 >> k2 >> k3;
  int n = (k1 + k2 + k3);
  vector <int> a(n);
  for (int i = 0; i < k1; i++) {
    int x;
    cin >> x;
    a[x - 1] = 0;
  }
  for (int i = 0; i < k2; i++) {
    int x;
    cin >> x;
    a[x - 1] = 1;
  }
  for (int i = 0; i < k3; i++) {
    int x;
    cin >> x;
    a[x - 1] = 2;
  }
  int ans = k1 + k2;
  int cur = 0;
  vector <int> cntl(3), cntr = {k1, k2, k3};
  for (int i = 0; i < n; i++) {
    cntl[a[i]]++, cntr[a[i]]--;
    cur = max(cur, cntl[0] - cntl[1]);
    ans = min(ans, cntr[0] + cntr[1] + cntl[0] + cntl[2] - cur);
  }
  cout << ans;
  return 0;
}