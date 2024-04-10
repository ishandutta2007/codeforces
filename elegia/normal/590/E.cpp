#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

template <class Z>
struct MaxFlow {
  vector<vector<tuple<int, int, Z>>> g;
  vector<int> level;

  struct Ref {
    const MaxFlow* p;
    int u, id;

    Ref() {}

    Ref(const MaxFlow* p, int u, int id) : p(p), u(u), id(id) {}

    Z get() const { return std::get<2>((p->g)[u][id]); }
  };

  MaxFlow() {}
  MaxFlow(int n) : g(n) {}

  Ref addEdge(int u, int v, const Z& w) {
    if (u == v) return Ref();
    int ru = g[u].size(), rv = g[v].size();
    g[u].emplace_back(v, rv, w);
    g[v].emplace_back(u, ru, 0);
    return Ref(this, v, rv);
  }

  Z dinic(int s, int t) {
    int n = g.size();
    function<vector<int>()> getLevel = [&]() {
      vector<int> level(n, -1);
      queue<int> q;
      level[s] = 0;
      q.push(s);
      while (!q.empty()) {
        int u = q.front(); q.pop();
        for (const auto& pr : g[u])
          if (get<2>(pr) && level[get<0>(pr)] == -1) {
            level[get<0>(pr)] = level[u] + 1;
            q.push(get<0>(pr));
          }
      }
      return level;
    };
    vector<int> r;
    function<Z(int, Z)> cap = [&](int u, Z limit) {
      if (u == t) return limit;
      Z ret = 0;
      while (r[u] && limit > ret) {
        int v = get<0>(g[u][r[u] - 1]), rev = get<1>(g[u][r[u] - 1]);
        Z& w = get<2>(g[u][r[u] - 1]);
        if (level[v] == level[u] + 1) {
          Z flow = cap(v, min(limit - ret, w));
          ret += flow;
          w -= flow;
          get<2>(g[v][rev]) += flow;
          if (limit == ret)
            return ret;
          --r[u];
        } else
          --r[u];
      }
      return ret;
    };
    Z ret = 0;
    while (level = getLevel(), level[t] != -1) {
      r = vector<int>(n);
      for (int i = 0; i < n; ++i)
        r[i] = g[i].size();
      ret += cap(s, numeric_limits<Z>::max());
    }
    return ret;
  }
};

const int N = 752, L = 10000010;

int n, rt, cnt;
int pos[N];
char s[L];
int ch[L][2];
bitset<N> trans[N];
bool vis[N];
int fail[L], prt[L], belongs[L], lst[L];
int f[N];
int sz[N];

void dfs(int u) {
  vis[u] = true;
  for (int v = 1; v <= n; ++v)
    if (trans[u][v]) {
      if (!vis[v])
        dfs(v);
      trans[u] |= trans[v];
    }
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  rt = cnt = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    int o = rt;
    for (char* p = s; *p; ++p) {
      if (!ch[o][*p - 'a']) {
        ch[o][*p - 'a'] = ++cnt;
        prt[cnt] = o;
      }
      o = ch[o][*p - 'a'];
    }
    pos[i] = o;
    belongs[o] = i;
  }
  queue<int> q;
  for (int i = 0; i < 2; ++i)
    if (ch[rt][i]) {
      fail[ch[rt][i]] = rt;
      q.push(ch[rt][i]);
    }
  while (!q.empty()) {
    int o = q.front();
    q.pop();
    for (int i = 0; i < 2; ++i)
      if (ch[o][i]) {
        int k = fail[o];
        while (k != rt && !ch[k][i]) k = fail[k];
        k = fail[ch[o][i]] = ch[k][i] ? ch[k][i] : rt;
        lst[ch[o][i]] = belongs[k] ? belongs[k] : lst[k];
        q.push(ch[o][i]);
      }
  }
  for (int i = 1; i <= n; ++i)
    for (int o = pos[i]; o; o = prt[o]) {
      if (lst[o])
        trans[i].set(lst[o]);
      if (o != pos[i] && belongs[o])
        trans[i].set(belongs[o]);
    }
  for (int i = 1; i <= n; ++i)
    if (!vis[i])
      dfs(i);
  int S = n * 2, T = n * 2 + 1;
  MaxFlow<int> dilworth(n * 2 + 2);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (trans[i + 1][j + 1])
        dilworth.addEdge(i * 2, j * 2 + 1, 1);
  for (int i = 0; i < n; ++i) {
    dilworth.addEdge(S, i * 2, 1);
    dilworth.addEdge(i * 2 + 1, T, 1);
  }

  cout << n - dilworth.dinic(S, T) << '\n';
  for (int i = 0; i < n; ++i)
    if (dilworth.level[i * 2] != -1 && dilworth.level[i * 2 + 1] == -1)
      cout << (i + 1) << ' ';

  return 0;
}