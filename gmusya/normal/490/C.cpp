#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  ll a, b;
  cin >> a >> b;
  vector <ll> pre(n), suf(n);
  pre[0] = (s[0] - '0') % a;
  for (int i = 1; i < n; i++)
    pre[i] = (pre[i - 1] * 10 + (s[i] - '0')) % a;
  suf[n - 1] = (s[n - 1] - '0') % b;
  ll ten = 10;
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = (suf[i + 1] + ten * (s[i] - '0')) % b;
    ten = (ten * 10) % b;
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == '0')
      continue;
    if (pre[i - 1] == 0 && suf[i] == 0) {
      cout << "YES\n";
      for (int j = 0; j < i; j++)
        cout << s[j];
      cout << '\n';
      for (int j = i; j < n; j++)
        cout << s[j];
      return 0;
    }
  }
  cout << "NO";
  return 0;
}