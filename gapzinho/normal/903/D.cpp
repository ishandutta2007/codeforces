
#include <bit>
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e9;
const int ms = 1e6+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ii a[ms];
ii bit[ms];
int n;

void update(int idx, int v) {
  while(idx <= n) {
    bit[idx].first += v;
    bit[idx].second++;
    idx += idx & -idx;
  }
}

ii query(int idx) {
  ii ans = {0, 0};
  while(idx > 0) {
    ans.first += bit[idx].first;
    ans.second += bit[idx].second;
    idx -= idx & -idx;
  }
  return ans;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i+1;
  }
  sort(a, a+n);
  int i = 0, j = 0;
  __int128_t ans = 0;
  for(int j = 0; j < n; j++) {
    while(a[i].first < a[j].first-1) {
      update(a[i].second, a[i].first);
      i++;
    }
    ii tmp = query(a[j].second);
    ii tmp2 = query(n);
    tmp2.first -= tmp.first;
    tmp2.second -= tmp.second;
    // cout << tmp.second << " " << tmp2.second << endl;
    ans += tmp.first - tmp.second*a[j].first;
    ans += tmp2.second*a[j].first - tmp2.first;
  }
  string s;
  ans = -ans;
  bool isNeg = ans < 0;
  if(isNeg) ans = -ans;
  while(ans > 0) {
    s.push_back((ans % 10) + '0');
    ans /= 10;
  }
  if(s.empty()) {
    s = "0";
  } else if(isNeg) {
    s.push_back('-');
  }
  reverse(s.begin(), s.end());
  cout << s << endl;
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