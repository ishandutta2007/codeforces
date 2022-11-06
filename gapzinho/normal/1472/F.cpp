#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int ms = 1e6+5;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;

ii arr[ms];

void solve() {
  
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> arr[i].second >> arr[i].first;
  }
  sort(arr, arr+m);
  int lst = 0;
  int cur = 0;
  for(int i = 0; i < m; i++) {
    if (cur == 0) {
      cur = arr[i].second;
    } else {
      if(i +1 < m && arr[i+1].first == arr[i].first) {
          cout << "NO\n";
          return;

      }
      if(cur == arr[i].second) {
        if((arr[i].first - lst) % 2 == 1) cur = 0;
        else {
          cout << "NO\n";
          return;
        }
      } else {
        if((arr[i].first - lst) % 2 == 0) cur = 0;
        else {
          cout << "NO\n";
          return;
        }
      }
    }
    lst = arr[i].first;
  }
  if(cur == 0) cout << "YES\n";
  else cout << "NO\n";
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
    solve(); //
  }
  return 0;
}