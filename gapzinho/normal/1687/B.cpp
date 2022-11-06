#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;
const int mod = 1e9+7;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int ms = 2e5+5;

int a[ms];

int qry(string &s) {

    cout << "? " << s << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  for(int i = 1; i <= m; i++) {
    s.push_back('0');
  }
  // ii pior = {inf, 0};
  vector<ii> eds;
  for(int i = 0; i < m; i++) {
    s[i] = '1';
    a[i] = qry(s);
    s[i] = '0';
    eds.emplace_back(a[i], i);
    // pior = min(pior, {a[i], i});
  }
  sort(eds.begin(), eds.end());
  int cur = 0;
  for(int idx = 0; idx < m; idx++) {
    int i = eds[idx].second;
    s[i] = '1';
    int tmp = qry(s);
    if(tmp-cur == a[i]) {
      cur = tmp;
    } else {
      s[i] = '0';
    }
  }
  cout << "! " << cur << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}