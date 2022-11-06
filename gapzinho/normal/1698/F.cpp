#include <bits/stdc++.h>
using namespace std;

#define int long long

using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const int ms = 1e6+5;

int n;
int a[ms], b[ms];
int lst[ms];
vector<ii> ops;

void rev(int l, int r) {
  reverse(a+l, a+r+1);
  ops.emplace_back(l+1, r+1);
}

void solve() {
  cin >> n;
  ops.clear();
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    lst[a[i]] = i;
  }
  for(int j = 0; j < n; j++) {
    cin >> b[j];
  }
  if(a[0] != b[0]) {
    cout << "NO\n";
    return;
  }
  for(int i = 1; i < n; i++) {
    for(int j = i-1; j < n; j++) {
      lst[a[j]] = j;
    }
    ii safeUntil = {lst[a[i-1]], i-1};
    for(int j = i; j < n && a[i] != b[i]; j++) {
      if(a[j] == b[i] && (j+1 < n && a[j+1] == a[i-1])) {
        rev(i-1, j+1);
        break;
      }
      if(a[j] == b[i] && a[j-1] == a[i-1] && safeUntil.first >= j) {
        rev(safeUntil.second, safeUntil.first);
        // cout << safeUntil.first << " " << safeUntil.second << endl;
        // j will be l + (r-j);
        rev(i-1, safeUntil.second + safeUntil.first - j + 1);
        break;
      }
      safeUntil = max(safeUntil, {lst[a[j]], j});
    }
    if(a[i] != b[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  cout << ops.size() << '\n';
  for(auto [l, r] : ops) {
    cout << l << " " << r << '\n';
  }
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