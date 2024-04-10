#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

ostream& operator<<(ostream& os, const pair<char, int>& unit) {
  return os << unit.first << "^" << unit.second;
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

struct E {
  int v; bool vis;
  E *next, *rev;
};

const int N = 100010;

int n, m;
bool vis[N], pr[N];

E* g[N];

E* adde(int u, int v) {
  static E pool[N * 10], *top = pool;
  E* p = top++;
  p->v = v;
  p->next = g[u];
  g[u] = p;
  return p;
}

void link(int u, int v) {
  E *p = adde(u, v), *q = adde(v, u);
  p->rev = q;
  q->rev = p;
}

void dfs(int u) {
  vis[u] = true;
  for (E* p = g[u]; p; p = p->next) {
    if (p->vis) continue;
    p->vis = p->rev->vis = true;
    if (vis[p->v]) {
      pr[p->v] ^= 1;
      printf("%d %d\n", u, p->v);
      continue;
    }
    dfs(p->v);
    if (pr[p->v]) {
      printf("%d %d\n", u, p->v);
      pr[p->v] ^= 1;
    } else {
      pr[u] ^= 1;
      printf("%d %d\n", p->v, u);
    }
  }
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d", &n, &m);
  for (int rep = 0; rep < m; ++rep) {
    int u, v;
    scanf("%d%d", &u, &v);
    link(u, v);
    vis[u] ^= 1;
    vis[v] ^= 1;
  }
  int lst = -1;
  for (int i = 1; i <= n; ++i)
    if (vis[i]) {
      if (lst == -1)
        lst = i;
      else {
        link(i, lst);
        lst = -1;
        ++m;
      }
    }
  if (m & 1) {
    ++m;
    link(1, 1);
  }
  printf("%d\n", m);
  memset(vis, 0, sizeof(vis));
  dfs(1);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}