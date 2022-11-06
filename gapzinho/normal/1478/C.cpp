#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 2e5+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e9+1;

int d[ms];
int a[ms];
int ans[ms];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < 2*n; i++) {
    cin >> d[i];
  }
  sort(d, d+2*n);
  for(int i = 0; i < 2*n; i+=2) {
    if(d[i] != d[i+1]) {
      cout << "NO" << '\n';
      return;
    }
  }
  for(int i = 0; i < n; i++) {
    a[i] = d[i*2];
  }
  if(a[0] % 2) {
      cout << "NO" << '\n';
      return;
  }
  int cur = 0;
  for(int i = 1; i < n; i++) {
    if(a[i] % 2) {
      cout << "NO" << '\n';
      // cout << "1" << endl;
      return;
    }
    ans[i] = ans[i-1] + (a[i] - a[i-1])/(i*2);
    cur += ans[i]*2;
    if(ans[i] == ans[i-1]) {

      cout << "NO" << '\n';
      // cout << "2" << endl;
      return;
    }
    if((a[i] - a[i-1]) % (i*2)) {
      cout << "NO" << '\n';
      // cout << "2" << endl;
      return;
    }
  }
  if(cur >= a[0]) {
      cout << "NO" << '\n';
      // cout << "3" << endl;
      return;
  }
  // cout << a[0] << ' ' << cur << endl;
  if ((a[0]-cur)%(2*n)) {
    cout << "NO" << '\n';
    // cout << "4" << endl;
    return;
  }
  cout << "YES" << '\n';
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
      solve();
  }
  return 0;
}