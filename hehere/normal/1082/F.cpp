#include <bits/stdc++.h>
using namespace std;

bool chmin(int &x, int y) {
  return y < x ? x = y, true : false;
}

const int maxN = 500 + 5;
const int maxK = 10 + 2;
int n, k;

int a[maxN], ch[maxN][maxK], f[maxN][maxN][maxK], cnt = 1;
int g[maxN][maxK];


void dp(int u, int dep) {
  for(int c = 0; c < 10; ++c) if(ch[u][c]) dp(ch[u][c], dep + 1);
  memset(f[u], 0, sizeof(f[u]));
  for(int c = 0; c < 10; ++c) if(ch[u][c]) {
    int v = ch[u][c];

    memcpy(g, f[u], sizeof(f[u]));
    memset(f[u], 0x3f, sizeof(f[u]));

    for(int d = 0; d <= dep; ++d)
      for(int i = 0; i <= k; ++i)
        for(int j = 0; j + i <= k; ++j)
          chmin(f[u][d][i + j], g[d][i] + f[v][d][j]);
  }

  for(int d = 0; d <= dep; ++d)
    for(int i = 0; i <= k; ++i)
      if(f[u][d][i] < 0x3f3f3f3f)
        f[u][d][i] += (dep - d) * a[u];
  
  if(dep > 0)
    for(int d = 0; d <= dep - 1; ++d)
      for(int i = 0; i <= k - 1; ++i)
        chmin(f[u][d][i + 1], f[u][dep][i]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n >> k;

  memset(ch, 0, sizeof(ch));
  memset(a, 0, sizeof(a));
  for(int i = 0; i < n; ++i) {
    string s; int m;
    cin >> s >> m;
    int u = 1;
    for(int i = 0; i < (int)s.size(); ++i) {
      int c = s[i] - '0';
      if(ch[u][c] == 0) ch[u][c] = ++cnt;
      u = ch[u][c];
    }
    a[u] += m;
  }
  dp(1, 0);
  int ans = 0x3f3f3f3f;
  for(int i = 0; i <= k; ++i) chmin(ans, f[1][0][i]);
  cout << ans << endl;
  return 0;
}