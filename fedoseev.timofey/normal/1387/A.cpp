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

const int N = 1e5 + 7;

vector <pair <int, int>> g[N];
int used[N];
vector <int> cmp;

void dfs(int u) {
  used[u] = 1;
  cmp.push_back(u);
  for (auto [v, w] : g[u]) {
    if (!used[v]) {
      dfs(v);
    }
  }
}   

int col[N];
vector <pair <int, int>> path;
vector <pair <int, int>> cycle;

void jhfs(int u) {
  for (auto [v, w] : g[u]) {
    if (col[v] == -1) {
      col[v] = col[u] ^ 1;
      path.push_back({v, w});
      jhfs(v);
      path.pop_back();
    } else if (col[v] != (col[u] ^ 1)) {
      if (cycle.empty()) {
        int id = -1; 
        for (int i = 0; i < (int)path.size(); ++i) {
          if (path[i].first == v) {
            id = i;
            break;
          }
        }
        for (int i = id + 1; i < (int)path.size(); ++i) {
          cycle.push_back(path[i]);
        }
        cycle.push_back({v, w});
      }
    }
  }
} 

ll val[N];
bool bad = false;

void go(int u) {
  used[u] = 1;
  for (auto [v, w] : g[u]) {
    if (!used[v]) {
      val[v] = w - val[u];
      go(v);
    } else if (val[v] != w - val[u]) {
      bad = true;
    }
  }
} 

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v, w *= 2;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  vector <vector <int>> gs;
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      cmp.clear();
      dfs(i);
      gs.push_back(cmp);
    }
  }
  vector <int> ans(n);
  for (auto c : gs) {
    for (int v : c) col[v] = -1;
    col[c[0]] = 0;
    cycle.clear();
    path.clear();
    jhfs(c[0]);
    if (!cycle.empty()) {
      ll sum = 0;
      for (auto p : cycle) {
        sum += p.second;
      }
      sum /= 2;
      int st = -1;
      if (cycle.size() == 1) {
        st = cycle[0].first;
        val[st] = sum;
      } else {
        for (int i = 0; i + 1 < (int)cycle.size(); i += 2) {
          sum -= cycle[i].second;
        }
        st = cycle[(int)cycle.size() - 2].first;
        val[st] = sum;
      }
      bad = false;
      for (int v : c) used[v] = 0;
      go(st);
      if (bad) {
        cout << "NO\n";
        return 0;
      }
    } else {
      for (auto v : c) {
        used[v] = 0;
      }
      bad = false;
      val[c[0]] = 0;
      go(c[0]);
      if (bad) {
        cout << "NO\n";
        exit(0);
      }
      ll best = 1e18;
      ll bx = 0;
      vector <vector <ll>> have(2);
      for (auto v : c) {
        have[col[v]].push_back(val[v]);
      }

      sort(have[0].begin(), have[0].end());
      sort(have[1].begin(), have[1].end());
      
      vector <vector <ll>> pref(2);
      for (int i = 0; i < 2; ++i) {
        pref[i].resize(have[i].size() + 1);
        for (int j = 0; j < (int)have[i].size(); ++j) {
          pref[i][j + 1] = pref[i][j] + have[i][j];
        }
      }
      auto get = [&] (int id, int l, int r) {
        if (l > r) return 0LL;
        return pref[id][r + 1] - pref[id][l];
      };  
      auto check = [&] (ll x) {
        ll res = 0;
        {
          auto it = lower_bound(have[0].begin(), have[0].end(), -x);
          int cnt_r = have[0].end() - it; 
          res += get(0, (int)have[0].size() - cnt_r, (int)have[0].size() - 1) + x * cnt_r;
          res -= get(0, 0, (int)have[0].size() - cnt_r - 1) + x * ((int)have[0].size() - cnt_r);
        }
        {
          auto it = lower_bound(have[1].begin(), have[1].end(), x);
          int cnt_r = have[1].end() - it; 
          res += get(1, (int)have[1].size() - cnt_r, (int)have[1].size() - 1) - x * cnt_r;
          res -= get(1, 0, (int)have[1].size() - cnt_r - 1) - x * ((int)have[1].size() - cnt_r);
        }
        /*for (auto v : c) {
          if (col[v] == 0) res += abs(val[v] + x);
          else res += abs(val[v] - x);
        }*/
        if (res < best) {
          best = res;
          bx = x;
        }
      };  
      for (auto v : c) {
        check(val[v]);
        check(-val[v]);
      }

      for (auto v : c) {
        if (col[v] == 0) {
          val[v] += bx;
        } else {
          val[v] -= bx;
        }
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    cout << fixed << setprecision(1) << (long double)val[i] / 2 << ' '; 
  }
  cout << '\n';
}