#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e18;
const int ms = 1e5+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, a, b, c;
int sz, fst;
int q[2];
int ans;
string s;
vector<int> vQnt0;

void help(int st) {
  fst = s[0] - '0';
  sz = 1;
  q[0] = q[1] = 0;
  vQnt0.clear();
  if(fst == 0) {
    vQnt0.emplace_back(0);
  }
  for(int i = 1; i < n; i++) {
    if(s[i] != s[i-1]) {
      sz++;
      if(s[i] == '0') {
        vQnt0.emplace_back(0);
      }
    } else {
      q[s[i] - '0']++;
      if(s[i] == '0') {
        vQnt0[(int)vQnt0.size()-1]++;
      }
    }
  }
  int l = 0;
  int r = vQnt0.size();
  int rem0 = 0;
  
  stack<int> stac;
  int cIdx = 0;
  int qntBad0 = 0;
  if(fst == 0) {
    sz--;
    qntBad0++;
    l++;
  }
  if(sz % 2 == 0) {
    qntBad0++;
    r--;
  }
  vector<int> hlp;
  for(int i = l; i < r; i++) {
    hlp.emplace_back(vQnt0[i]);
  }
  sort(hlp.begin(), hlp.end());
  int cur = 0;
  int qntPodendoRoubar = 0;
  while(cIdx < (int) hlp.size() && hlp[cIdx] == 0) {
    cIdx++;
    qntPodendoRoubar++;
  }
  // cout << sz << " " << q[0] << " " << q[1] << endl;
  while(true) {
    if (st == 0) {
      if (q[0] > 0) {
        q[0]--;
        rem0++;
        stac.emplace(cIdx);
        cur += a;
        if(cIdx < (int) hlp.size()) hlp[cIdx]--;
        while(cIdx < (int) hlp.size() && hlp[cIdx] == 0) {
          cIdx++;
          qntPodendoRoubar++;
        }
      } else if(sz >= 3) {
        cur -= c;
        sz -= 2;
        q[1]++;
        qntPodendoRoubar--;
      } else if(qntBad0 > 0) {
        qntBad0--;
        cur -= c;
      } else {
        return;
      }
    } else {
      if(q[1] > 0) {
        q[1]--;
        cur += b;
      } else if(qntPodendoRoubar > 0 && rem0 > 0 && sz >= 3) {
        if(stac.top() != cIdx) {
            cIdx = stac.top();
            hlp[cIdx]++;
            qntPodendoRoubar--;
        } else if(cIdx < (int) hlp.size()) {
            hlp[cIdx]++;
        }
        stac.pop();
        if(qntPodendoRoubar == 0) return;
        qntPodendoRoubar--;
        rem0--;
        q[0]++;
        cur -= a;
        q[1]++;
        sz -= 2;
        cur -= c;
        q[1]--;
        cur += b;
      } else {
        return;
      }
    }
    // cout << "tmp : " << cur << endl;
    st = !st;
    ans = max(ans, cur);
  }
}

void solve() {
  cin >> n >> a >> b >> c;
  cin >> s;
  ans = 0;
  help(0);
  help(1);
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