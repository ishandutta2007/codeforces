#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
const int ms = 205; // N-i+qntB[i];
const int mod = 1e9+7;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int qnt[ms];


void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ans;
  ans.push_back(s[0]);
  char lst = s[0];
  char befLst = s[0];
  for(int i = 1; i < n; i++) {
    if(s[i] < lst) {
      ans.push_back(s[i]);
      befLst = lst;
      lst = s[i];
    }
    else if(s[i] > lst) break;
    else {
      if(s[i] < befLst) {
        ans.push_back(s[i]);
      } else {
        break;
      }
    }
  }
  cout << ans;
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // #ifdef ONLINE_JUDGE
  //   freopen("grid.in", "r", stdin);
  //   freopen("grid.out", "w", stdout);
  // #endif
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}