#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
const int ms = 1e5 + 5;
const int mod = 1e9+7;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;


void solve() {
  map<int, int> st;
  vector<iii> frnds;
  int n, m, c, c0;
  cin >> n >> m >> c >> c0;
  int cur = c0;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    frnds.emplace_back(t, a, b);
  }
  sort(frnds.begin(), frnds.end());
  frnds.emplace_back(m, 0, 0);
  int curT = 0;
  st[0] = c0;
  for(auto [t, a, b] : frnds) {
    // cout << "starting at " << cur << endl;
    while(t-curT > 0) {
      if(st.empty()) {
        // cout << curT << " -> " << t << endl;
        cout << -1 << '\n';
        return;
      }
      auto &[cst, sz] = *st.begin();
      int qntRemoved = min(sz, t-curT);
      // cout << "removed " << qntRemoved << " with price " << cst << " and now " << curT << " => " << t << endl;
      ans += qntRemoved * cst;
      curT += qntRemoved;
      sz -= qntRemoved;
      cur -= qntRemoved;
      if(sz == 0) {
        st.erase(cst);
      }
    }
    st[b] += a;
    cur += a;
    while(cur > c) {
      auto &[cst, sz] = *st.rbegin();
      int qntRemoved = min(sz, cur-c);
      cur -= qntRemoved;
      sz -= qntRemoved;
      if(sz == 0) {
        st.erase(cst);
      }
    }
  }
  cout << ans << '\n';
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
    solve(); 
  }
  return 0;
}