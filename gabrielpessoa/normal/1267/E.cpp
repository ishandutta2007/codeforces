#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int ms = 105;

int mat[ms][ms];
vector<int> ans[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> mat[i][j];
    }
  }
  int best = 1e9;
  int ele = -1;
  for(int i = 1; i < n; i++) {
    int cur = 0;
    vector<ii> v;
    for(int x = 1; x <= m; x++) {
      cur += mat[x][i] - mat[x][n];
      v.emplace_back(mat[x][i] - mat[x][n], x);
    }
    sort(v.begin(), v.end());
    for(auto x : v) {
      if(cur < 0) {
        ans[i].emplace_back(x.second);
        cur -= x.first;
      }
    }
    if(ans[i].size() < best) {
      best = ans[i].size();
      ele = i;
    }
  }
  cout << ans[ele].size() << '\n';
  for(int i = 0; i < ans[ele].size(); i++) {
    cout << ans[ele][i] << " \n"[i + 1 == ans[ele].size()];
  }
}