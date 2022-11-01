#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_VAL = 15'000'000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int g = 0;
  for (int i = 0; i < n; i++)
    g = __gcd(a[i], g);
  for (int i = 0; i < n; i++)
    a[i] /= g;
  vector <int> lp(MAX_VAL + 1), pr;
  for (int i = 2; i <= MAX_VAL; i++) {
    if (!lp[i]) lp[i] = i, pr.push_back(i);
    for (int j = 0; j < (int) pr.size() && pr[j] <= lp[i] && pr[j] * i <= MAX_VAL; j++)
      lp[pr[j] * i] = pr[j];
  }
  vector <int> cnt(MAX_VAL + 1);
  for (int x : a) {
    while (x != 1) {
      cnt[lp[x]]++;
      int d = lp[x];
      while (x % d == 0)
        x /= d;
    }
  }
  int ans = n - *max_element(cnt.begin(), cnt.end());
  if (ans == n)
    ans = -1;
  cout << ans;
  return 0;
}