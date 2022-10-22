#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = 100 + 7;
int n, m, a[N];
pair<int, int> score[N];
vector<int> ret[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  /// freopen ("input", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int j = 1; j <= m; j++) {
      score[j] = {(int) 1e9 + 7, j};
      ret[j].clear();
    }
    for (int it = 1; it <= n; it++) {
      sort(score + 1, score + m + 1);
      for (int i = 1; i <= m; i++) {
        cin >> a[i];
      }
      sort(a + 1, a + m + 1);
      reverse(a + 1, a + m + 1);
      for (int i = 1; i <= m; i++) {
        score[i].first = min(score[i].first, a[i]);
        ret[score[i].second].push_back(a[i]);
      }
    }
    int sol = 0;
    for (int j = 1; j <= m; j++) {
      //sol += score[j];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << ret[j][i - 1] << " ";
      }
      cout << "\n";
    }
    continue;
    cout << sol << "\n";
  }
  return 0;
}