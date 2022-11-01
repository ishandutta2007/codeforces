#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int pos = 0;
    while (s[pos] != '*')
      pos++;
    int ans = 0;
    while (pos < n) {
      ans++;
      int nxt = pos + k;
      while (nxt >= n || s[nxt] != '*')
        nxt--;
      if (nxt == pos)
        break;
      pos = nxt;
    }
    cout << ans << '\n';
  }
  return 0;
}