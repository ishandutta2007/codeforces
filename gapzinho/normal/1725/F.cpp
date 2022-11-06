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
const int mod = 998244353;

int l[ms], r[ms];
int ans[30];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }
  for(int id = 0; id < 30; id++) {
    int m = (1 << id);
    vector<ii> segs;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      if(r[i] - l[i] + 1 >= m) {
        cnt++;
        continue;
      }
      int lo = l[i] % m, hi = r[i] % m;
      segs.emplace_back(lo, 1);
      segs.emplace_back(hi+1, -1);
      if(hi < lo) {
        cnt++;
      }
    }
    sort(segs.begin(), segs.end());
    ans[id] = cnt;
    for(auto [p, delt] : segs) {
      cnt += delt;
      ans[id] = max(ans[id], cnt);
    }
  }
  int  q;
  cin >> q;
  while(q--) {
    int w;
    cin >> w;
    for(int id = 0; id < 30; id++) {
      if(w & (1 << id)) {
        // cout << "mod = " << (1 << id) << endl;
        cout << ans[id] << '\n';
        break;
      }
    }
  }
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