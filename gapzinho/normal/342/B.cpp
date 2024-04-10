#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 2e5+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int s[ms];
int t[ms], l[ms], r[ms];

void solve() {
  int n, m, s, f;
  cin >> n >> m >> s >> f;
  string ans;
  for(int i = 0; i < m; i++) {
    cin >> t[i] >> l[i] >> r[i];
  }
  int curT = 1;
  int curP = 0;
  while(s != f) {
    int go = s;
    if(f > s) go++;
    else go--;
    char cc = f > s ? 'R' : 'L';
    if(t[curP] == curT) {
      if(s >= l[curP] && s <= r[curP]) ans.push_back('X');
      else if(go >= l[curP] && go <= r[curP]) ans.push_back('X');
      else {
        s = go;
        ans.push_back(cc);
      }
      curT++;
      curP++;
    } else {
      s = go;
      ans.push_back(cc);
      curT++;
    }
  }
  cout << ans << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
      solve();
  }
  return 0;
}