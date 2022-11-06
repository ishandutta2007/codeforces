#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 1005;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int l[ms], r[ms];

void solve() {
  int n, k;
  cin >> n >> k;
  string ans;
  int op = 0;
  for(int i = 0; i < n; i++) {
    if(k-i > 0) {
      ans.push_back('(');
      k -= i;
      op++;
    } else {
      while(k != op) {
        ans.push_back(')');
        op--;
      }
      k -= op;
      ans.push_back('(');
      ans.push_back(')');
      while(op) {
        ans.push_back(')');
        op--;
      }
      for(int j = i+1; j < n; j++) {
        ans += "()";
      }
      break;
    }
  }
  if(k) {
    cout << "Impossible\n";
    return;
  }
  while(op) {
    ans.push_back(')');
    op--;
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