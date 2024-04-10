#include <bits/stdc++.h>
using namespace std;

constexpr char nl = '\n';
using ll = long long;
int T = -1;

int main() {
  if(T < 0) { cin.tie(0)->sync_with_stdio(0); cin >> T; }
  if(--T) main();

  string a, b;
  cin >> a >> b;
  unordered_set<string> sub_b;
  for(int i=0; i<size(b); i++) {
    for(int j=0; i+j<size(b); j++) {
      sub_b.insert(b.substr(i, j+1));
    }
  }
  int ans = size(a) + size(b);
  for(int i=0; i<size(a); i++) {
    for(int j=0; i+j<size(a); j++) {
      if(sub_b.count(a.substr(i, j+1))) {
        ans = min(ans, (int)(size(a) + size(b)) - 2 * (j+1));
      }
    }
  }
  cout << ans << nl;

  return 0;
}