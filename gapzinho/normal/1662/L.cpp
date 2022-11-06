#include <bits/stdc++.h>
using namespace std;


#define int long long
#define endl "\n"
using ii = pair<int, int>;

int n;


const int inf = 1e9;
const int ms = 4e5+5;

template<class T = int>
struct Bit2D {
public:
  // send updated points
  Bit2D(vector<pair<T, T>> pts) {
    sort(pts.begin(), pts.end());
    for(auto a : pts) {
      if(ord.empty() || a.first != ord.back()) {
        ord.push_back(a.first);
      }
    }
    fw.resize(ord.size() + 1);
    coord.resize(fw.size());
    for(auto &a : pts) {
      swap(a.first, a.second);
    }
    sort(pts.begin(), pts.end());
    for(auto &a : pts) {
      swap(a.first, a.second);
      for(int on = upper_bound(ord.begin(), ord.end(), a.first) - ord.begin(); on < fw.size(); on += on & -on) {
        if(coord[on].empty() || coord[on].back() != a.second) {
          coord[on].push_back(a.second);
        }
      }
    }
    for(int i = 0; i < fw.size(); i++) {
      fw[i].assign(coord[i].size() + 1, 0);
    }
  }
  void upd(T x, T y, T v) {
    for(int xx = upper_bound(ord.begin(), ord.end(), x) - ord.begin(); xx < fw.size(); xx += xx & -xx) {
      for(int yy = upper_bound(coord[xx].begin(), coord[xx].end(), y) - coord[xx].begin(); yy < fw[xx].size(); yy += yy & -yy) {
        fw[xx][yy] = max(fw[xx][yy], v);
      }
    }
  }
  T qry(T x, T y) {
    T ans = 0;
    for(int xx = upper_bound(ord.begin(), ord.end(), x) - ord.begin(); xx > 0; xx -= xx & -xx) {
      for(int yy = upper_bound(coord[xx].begin(), coord[xx].end(), y) - coord[xx].begin(); yy > 0; yy -= yy & -yy) {
        ans = max(ans, fw[xx][yy]);
      }
    }
    return ans;
  }
private:
  vector<T> ord;
  vector<vector<T>> fw, coord;
};

int t[ms], a[ms];
int h[ms], l[ms];
map<int, int> magic;
int dp[ms];

void solve() {
  int v;
  cin >> n >> v;
  for(int i = 1; i <= n; i++) {
      cin >> t[i];
  }
  for(int i = 1; i <= n; i++) {
      cin >> a[i];
  }
  t[0] = 0; a[0] = 0;
  vector<ii> pts;
  for(int i = 0; i <= n; i++) {
    h[i] = -(t[i]*v + a[i]);
    l[i] = -(t[i]*v - a[i]);
    // cout << h[i] << "  " << l[i] << endl;
    pts.emplace_back(h[i], l[i]);
  }
  Bit2D<int> bt(pts);
  for(int i = n; i >= 0; i--) {
    dp[i] = 1 + bt.qry(h[i], l[i]);
    bt.upd(h[i], l[i], dp[i]);
    // cout << bt.qry(h[i], l[i]) << endl;
  }
  cout << dp[0]-1 << endl;
}

 main() {
  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
}