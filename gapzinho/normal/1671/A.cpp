#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int inf = 0x3f3f3f3f;
const int ms = 505;
const int mod = 1e9+7;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;

int x[10][10];
vector<ii> g[ms];
int dist[505][1<<7][7];

void solve() {
  int cnt = 1;
  string s;
  cin >> s;
  int n = s.size();
  for(int i = 1; i < n; i++) {
    if(s[i] != s[i-1]) {
      if(cnt == 1) {
        cout << "NO" << endl;
        return;
      }
      cnt = 1;
    } else {
      cnt++;
    }
  }

      if(cnt == 1) {
        cout << "NO" << endl;
        return;
      }
      cout << "YES" << endl;
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
    // T++;
    solve(); 
  }
  return 0;
}