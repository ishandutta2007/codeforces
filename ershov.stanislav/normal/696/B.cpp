#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L); 

mt19937 mrand(random_device{} ()); 
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

int n;
vector<vector<int> > tree;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  tree = vector<vector<int> > (n);
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    p--;
    tree[p].pb(i);
  }
  return true;
}

vector<int> cnt;
vector<int> ans;

void dfs(int v) {
  cnt[v] = 1;
  for (int i = 0; i < sz(tree[v]); i++) {
    dfs(tree[v][i]);
    cnt[v] += cnt[tree[v][i]];
  }
}

void dfs2(int v, int sum) {
  ans[v] = sum + 2;
  for (int i = 0; i < sz(tree[v]); i++) {
    dfs2(tree[v][i], cnt[v] + 1 - cnt[tree[v][i]] + sum);
  }
}

void solve() {
  ans = cnt = vector<int> (n);
  dfs(0);
  dfs2(0, 0);
  for (int i = 0; i < n; i++) {
    printf("%.2f%c", (double) ans[i] / 2, " \n"[i == n - 1]);
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}