#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 2e5 + 7;

int t[N];
int h[N];

vector <int> g[N];

ll dp[N][2];

const ll Inf = 1e18;

void dfs(int u, int p) {
  vector <int> ch;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      ch.push_back(v);
    }
  }
  if (ch.empty()) {
    dp[u][0] = dp[u][1] = t[u];
  } else {
    vector <int> md;
    int cnt_l = 0, cnt_r = 0;
    ll sum = 0; 
    for (auto v : ch) {
      if (h[v] < h[u]) {
        ++cnt_l;
        sum += dp[v][0];
      } else if (h[v] == h[u]) {
        md.push_back(v);
      } else {
        ++cnt_r;
        sum += dp[v][1];
      }
    }
    while (cnt_l > 0 && cnt_r > 0) {
      --cnt_l;
      --cnt_r;
      sum += t[u];
    }
    int fl = (cnt_l > 0 ? 1 : 0);
    int cnt = cnt_l + cnt_r;

    dp[u][0] = dp[u][1] = Inf;
    for (int f = 0; f <= 1; ++f) {
      for (int tk_md = 0; tk_md <= 1; ++tk_md) {
        for (int tk_other = 0; tk_other <= 1; ++tk_other) {
          if (tk_md > md.size()) continue;
          vector <int> nmd = md;
          ll cur = sum;
           if (tk_md) {
            ll mn = Inf, id = -1; 
            for (int i = 0; i < (int)nmd.size(); ++i) {
              if (dp[nmd[i]][f] - dp[nmd[i]][f ^ 1] < mn) {
                mn = dp[nmd[i]][f] - dp[nmd[i]][f ^ 1];
                id = i;
              }
            }
            cur += dp[nmd[id]][f];
            cur += t[u];
            nmd.erase(nmd.begin() + id);
          } 
          int cur_cnt = cnt;
          sort(nmd.begin(), nmd.end(), [&] (int u, int v) {
            return dp[u][fl] - dp[u][fl ^ 1] > dp[v][fl] - dp[v][fl ^ 1];
          });
          deque <int> rofl = deque <int> (nmd.begin(), nmd.end());
          while (cur_cnt - tk_other > 0 && rofl.size() > 0 && dp[rofl.back()][fl] - dp[rofl.back()][fl ^ 1] <= t[u]) {
            --cur_cnt;
            cur += dp[rofl.back()][fl];
            cur += t[u];
            rofl.pop_back();
          }
          while (rofl.size() >= 2 && dp[rofl.front()][fl ^ 1] - min(dp[rofl.front()][0], dp[rofl.front()][1])  + dp[rofl.back()][fl] - min(dp[rofl.back()][0], dp[rofl.back()][1])  <= t[u]) {
            cur += t[u];
            cur += dp[rofl.front()][fl ^ 1];
            cur += dp[rofl.back()][fl];
            rofl.pop_front();
            rofl.pop_back();
          }

          cur += (ll)t[u] * cur_cnt;
          cur += (ll)t[u] * rofl.size();
          for (auto v : rofl) cur += min(dp[v][0], dp[v][1]);
          if (!tk_md) {
            if ((cur_cnt == 0 || f == fl) && u != 0) {
              cur += t[u];
            }
          }
          dp[u][f] = min(dp[u][f], cur);
        }
      }
    }
  } 
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  /*for (int i = 0; i < n; ++i) {
    cout << dp[i][0] << ' ' << dp[i][1] << endl;
  }*/
  cout << min(dp[0][0], dp[0][1]) << '\n';
}