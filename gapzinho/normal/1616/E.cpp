#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e18;
const int ms = 1e5+5; // N-i+qntB[i];
const int mod = 1e9+7;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

set<int> st[30];
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

int get(int i) {
  int x = *st[i].begin();
  int p = x;
  x += query(n-p);
  // cout << "Get de " << p << " = " << x << endl;
  return x;
}

void solve() {
  string s, t;
  cin >> n >> s >> t;
  for(int i = 1; i <= n; i++) bit[i] = 0;
  for(int i = 0; i < 26; i++) st[i].clear();
  for(int i = 0; i < n; i++) {
    st[s[i]-'a'].emplace(i);
  }
  int ans = inf, cur = 0;
  for(int i = 0; i < n; i++) {
    int cid = t[i] - 'a';
    for(int j = 0; j < cid; j++) {
      if(!st[j].empty()) {
        // cout  << "Posicao " << i << " letra " << j << " = " << cur + get(j) - i << endl;
        // cout << cur << endl;
        ans = min(ans, cur + get(j) - i);
      }
    }
    if(!st[cid].empty()) {
      cur += get(cid)-i;
      update(n - (*st[cid].begin()), 1);
      st[cid].erase(st[cid].begin());
    } else {
      break;
    }
  }
  if(ans == inf) ans = -1;
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