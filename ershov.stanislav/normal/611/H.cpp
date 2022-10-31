#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const ld EPS = 1e-12;
const ld PI = acos(-1.0L); 

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

unsigned int rdtsc() {
  unsigned int ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

const int maxn = 100;
int n;
int m;
int g[maxn][maxn];
int c[maxn][maxn], f[maxn][maxn];
int nflow;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  memset(g, 0, sizeof(g));
  for (int i = 0; i < n - 1; i++) {
    char s[maxn], t[maxn];
    scanf("%s%s", s, t);
    int slen = strlen(s), tlen = strlen(t);
    slen--, tlen--;
    g[slen][tlen]++;
    if (slen != tlen) {
      g[tlen][slen]++;
    }
  }
  return true;
}

vector<int> dist, nxt;

int dfs(int v, int maxflow) {
  if (v == 1) {
    return maxflow;
  }
  for (int & i = nxt[v]; i < nflow; i++) {
    if (dist[i] == dist[v] + 1 && c[v][i] > f[v][i]) {
      int res = dfs(i, min(maxflow, c[v][i] - f[v][i]));
      if (res) {
        f[v][i] += res;
        f[i][v] -= res;
        return res;
      }
    }
  }
  return 0;
}

int getflow(int n) {
  int res = 0;
  nflow = n;
  while (1) {
    dist = vector<int> (n, INF);
    nxt = vector<int> (n, 0);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (sz(q)) {
      int cur = q.front();
      q.pop();
      for (int i = 0; i < n; i++) {
        if (c[cur][i] > f[cur][i] && dist[i] == INF) {
          dist[i] = dist[cur] + 1;
          q.push(i);
        }
      }
    }
    if (dist[1] == INF) {
      break;
    }
    while (true) {
      int curres = dfs(0, INF);
      res += curres;
      if (!curres) {
        break;
      }
    }
  }
  return res;
}

void solve() {
  int n2 = n;
  m = 0;
  while (n2 > 0) {
    n2 /= 10;
    m++;
  }
  vector<int> cntv(m);
  for (int i = 1, k = 0; i <= n; i *= 10, k++) {
    for (int j = i; j < i * 10 && j <= n; j++) {
      cntv[k]++;
    }
  }
  int cnttrees = 1;
  for (int j = 0; j < m - 2; j++) {
    cnttrees *= m;
  }
  bool solved = false;
  vector<pair<int, int> > tree;
  /*for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      eprintf("%d%c", g[i][j], " \n" [j == m - 1]);
    }
  }*/
  for (int num = 0; num < cnttrees; num++) {
    tree = vector<pair<int, int> > ();
    if (m > 1) {
      vector<int> proofer(m - 2);
      for (int num2 = num, i = 0; i < m - 2; i++) {
        proofer[i] = num2 % m;
        num2 /= m;
      }
      vector<int> cnt(m);
      set<int> leaves;
      for (int i = 0; i < m - 2; i++) {
        cnt[proofer[i]]++;
      }
      for (int i = 0; i < m; i++) {
        if (cnt[i] == 0) {
          leaves.insert(i);
        }
      }
      for (int i = 0; i < m - 2; i++) {
        int leave = *leaves.begin();
        leaves.erase(leave);
        tree.eb(leave, proofer[i]);
        cnt[proofer[i]]--;
        if (cnt[proofer[i]] == 0) {
          leaves.insert(proofer[i]);
        }
      }
      assert(sz(leaves) == 2);
      tree.eb(*leaves.begin(), *leaves.rbegin());
    }
    /*eprintf("tree %d:\n", num);
      for (int i = 0; i < sz(tree); i++) {
      eprintf("%d %d\n", tree[i].first, tree[i].second);
      }*/
    vector<vector<int> > curg = vector<vector<int> > (m, vector<int> (m));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        curg[i][j] = g[i][j];
      }
    }
    for (auto i : tree) {
      curg[i.first][i.second]--;
      curg[i.second][i.first]--;
    }
    bool ok = true;
    for (int mask = 1; mask < (1 << m); mask++) {
      int cnt = 0;
      for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
          if (((mask >> i) & 1) || ((mask >> j) & 1)) {
            cnt += curg[i][j];
          }
        }
      }
      int need = 0;
      for (int i = 0; i < m; i++) {
        if ((mask >> i) & 1) {
          need += cntv[i] - 1;
        }
      }
      if (cnt < need) {
        ok = false;
      }
    }
    if (!ok) {
      continue;
    }
    memset(c, 0, sizeof(c));
    memset(f, 0, sizeof(f));
    for (int i = 0; i < m; i++) {
      c[0][i + 2] = cntv[i] - 1;
      for (int j = 0; j < m; j++) {
        c[i + 2][2 + m + min(i, j) * m + max(i, j)] = 1e6;
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = i; j < m; j++) {
        c[2 + m + i * m + j][1] = curg[i][j];
        if (curg[i][j] < 0) {
          ok = false;
        }
      }
    }
    if (!ok) {
      continue;
    }
    /*for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
      eprintf("%d%c", c[i][j], " \n" [j == 9]);
      }
      }*/
    int flow = getflow(2 + m + m * m);
    /*eprintf("flow = %d\n", flow);
      for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
      eprintf("%d%c", f[i][j], " \n" [j == 9]);
      }
      }*/
    assert(flow == n - m);
    solved = true;
    break;
  }
  if (!solved) {
    printf("-1\n");
  } else {
    vector<int> first(m), ptr(m), mx(m);
    for (int i = 1, k = 0; i <= n; i *= 10, k++) {
      first[k] = i;
      ptr[k] = i + 1;
      mx[k] = i * 10;
    }
    vector<pair<int, int> > ans;
    for (auto j : tree) {
      ans.eb(first[j.first], first[j.second]);
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < f[2 + i][2 + m + min(i, j) * m + max(i, j)]; k++) {
          assert(ptr[i] < mx[i]);
          ans.eb(first[j], ptr[i]++);
        }
      }
    }
    for (auto i : ans) {
      printf("%d %d\n", i.first, i.second);
    }
  }
}

int main() {
  srand(rdtsc());
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}