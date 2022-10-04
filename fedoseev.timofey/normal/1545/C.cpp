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
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;

#define sz(x) (int)(x).size()
#define trav(x, a) for (const auto& x: a)
#define all(x) (x).begin(), (x).end()
#define pii pair<int,int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;

struct Blossom {
  int N;
  int n, ret; 
  vector<int> mate, par;
  vector<int> nx, dsu, mrk, vis;
  queue<int> pq;
  vector<vector<int>> adj;
  Blossom() {}
  Blossom(int n) : n(n), par(n+5), nx(n+5), mate(n+5), dsu(n+5), mrk(n+5), vis(n+5), adj(n+2) {
    iota(par.begin(), par.end(), 0);
  }

  void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int qry(int x) { return x == par[x] ? x : par[x] = qry(par[x]); }
  void join(int x, int y) { par[qry(x)] = qry(y); }

  int lca(int x, int y) {
    static int t=0;
    for (t++; ;swap(x,y)) if (x != -1) {
      if (vis[x=qry(x)]==t) return x;
      vis[x] = t;
      x = (mate[x]!=-1)?nx[mate[x]]:-1;
    }
  }

  void group(int a, int p) {
    for (int b,c; a != p; join(a,b), join(b,c),a=c) {
      b=mate[a], c=nx[b];
      if (qry(c) != p) nx[c] = b;
      if (mrk[b] == 2) mrk[b] = 1, pq.push(b);
      if (mrk[c] == 2) mrk[c] = 1, pq.push(c);
    }
  }

  void aug(int s) {
    for (int i = 0; i <= n; i++)
      nx[i] = vis[i] = -1, par[i] = i, mrk[i] = 0;
    while (!pq.empty()) pq.pop();
    pq.push(s); mrk[s] = 1;
    while (mate[s] == -1 && !pq.empty()) {
      int x = pq.front(); pq.pop();
      for (int i = 0,y; i < sz(adj[x]); i++) {
        if ((y=adj[x][i]) != mate[x] && qry(x)!=qry(y)&&mrk[y]!=2) {
          if (mrk[y]==1) {
            int p = lca(x, y);
            if (qry(x)!=p) nx[x] = y;
            if (qry(y)!=p) nx[y] = x;
            group(x,p); group(y,p);
          } else if (mate[y]==-1) {
            nx[y]=x;
            for (int j=y,k,l; j != -1; j=l) {
              k=nx[j]; l = mate[k];
              mate[j] = k; mate[k] = j;
            }
            break;
          } else {
            nx[y] = x;
            pq.push(mate[y]);
            mrk[mate[y]] = 1;
            mrk[y] = 2;
          }
        }
      }
    }
  }

  int matching() {
    fill(mate.begin(), mate.end(), -1);
    for (int i = 1; i <= n; i++)
      if (mate[i] == -1)
        aug(i);
    int ret = 0;
    for (int i = 1; i <= n; i++) {
      ret += mate[i] > i;
    }
    return ret;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <vector <int>> p(2 * n, vector <int> (n));
    for (int i = 0; i < 2 * n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> p[i][j];
      }
    }
    Blossom b(2 * n);
    vector <vector <int>> g(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
      for (int j = i + 1; j < 2 * n; ++j) {
        bool is_edge = false;
        for (int k = 0; k < n; ++k) {
          if (p[i][k] == p[j][k]) {
            is_edge = true;
            break;
          }
        }
        if (is_edge) {
          g[i].push_back(j);
          g[j].push_back(i);
          b.add_edge(i + 1, j + 1);
        }
      }
    }
    int sz = b.matching();
    assert(sz == n);
    vector <int> pr(2 * n);
    vector <int> num(2 * n);
    vector <pair <int, int>> prs;
    for (int i = 1; i <= 2 * n; ++i) {
      if (i < b.mate[i]) {
        int mt = b.mate[i];
        pr[i - 1] = mt - 1;
        pr[mt - 1] = i - 1;
        prs.push_back({i - 1, mt - 1});
        num[i - 1] = (int)prs.size() - 1;
        num[mt - 1] = (int)prs.size() - 1;
      }
    }
    vector <int> st(n, -1);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (st[i] != -1) continue;
      vector <int> cur = st;
      vector <int> cans;
      auto test = [&] (int i, int x) {
        st[i] = x;
        vector <int> q;
        q.push_back(x);
        bool bad = false;
        while (!q.empty()) {
          int x = q.back();
          q.pop_back();
          for (auto v : g[x]) {
            int id = num[v];
            if (st[id] == -1) {
              st[id] = prs[id].first ^ prs[id].second ^ v;
              q.push_back(st[id]);
            } else if (st[id] == v) {
              bad = true;
              break;
            }
          }
          if (bad) break;
        }
        if (!bad && cans.empty()) cans = st;
        return !bad;
      };
      bool fl = true;
      if (!test(i, prs[i].first)) fl = false;
      st = cur;
      if (!test(i, prs[i].second)) fl = false;
      assert(!cans.empty());
      st = cans;
      if (fl) ++cnt;
    }
    int res = 1;
    for (int i = 0; i < cnt; ++i) {
      res = 2 * res % 998244353;
    }
    cout << res << '\n';
    vector <int> sm;
    for (int i = 0; i < n; ++i) {
      sm.push_back(st[i]);
    }
    sort(sm.begin(), sm.end());
    for (auto x : sm) cout << x + 1 << ' ';
    cout << endl;
    /*for (auto p : prs) {
      cout << p.first + 1 << ' ' << p.second + 1 << endl;
    }
    for (int i = 0; i < 2 * n; ++i) {
      for (int j : g[i]) {
        if (j > i) {
          cout << "edge " << i + 1 << ' ' << j + 1 << endl;
        }
      }
    }*/
    
  }
}