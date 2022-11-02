#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int maxN = 500000 + 233;
int n, m;
int u[maxN], v[maxN], w[maxN];
bool ok[maxN];
int p[maxN];
int pa[maxN], sz[maxN];
vector<pii> qs[maxN];

bool cmp(int x, int y) { return w[x] < w[y]; }

void init() { for(int i = 1; i <= n; ++i) pa[i] = i, sz[i] = 1; }

vector< pair<int, pii> > mod;
int findset(int x) { return pa[x] == x ? x : findset(pa[x]); }
bool merge(int x, int y) {
  int fx = findset(x), fy = findset(y);
  if(fx == fy) return false; // connected
  if(sz[fx] < sz[fy]) std::swap(fx, fy);
  mod.emplace_back(fx, pii(pa[fx], sz[fx]));
  mod.emplace_back(fy, pii(pa[fy], sz[fy]));
  pa[fy] = fx; sz[fx] += sz[fy];
  return true;
}
void retreat() {
  while(mod.size()) {
    pa[mod.back().first] = mod.back().second.first;
    sz[mod.back().first] = mod.back().second.second;
    mod.pop_back();
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  for(int i = 1; i <= m; ++i) cin >> u[i] >> v[i] >> w[i];
  for(int i = 1; i <= m; ++i) p[i] = i;
  std::sort(p + 1, p + m + 1, cmp);
  int q; cin >> q;
  vector<int> lst;
  for(int t = 1; t <= q; ++t) { ok[t] = true;
    int k; cin >> k;
    for(int i = 0; i < k; ++i) {
      int x; cin >> x;
      qs[w[x]].emplace_back(t, x);
    }
  }
  init(); mod.clear();
  for(int i = 1; i <= m; ++i) {
    int j = i; for(; j <= m && w[p[i]] == w[p[j]]; ++j); --j;
    int s = w[p[i]], len = qs[s].size();
    for(int x = 0; x < len; ++x) {
       int y = x; for(; y < len && qs[s][x].first == qs[s][y].first; ++y); --y;
       for(int z = x; z <= y; ++z) ok[qs[s][z].first] &= merge(u[qs[s][z].second], v[qs[s][z].second]);
       retreat();
       x = y;
    }
    for(int k = i; k <= j; ++k) merge(u[p[k]], v[p[k]]);
    mod.clear();
    i = j;
  }
  for(int t = 1; t <= q; ++t) printf("%s\n", ok[t] ? "YES" : "NO");
  return 0;
}