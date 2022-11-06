#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 2e5+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e9+1;
ii f[ms];
ii f2[ms];
int n, s;

bool check(int mi) {
  int cur = 0;
  int cnt = 0;
  for(int i = n-1; i >= 0; i--) {
    if(f[i].second < mi || cnt == (1 + n/2)) {
      cur += f[i].first;
    } else {
      cur += max(mi, f[i].first);
      cnt++;
    }
  }
  return cnt == (1 + n/2) && cur <= s;
}

void solve() {
  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    cin >> f[i].first >> f[i].second;
  }
  sort(f, f+n);
  int lo = f[n/2].first, hi = inf;
  while(lo < hi) {
    int mi = (lo+hi+1)/2;
    if(check(mi)) {
      lo = mi;
    } else {
      hi = mi-1;
    }
  }
  cout << lo << '\n';
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
      solve();
  }
  return 0;
}