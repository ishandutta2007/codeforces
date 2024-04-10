// March 14, 2020
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


constexpr int MAX = 1000005;

vector<int> g[MAX];
vector<pair<int, int>> edges;

int was[MAX];
int used[MAX]; // edge used
int depth[MAX];
int dist[MAX];
int ans = MAX;

void add_edge(int u, int v) {
  int id = (int) edges.size();
  g[u].push_back(id);
  g[v].push_back(id);
  edges.emplace_back(u, v);
}

void dfs(int v, int p) {
  // cerr << "dfs from " << v << '\n';
  for (int u : g[v]) {
    if (u == p) {
      continue;
    }
    if (was[u]) {
      if (depth[u] < depth[v]) {
        ans = min(ans, depth[v] - depth[u] + 1);
      }
      continue;
    }
    was[u] = true;
    depth[u] = depth[v] + 1;
    dfs(u, v);
  }
}

void bfs(int x) {
  cerr << "bfsing from node " << x << '\n';
  queue<int> q;
  q.push(x);
  was[x] = x;
  dist[x] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int id : g[v]) {
      if (used[id] == x) {
        continue;
      }
      used[id] = x;
      int to = edges[id].first ^ edges[id].second ^ v;
      if (was[to] == x) {
        ans = min(ans, dist[v] + dist[to] + 1);
        continue;
      }
      was[to] = x;
      dist[to] = dist[v] + 1;
      q.push(to);
    }
  }
  cerr << ans << '\n';
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


  vector<int> sieve(MAX, 0);
  vector<int> primes;
  for (int i = 2; i * i < MAX; i++) {
    if (sieve[i]) {
      continue;
    }
    if (i <= 1000) {
      primes.push_back(i);
    }
    for (int j = i * i; j < MAX; j += i) {
      sieve[j] = i;
    }
  }
  vector<int> pid(MAX, -1);
  pid[1] = 0;
  int cnt = 1;
  for (int i = 2; i < MAX; i++) {
    if (sieve[i] == 0) {
      pid[i] = cnt++;
    }
  }

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int p : primes) {
      while (a[i] % (p * p) == 0) {
        a[i] /= p * p;
      }
    }
  }
  sort(a.begin(), a.end());
  if (a[0] == 1) {
    cout << "1\n";
    return 0;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1]) {
      cout << "2\n";
      return 0;
    }
  }
  for (int x : a) {
    int u, v;
    if (sieve[x] == 0) {
      u = 1;
      v = x;
    } else {
      u = sieve[x];
      v = x / u;
    }
    add_edge(pid[u], pid[v]);
  }
  fill(was, was + MAX, -1);
  fill(used, used + MAX, -1);
  for (int i = 0; i < 250; i++) { // # of primes <= 1000
    bfs(i);
  }
  if (ans == MAX) {
    ans = -1;
  }
  cout << ans << '\n';


  return 0;
}