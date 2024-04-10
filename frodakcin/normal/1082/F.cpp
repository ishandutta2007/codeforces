#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 500 + 100;
const int MAXK = 10 + 5;
const int MAXL = 500 + 10;

int N, K;

int s[MAXN][MAXL];
int m[MAXN];
int l[MAXN];

char sr[MAXL];

void rpl(int& a, const int& b) {
  if(a < b) a = b;
}

//TRIE
int c[MAXL][10];
int v[MAXL], d[MAXL], p[MAXL], h, X;

int nn(const int& q = 0) {
  for(int i = 0;i < 10;i++) c[X][i] = 0;
  v[X] = 0, d[X] = q;
  return X++;
}
void init() {
  X = 1;
  h = nn(0);
}
void add(int * S, const size_t& L, const int& M) {
  int n = h;
  for(int i = 0;i < L;i++) {
    if(c[n][S[i]] == 0) c[n][S[i]] = nn(d[n] + 1);
    n = c[n][S[i]];
  }
  v[n] += M;
}
int raw;
int dfs(const int& n) {
  p[n] = v[n];
  for(int i = 0;i < 10;i++) if(c[n][i]) p[n] += dfs(c[n][i]);
  raw += p[n];
  return p[n];
}

const int INF = 1e9 + 100;
int dp[MAXL][MAXK], ans;
void init2() {
  for(int i = 0;i < MAXL;i++) for(int k = 0;k <= K;k++) dp[i][k] = -INF;
}
int dp2[MAXL][MAXK];
void dfs3(const int& u, const int& n) {
  for(int i = 0;i < 10;i++) if(c[n][i]) dfs3(u, c[n][i]);
  for(int i = 0, f = 1;i < 10;i++) {
    if(not c[n][i]) continue;
    if(f) {
      f = 0;
      for(int j = 0;j <= K;j++) dp2[n][j] = dp2[c[n][i]][j];
    }
    else {
      for(int j = K;j >= 0;j--) {
        if(dp2[n][j] == -INF) continue;
        for(int k = K;k >= j;k--)
          if(dp2[c[n][i]][k-j] != -INF) rpl(dp2[n][k], dp2[n][j] + dp2[c[n][i]][k-j]);
      }
    }
  }
  dp2[n][0] = 0;
  for(int i = 1;i <= K;i++) if(dp[n][i] != -INF) rpl(dp2[n][i], dp[n][i] - p[n] * d[u]);
}
void dfs2(const int& n) {
  dp[n][0] = 0;
  dp[n][1] = p[n]*d[n];
  for(int i = 0;i < 10;i++) if(c[n][i]) dfs2(c[n][i]);
  
  for(int i = 0;i < MAXL;i++) for(int k = 0;k <= K;k++) dp2[i][k] = -INF;
  dfs3(n, n);
  for(int i = 1;i <= K;i++) if(dp2[n][i - 1] != -INF) dp[n][i] = dp2[n][i - 1] + p[n] * d[n];
}

int main() {
  scanf("%d%d", &N, &K);
  for(int i = 0;i < N;i++) {
    scanf(" %s", sr);
    for(l[i] = 0;sr[l[i]] != '\0';l[i]++) s[i][l[i]] = static_cast<int> (sr[l[i]]) - 48;
    scanf("%d", m + i);
  }
  init();
  for(int i = 0;i < N;i++) add(s[i], l[i], m[i]);
  raw = 0, dfs(h), raw -= p[h];
  init2();
  ans = 0, dfs2(h);
  
  for(int i = 0;i <= K;i++) rpl(ans, dp2[h][i]);
  printf("%d\n", raw - ans);
  
  return 0;
}