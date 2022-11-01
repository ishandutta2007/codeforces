#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  int n = (int) a.size();
  int m = (int) b.size();
  vector <int> cnt(n + 1);
  for (int i = 1; i <= n; i++)
    cnt[i] = cnt[i - 1] + (a[i - 1] - '0');
  int cntb = 0;
  for (int i = 0; i < m; i++)
    cntb += (b[i] - '0');
  int ans = 0;
  for (int l = 1, r = m; r <= n; l++, r++)
    ans += ((cntb + cnt[r] - cnt[l - 1]) % 2 == 0);
  cout << ans;
  return 0;
}