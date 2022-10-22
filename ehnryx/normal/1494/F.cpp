#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

constexpr char nl = '\n';
constexpr ll INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-9L;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

// Watch out for stack overflow. Answer is returned in reverse order.
void euler(int u, list<int>& res, list<int>::iterator it, vector<multiset<int>>& adj) {
  for (auto it2 = adj[u].begin(); it2 != adj[u].end(); ) {
    int v=*it2; adj[u].erase(it2);
    /*undirected:*/ adj[v].erase(adj[v].find(u));
    euler(v, res, res.insert(it, v), adj); it2 = adj[u].begin(); } }
list<int> euler_walk(int s, vector<multiset<int>>& adj) {
  list<int> res; res.push_back(s); euler(s, res, res.begin(), adj);
  reverse(res.begin(), res.end()); return res;
}


// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int n, m;
  cin >> n >> m;
  vector<multiset<int>> adj(n+1);
  for(int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].insert(b);
    adj[b].insert(a);
  }

  vector<int> odd;
  vector<bool> is_odd(n+1);
  for(int i=1; i<=n; i++) {
    if(adj[i].size() % 2 == 1) {
      odd.push_back(i);
      is_odd[i] = true;
    }
  }

  if(odd.size() <= 2) {
    int s = (odd.empty() ? 1 : odd.front());
    list<int> ans = euler_walk(s, adj);
    cout << ans.size() << nl;
    for(int it : ans) {
      cout << it << " ";
    }
    cout << nl;
    return 0;
  }

  for(int i=1; i<=n; i++) {
    vector<int> star;
    int want = 0;
    for(int j : adj[i]) {
      if(is_odd[j]) {
        star.push_back(j);
        if(adj[j].size() > 1) {
          want = j;
        }
      }
    }

    vector<multiset<int>> cur_adj = adj;
    for(int j : star) {
      cur_adj[i].erase(cur_adj[i].find(j));
      cur_adj[j].erase(cur_adj[j].find(i));
    }
    vector<int> cur_odd;
    for(int j=1; j<=n; j++) {
      if(cur_adj[j].size() % 2 == 1) {
        cur_odd.push_back(j);
      }
    }
    bool ok = (cur_odd.empty() || i == cur_odd.front() || i == cur_odd.back());
    if(!ok || cur_odd.size() > 2) {
      continue;
    }

    if(cur_odd.empty() && want) {
      cur_odd.push_back(i);
      cur_odd.push_back(want);
      cur_adj[i].insert(want);
      cur_adj[want].insert(i);
      star.erase(find(star.begin(), star.end(), want));
    }

    int s = (cur_odd.empty() ? i : cur_odd.front() ^ cur_odd.back() ^ i);
    list<int> ans = euler_walk(s, cur_adj);
    if(ans.size() - 1 + star.size() != m) {
      continue;
    }
    ans.push_back(-1);
    for(int j : star) {
      ans.push_back(j);
      ans.push_back(i);
    }
    cout << ans.size() << nl;
    for(int it : ans) {
      cout << it << " ";
    }
    cout << nl;
    return 0;
  }

  cout << 0 << nl;

  return 0;
}