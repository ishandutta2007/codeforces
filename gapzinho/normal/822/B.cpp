
#include <bit>
#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int inf = 1e9;
const int ms = 1e6+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> curAns;

void solve() {
  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  int ans = n+1;
  for(int i = 0; i+n <= m; i++) {
    int tmp = 0;
    vector<int> tmpAns;
    for(int j = 0; j < n; j++) {
      if(s[j] != t[i+j]) {
        tmp++; 
        tmpAns.emplace_back(j+1);
      }
    }
    if(tmp < ans) {
      ans = tmp;
      curAns = tmpAns;
    }
  }
  cout << ans << endl;
  for(int k : curAns) {
    cout << k << " ";
  }
  cout << endl;
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