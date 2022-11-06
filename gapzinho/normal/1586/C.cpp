
#include <bit>
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e18;
const int ms = 1e6+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string s[ms];
int n, m;
int ans[ms];
int bst[ms];
int vis[ms];

// k = x*m+y;

int getIdx(int i, int j) {
  return j*n+i;
}

int isValid(int i, int j) {
  if(i < 0 || i >= n || j < 0 || j >= m || s[i][j] == 'X') return false;
  return true;
}
int dx[2] = {-1, 0};
int dy[2] = {0, -1};

int dfs(int i, int j) {
  int k = getIdx(i, j);
  if(vis[k]) return bst[k];
  else {
    vis[k] = 1;
    for(int d = 0; d < 2; d++) {
      if(isValid(i+dx[d], j+dy[d])) {
        bst[k] = min(bst[k], dfs(i+dx[d], j+dy[d]));
      }
    }
    return bst[k];
  }
}

void solve() {
  cin >> n >> m;
  for(int j = 0; j < m; j++) {
    ans[j] = 0;
  }
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    for(int j = 0; j < m; j++) {
       if(i == 0) bst[getIdx(i, j)] = 0;
       else bst[getIdx(i, j)] = j;
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      ans[j] = max(ans[j], dfs(i, j));
    }
  }
  for(int j = 1; j < m; j++) {
    ans[j] = max(ans[j], ans[j-1]);
  }
  int q;
  cin >> q;
  for(int i = 0; i < q; i++) {
    int lo, hi;
    cin >> lo >> hi;
    lo--; hi--;
    if(ans[hi] <= lo) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
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