// August 18, 2019
// https://codeforces.com/contest/1205/problem/B

/*
Check cycle detection code later.

After-contest (I thought I had solved it, but I got systested...):
1. Don't try to use a more efficient algorithm if a slower one will do. Here,
   don't try to find all possible cycle lengths in O(N + M) time when an
   O(M(N + M)) time complexity is fast enough.
2. Cycle detection: there doesn't seem to be a subquadratic solution.
*/


#include <bits/stdc++.h>

using namespace std;


const int INF = 1e9;
const int N = 100000;


int n;
long long a[N];
vector<int> has_bit[63];
vector<int> g[N];
vector< pair<int, int> > edges;
int was[N];
int dist[N];
int attempt;
int ign; // edge to remove

void bfs(int start) {
  queue<int> q;
  was[start] = attempt;
  dist[start] = 0;
  q.push(start);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int id : g[v]) {
      if (id == ign) {
        continue;
      }
      const auto &e = edges[id];
      int to = e.first ^ e.second ^ v;
      if (was[to] == attempt) {
        continue;
      }
      was[to] = attempt;
      dist[to] = dist[v] + 1;
      q.push(to);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < 63; j++) {
      if (a[i] & (1LL << j)) {
        has_bit[j].push_back(i);
      }
    }
  }
  set< pair<int, int> > edge_set;
  for (int i = 0; i < 63; i++) {
    int s = (int) has_bit[i].size();
    if (s >= 3) {
      cout << "3\n";
      return 0;
    }
    if (s == 2) {
      int a = has_bit[i][0];
      int b = has_bit[i][1];
      if (a > b) {
        swap(a, b);
      }
      if (!edge_set.count({a, b})) {
        int id = (int) edges.size();
        g[a].push_back(id);
        g[b].push_back(id);
        edges.emplace_back(a, b);
        edge_set.emplace(a, b);
      }
    }
  }
  int ans = INF;
  for (ign = 0; ign < (int) edges.size(); ign++) {
    attempt = ign + 1;
    const auto &e = edges[ign];
    int u = e.first, v = e.second;
    bfs(u);
    if (was[v] == attempt) {
      ans = min(ans, dist[v] + 1);
    }
  }
  cout << (ans < INF ? ans : -1) << '\n';


  return 0;
}