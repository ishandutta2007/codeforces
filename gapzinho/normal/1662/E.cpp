#include <bits/stdc++.h>
using namespace std;

#define int long long

using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
using ld =  long double;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int ms = 2e5+5;

int bit[ms], n;

void update(int idx, int v) {
  while(idx <= n) {
    bit[idx] += v;
    idx += idx & -idx;
  }
}

int query(int idx) {
  int ans = 0;
  while(idx > 0) {
    ans += bit[idx];
    idx -= idx & -idx;
  }
  return ans;
}

int a[ms], p[ms];

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    p[a[i]] = i;
    bit[i] = 0;
  }
  int ans = 0;
  int cur = 1;
  for(int i = 1; i <= n; i++) {
    int cst = p[i] > cur ? query(p[i]) - query(cur) : query(n) - query(cur) + query(p[i]);
    ans += (n-i+1) * cst;
    update(p[i], 1);
    cur = p[i];
  }
  cout << ans << endl;
}



int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
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