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
const int ms = 1e5+5;

int d[ms][20][2][2];
int px[ms][2], py[ms][2];

void solve() {
  int n;
  cin >> n;
  for(int i = 2; i <= n; i++) {
    for(int j = 0; j < 2; j++) {
      cin >> px[i][j] >> py[i][j];
      if(j == 0) px[i][j]++;
      else py[i][j]++;
    }
  }
  px[1][0] = px[1][1] = 1;
  py[1][0] = py[1][1] = 1;
  for(int i = 1; i < n; i++) {
    for(int a = 0; a < 2; a++) {
      for(int b = 0; b < 2; b++) {
        d[i][0][a][b] = abs(px[i][a] - px[i+1][b]) + abs(py[i][a] - py[i+1][b]);
      }
    }
  }
  for(int i = n-1; i >= 1; i--) {
    for(int j = 1; j < 20; j++) {
      if(i + (1 << j) > n) break;
      for(int a = 0; a < 2; a++) {
        for(int b = 0; b < 2; b++) {
          int k = i + (1 << (j-1));
          d[i][j][a][b] = min(d[i][j-1][a][0] + d[k][j-1][0][b], d[i][j-1][a][1] + d[k][j-1][1][b]);
        }
      }
    }
  }
  int m;
  cin >> m;
  for(int i = 0; i < m; i++) {
    ii a, b;
    cin >> a.first >> a.second >> b.first >> b.second;
    int la = max(a.first, a.second);
    int lb = max(b.first, b.second);
    if(lb < la) {
      swap(la, lb);
      swap(a, b);
    }
    int ans;
    if(la == lb) {
      ans = abs(a.first - b.first ) + abs(a.second - b.second);
    } else {
      la++;
      vector<int> dis;
      for(int k = 0; k < 2; k++) {
        dis.emplace_back(abs(a.first - px[la][k]) + abs(a.second - py[la][k]));
      }
      for(int pot = 19; pot >= 0; pot--) {
        if(la + (1 << pot) <= lb) {
          vector<int> ndis;
          for(int k = 0; k < 2; k++) {
            ndis.emplace_back(min(dis[0] + d[la][pot][0][k], dis[1] + d[la][pot][1][k]));
          }
          dis = ndis;
          la += (1 << pot);
        }
      }
      ans = inf;
      assert(la == lb);
      for(int k = 0; k < 2; k++) {
        ans = min(ans, dis[k] + abs(b.first - px[la][k]) + abs(b.second - py[la][k]));
      }
    }
    cout << ans << '\n';
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
  // cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}