#include <bits/stdc++.h>
using namespace std;

constexpr char nl = '\n';
using ll = long long;
int T = -1;

int main() {
  if(T < 0) { cin.tie(0)->sync_with_stdio(0); cin >> T; }
  if(--T) main();

  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  auto first = find(begin(s), end(s), '*');
  if(first != end(s)) *first = 'x';
  auto last = find(rbegin(s), rend(s), '*');
  if(last != rend(s)) *last = 'x';

  int ans = 0;
  for(int i=0, j=n, o=-1; i<n; i++) {
    if(s[i] == 'x' || s[i] == '*') {
      if(o != -1 && i-j > k) {
        ans++;
        j = o;
      }
      if(s[i] == 'x') {
        ans++;
        j = i;
      }
      o = i;
    }
  }
  cout << ans << nl;

  return 0;
}