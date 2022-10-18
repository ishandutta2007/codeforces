#include <bits/stdc++.h>

using i64 = int64_t;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string s;
  cin >> s;
  char cur = 'a';
  int ans = 0;
  for (char ch : s) {
    ans += min((ch - cur + 26) % 26, (cur - ch + 26) % 26);
    cur = ch;
  }
  cout << ans << '\n';
  return 0;
}