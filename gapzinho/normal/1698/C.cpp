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

void solve() {
  int n;
  cin >> n;
  set<int> st;
  int cnt0 = 0;
  vector<int> a;
  for(int i = 0; i < n; i++) {
    int v;
    cin >> v;
    st.emplace(v);
    if(v == 0) {
      if(cnt0 < 3) {
        a.emplace_back(0);
      }
      cnt0++;
    } else {
      a.emplace_back(v);
    }
  }
  n = a.size();
  if(n > 20) {
    cout << "NO\n";
    return;
  }
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      for(int k = j+1; k < n; k++) {
        if(!st.count(a[i]+a[j]+a[k])) {
          cout << "NO\n";
          return;
        }
      }
    }
  }
  cout << "YES\n";
  return;
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