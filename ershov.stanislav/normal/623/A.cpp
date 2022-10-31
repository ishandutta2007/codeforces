#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int maxn = 550;
int n, m;
int bad[maxn];
int has[maxn][maxn];
vector<int> graph[maxn];
int col[maxn];
char s[maxn];

void dfs(int v, int c) {
  if (bad[v] || col[v]) {
    return;
  }
  col[v] = c;
  for (auto i : graph[v]) {
    dfs(i, c);
  }
}

int main() {
#ifdef DEBUG
  freopen("text.in", "r", stdin);
#endif

  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    graph[u].pb(v);
    graph[v].pb(u);
    has[u][v] = has[v][u] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (sz(graph[i]) == n - 1) {
      bad[i] = 1;
    }
  }
  int cols = 0;
  for (int i = 0; i < n; i++) {
    if (!col[i] && !bad[i]) {
      dfs(i, ++cols);
    }
  }
  if (cols > 2) {
    printf("No\n");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (bad[i]) {
      s[i] = 'b';
    } else {
      if (col[i] == 1) {
        s[i] = 'a';
      } else {
        s[i] = 'c';
      }
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int a = s[i];
      int b = s[j];
      if ((abs(a - b) <= 1) ^ has[i][j]) {
        ok = false;
      }
    }
  }
  if (ok) {
    printf("Yes\n");
    for (int i = 0; i < n; i++) {
      printf("%c", s[i]);
    }
    printf("\n");
  } else {
    printf("No\n");
  }

  return 0;
}