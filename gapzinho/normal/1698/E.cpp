#include <bits/stdc++.h>
using namespace std;

#define int long long

using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int ms = 1e6+5;

int n;
int pos[ms];
int a[ms], b[ms];
int exst[ms];

void solve() {
  int s;
  cin >> n >> s;
  int possib = 0;
  for(int i =1 ;  i <= n; i++){
    exst[i] = 0;
  }
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
    exst[b[i]] = 1;
  }
  int ans = 1;
  for(int i = n; i > n-s; i--) {
    if(!exst[i]) {
      possib++;
    }
  }
  for(int i = n; i > 0; i--) {
    int hlp = i-s;
    if(hlp > 0 && !exst[hlp]) {
      possib++;
    }
    int k = pos[i];
    if(b[k] != -1) {
      if(b[k] < i - s) {
        cout << 0 << '\n';
        return;
      }
    } else {
      ans = ans * possib % mod;
      possib--;
    }
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(3);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}