#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
using ull = uint64_t;
using ii = pair<int, int>;
using iii = pair<int, ii>;
// using i4 = tuple<int, int, int, int>;
using i4 = pair<ii, ii>;
using ll = long long;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int ms = 2e5+5;

int cnt[300];

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    memset(cnt, 0, sizeof cnt);
    for(char c : s) {
      cnt[c]++;
    }
    cnt['a' - 1] = inf;
    for(char c = 'b'; c < 'z'; c++) {
      cnt[c] = min(cnt[c], cnt[c-1]);
    }
    char cur = min('z', (char) ('a' + min(n/k, 25ll)));
    for(int i = 0; i < k; i++) {
      while(cnt[cur-1] <= i) {
        cur--;
      }
      cout << cur;
    }
    cout << '\n';
}
 
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int T = 1; T <= t; T++) {
    // cout << "Case #" << T << ": ";
    solve(); 
  }
  return 0;
}