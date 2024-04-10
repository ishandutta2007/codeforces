#include <bits/stdc++.h>
using namespace std;

#define int long long

using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int mod = 1e9+7;
const int inf = 1e9;

// int arr[ms];
int m;
vector<ii> a, b;

void solve() {
  int n, k;
  cin >> n >> m;
  a.clear();
  b.clear();
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a.emplace_back(x, 1);
  }
  cin >> k;
  for(int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    b.emplace_back(x, 1);
  }
  while(!a.empty() || !b.empty()) {
    if(a.empty() || b.empty()) {
      cout << "NO\n";
      return;
    }
    ii &x = *a.rbegin();
    ii &y = *b.rbegin();
    if(x.first == y.first) {
      int cnt = min(x.second, y.second);
      x.second-=cnt;
      y.second-=cnt;
      if(x.second == 0) a.pop_back();
      if(y.second == 0) b.pop_back();
      continue;
    }
    if(x < y) {
      if(y.first % m) {
        cout << "NO\n";
        return;
      }
      if(x.first * m > y.first) {
        cout << "NO\n";
        return;
      }
      y.second--;
      if(y.second == 0) b.pop_back();
      b.emplace_back(y.first/m, m);
    }
    if(x > y) {
      if(x.first % m) {
        cout << "NO\n";
        return;
      }
      if(y.first * m > x.first) {
        cout << "NO\n";
        return;
      }
      x.second--;
      if(x.second == 0) a.pop_back();
      a.emplace_back(x.first/m, m);
    }
  }
  cout << "YES" << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(3);
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