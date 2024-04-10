#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int ms = 1e6+5;

ii a[ms];


void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i].first;
  }
  for(int i = 0; i < n; i++) {
    cin >> a[i].second;
  }
  vector<ii> movs;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j+1 < n; j++) {
      if(a[j] > a[j+1]) {
        movs.emplace_back(j+1, j+2);
        swap(a[j], a[j+1]);
      }
    }
  }
  for(int i = 0; i+1 < n; i++) {
    if(a[i].second > a[i+1].second) {
      cout << "-1" << '\n';
      return;
    }
  }
  cout << movs.size() << '\n';
  for(auto [x, y] : movs) {
    cout <<x << " " << y << '\n';
  }
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