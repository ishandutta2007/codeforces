#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

// template <typename T>
// struct Dinic {
//   struct Edge {
//     int dst, rev; T cap;
//     Edge(int dst, T cap, int rev) : dst(dst), cap(cap), rev(rev) {}
//   };
//   vector<vector<Edge>> graph;
//   Dinic(int n) : graph(n), level(n), itr(n) {}
//   void add_edge(int src, int dst, T cap) {
//     graph[src].emplace_back(dst, cap, graph[dst].size());
//     graph[dst].emplace_back(src, 0, graph[src].size() - 1);
//   }
//   T maximum_flow(int s, int t, T limit) {
//     T res = 0;
//     while (limit > 0) {
//       fill(ALL(level), -1);
//       level[s] = 0;
//       queue<int> que({s});
//       while (!que.empty()) {
//         const int ver = que.front(); que.pop();
//         for (const Edge& e : graph[ver]) {
//           if (level[e.dst] == -1 && e.cap > 0) {
//             level[e.dst] = level[ver] + 1;
//             que.emplace(e.dst);
//           }
//         }
//       }
//       if (level[t] == -1) break;
//       fill(ALL(itr), 0);
//       while (limit > 0) {
//         const T f = dfs(s, t, limit);
//         if (f == 0) break;
//         limit -= f;
//         res += f;
//       }
//     }
//     return res;
//   }
//  private:
//   vector<int> level, itr;
//   T dfs(int ver, int t, T flow) {
//     if (ver == t) return flow;
//     for (; itr[ver] < graph[ver].size(); ++itr[ver]) {
//       Edge& e = graph[ver][itr[ver]];
//       if (level[ver] < level[e.dst] && e.cap > 0) {
//         const T tmp = dfs(e.dst, t, min(flow, e.cap));
//         if (tmp > 0) {
//           e.cap -= tmp;
//           graph[e.dst][e.rev].cap += tmp;
//           return tmp;
//         }
//       }
//     }
//     return 0;
//   }
// };

int main() {
  int n, m, s; cin >> n >> m >> s; --s;
  vector<vector<int>> graph(n);
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
  }
  vector<int> level(n, -1), prev(n, -1);
  level[s] = -2;
  REP(root, graph[s].size()) {
    level[graph[s][root]] = root;
    prev[graph[s][root]] = s;
  }
  queue<int> que;
  REP(root, graph[s].size()) {
    que.emplace(graph[s][root]);
    while (!que.empty()) {
      const int ver = que.front(); que.pop();
      for (int e : graph[ver]) {
        if (level[e] == -1) {
          level[e] = root;
          prev[e] = ver;
          que.emplace(e);
        } else if (level[e] != -2 && level[e] != root) {
          vector<int> leslie, leon{e};
          for (int i = e; i != -1; i = prev[i]) leslie.emplace_back(i);
          for (int i = ver; i != -1; i = prev[i]) leon.emplace_back(i);
          reverse(ALL(leslie));
          reverse(ALL(leon));
          const int h_leslie = leslie.size(), h_leon = leon.size();
          cout << "Possible\n" << h_leslie << '\n';
          REP(i, h_leslie) cout << leslie[i] + 1 << " \n"[i + 1 == h_leslie];
          cout << h_leon << '\n';
          REP(i, h_leon) cout << leon[i] + 1 << " \n"[i + 1 == h_leon];
          return 0;
        }
      }
    }
  }
  cout << "Impossible\n";
  return 0;
}