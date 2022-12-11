#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
 
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;

int n, a, b;
int total_len;
vector<int> g[200007];
int dist[200007];
int on_path[200007];


int get_dist(int v, int p, int need, int len = 0) {
  if (need == v) {
    on_path[v] = 1;
    return len;
  }
  for (int to : g[v]) if (to != p) {
    int now = get_dist(to, v, need, len + 1);
    if (now != -1) {
      on_path[v] = 1;
      return now;
    }
  }
  return -1;
}

void calc(int v, int p) {
  dist[v] = 0;
  for (int to : g[v]) if (to != p) {
    calc(to, v);
    dist[v] = max(dist[v], dist[to] + 1);
  }
}

int y_node;

void dfs(int v, int p, int top = 0) {
  vector<pair<int, int>> t;
  t.pb({top, -1});
  for (int to : g[v]) if (to != p) {
    t.pb({dist[to] + 1, to});
  }
  sort(all(t));

  // cout << "v: " << v << ' ';
  // for (auto [w1, w2] : t) cout << w1 << ' ';
  // cout << endl;

  if (t.size() >= 3 && t[(int)t.size() - 3].x >= total_len) {
    y_node = v;
  }
  for (int to : g[v]) if (to != p) {
    int n_top = t.back().x + 1;
    if (t.back().y == to) n_top = t[(int)t.size() - 2].x + 1;
    dfs(to, v, n_top);
  }
}

int get_first_on_path(int v, int p) {
  if (on_path[v]) return v;
  for (int to : g[v]) if (to != p) {
    auto now = get_first_on_path(to, v);
    if (now != -1) return now;
  }
  return -1;
}

std::vector<int> st;
bool get_path(int a, int b, int p = -1) {
  st.pb(a);
  if (a == b) return true;
  for (auto to : g[a]) if (to != p) {
    if (get_path(to, b, a)) return true;
  }
  st.pop_back();
  return false;
}

int main(){
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("A_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int tt;
  cin >> tt;
  while (tt--) {   /// a == b ?
    cin >> n >> a >> b; --a; --b;
    for (int i = 0; i < n; ++i) on_path[i] = 0, g[i].clear();
    for (int i = 0; i < n  -1; ++i) {
      int w1, w2;
      cin >> w1 >> w2;
      --w1; --w2;
      g[w1].pb(w2);
      g[w2].pb(w1);
    }
    total_len = get_dist(a, -1, b);
    y_node = -1;
    calc(0, -1);
    dfs(0, -1);
   // cout << total_len << ' ' << y_node << endl;

    if (y_node == -1) {
      cout << "NO\n";
      continue;
    }
    auto root = get_first_on_path(y_node, -1);
    calc(root, -1);

   // cout << root << endl;

    get_path(root, a);
    const auto p1 = st; st.clear();
    get_path(root, b);
    const auto p2 = st; st.clear();

    int uk1 = (int)p1.size() - 1;
    int uk2 = (int)p2.size() - 1;

   // for (auto c : p1) cout << c + 1 << ' ';
   // cout << endl;
   // for (auto c : p2) cout << c + 1 << ' ';
   // cout << endl;

    int now = 0;

    for (int it = 0; it < 3 * n && std::min(uk1, uk2) > 0; ++it) {
      if (now == 0) {
        int now = min(uk2, dist[p1[uk1]]);
        uk2 -= now;
        uk1 += now;
      //cout << p1[uk1] + 1 << ' ' << dist[p1[uk1]] << endl;
      } else {
        int now = min(uk1, dist[p2[uk2]]);
        uk1 -= now;
        uk2 += now;
      //cout << p2[uk2] + 1 << ' ' << dist[p2[uk2]] << endl;
      }
      now ^= 1;
    }

    if (std::min(uk1, uk2) == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}