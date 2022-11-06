#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
using ull = uint64_t;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
using ld =  long double;
const int inf = 0x3f3f3f3f3f3f3f3f;
 
const int ms = 1e5+5;
const int mod = 1e9+7;

vector<ii> g[ms][2];
int d[ms][2];

vector<int> v;
int ans = 0;

vector<int> mg(int l, int r) {
  if(r - l == 1) {
    return {v[l]};
  }
  int mi = (l+r)/2;
  auto a = mg(l, mi);
  auto b = mg(mi, r);
  vector<int> ret;
  ret.reserve(r-l);
  int i = 0, j = 0;
  while(i < (int) a.size() && j < (int) b.size()) {
    if(a[i] <= b[j]) {
      ret.emplace_back(a[i++]);
    } else {
      ret.emplace_back(b[j++]);
      ans += (int) a.size() - i;
    }
  }
  while(i < (int) a.size()) {
    ret.emplace_back(a[i++]);
  }
  while(j < (int) b.size()) {
    ret.emplace_back(b[j++]);
  }
  // l = 5, r = 9, mi = 7
  return ret;
}

void solve() {
  int n;
  cin >> n;
  v.resize(n);
  for(int &x : v) {
    cin >> x;
  }
  int hi = v[0];
  int lo = v[0];
  for(int i = 1; i < n; i++) {
    v[i] += v[i-1];
    hi = max(hi, v[i]);
    lo = min(lo, v[i]);
    if(v[i] < 0) {
      cout << -1 << '\n';
      return;
    }
  }
  if(v[n-1] != hi || v[0] < 0) {
    cout << -1 << '\n';
    return;
  }
  mg(0, n);
  cout << ans << '\n';
}
 
 
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int T = 1; T <= t; T++) {
    // cout << "Case #" << T << ": ";
    solve(); 
  }
  return 0;
}