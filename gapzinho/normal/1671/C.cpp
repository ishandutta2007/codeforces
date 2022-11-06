#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
const int ms = 1e6+5;
const int mod = 1e9+7;
using ull = uint64_t;
#define endl '\n'
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;

int a[ms];

void solve() {
  int n, x;
  cin >> n >> x;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);
  for(int i = 1; i < n; i++) {
    a[i] += a[i-1];
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(x < a[i]) continue;
    ans += (x-a[i])/(i+1) + 1;
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  cin >> t;
  while (t--) {
    // T++;
    solve(); 
  }
  return 0;
}