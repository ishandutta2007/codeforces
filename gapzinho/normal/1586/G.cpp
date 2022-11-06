
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e18;
const int ms = 2e5+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<pair<ii, int>> events;
vector<int> s;
vector<int> ndd;
int a[ms], b[ms];
int bit[2*ms];
int sz;

int qry(int i) {
  i = sz-i+1;
  int ans = 0;
  while(i > 0) {
    ans += bit[i];
    ans %= mod;
    i -= i & -i;
  }
  return ans;
}

void upd(int i, int v) {
  i = sz-i+1;
  while(i <= sz) {
    bit[i] += v;
    bit[i] %= mod;
    i += i & -i;
  }
}

void solve() {
  int n;
  cin >> n;
  sz = 2*n;
  events.resize(n+1);
  for(int i = 1; i <= n; i++) {
    events[i].second = i;
    cin >> a[i] >> b[i];
    events[i].first = {b[i], a[i]};
  }
  int t;
  cin >> t;
  s.resize(t);
  for(int i = 0; i < t; i++) {
    cin >> s[i];
  }
  a[0] = 0, b[0] = 2*n+1;
  ndd.emplace_back(0);
  sort(s.begin(), s.end(), [](auto i, auto j) {return b[i] > b[j]; });
  sort(events.begin(), events.end());
  for(int i : s) {
    int lst = *ndd.rbegin();
    if(a[i] > a[lst]) ndd.emplace_back(i);
  }
  reverse(ndd.begin(), ndd.end());
  int ansNeeded = ndd.size() -1;
  int curAdded = 0;
  int ans = 0;
  upd(2*n, 1);
  for(int i = 1; i <= n && curAdded < ansNeeded; i++) {
    int id = events[i].second;
    auto &[y, x] = events[i].first;
    // cout << id << " " << x << " " << y << endl;
    if(id == ndd[curAdded]) {
      ans += qry(a[ndd[curAdded+1]]);
      ans %= mod;
      curAdded++;
      // cout << "adicionando " << a[id] << " " << b[id] << endl;
    }
    upd(x, qry(x));
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // t = inf;
  // cin >> t;
  // cout << fixed << setprecision(9);
  while (t--) {
      solve();
  }
  return 0;
}