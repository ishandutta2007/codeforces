#include <bits/stdc++.h>
using namespace std;

const int maxN = 200 + 5;
const int maxM = 20;
const int maxK = 500 + 5;
const int P = 1000000007;
int n, m, k;
vector<int> l, r;

int cnt = 0;
int ch[maxN][maxM], fail[maxN]; // tot_len <= 200
int val[maxN];
void insert(vector<int> s, int val) {
  int len = s.size(), u = 0;
  for(int i = 0; i < len; ++i) {
    int c = s[i];
    if(ch[u][c] == 0) ch[u][c] = ++cnt;
    u = ch[u][c];
  }
  ::val[u] += val;
}

void build() {
  queue<int> Q;
  for(int c = 0; c < m; ++c) if(ch[0][c]) Q.push(ch[0][c]);
  while(Q.size()) {
    int fa = Q.front(); Q.pop();
    for(int c = 0; c < m; ++c) {
      if(ch[fa][c] == 0) { ch[fa][c] = ch[fail[fa]][c]; continue; }
      int u = ch[fa][c];
      fail[u] = ch[fail[fa]][c];
      val[u] += val[fail[u]];
      Q.push(u);
    }
  }
}

int f[2][maxN][2][maxK];
void inc(int &x, int y) { (x += y) >= P ? x -= P : 233; }
int solve(vector<int> lim) {
  memset(f, 0, sizeof(f));
  int p = 0;
  f[p][0][1][0] = 1;
  int len = lim.size();
  int ans = 0;
  p ^= 1;
  for(int i = 0; i < len; ++i, p ^= 1) {
    memset(f[p], 0, sizeof(f[p]));
    for(int u = 0; u <= cnt; ++u) {
      for(int c = 0; c < m; ++c) {
        for(int last = 0; last < 2; ++last) {
          int leq = (c < lim[i] || (c == lim[i] && last));
          int v = ch[u][c];
          for(int x = 0; x <= k; ++x) if(x + val[v] <= k) {
            inc(f[p][v][leq][x + val[v]], f[p ^ 1][u][last][x]);
            if((leq || i < len - 1) && c) inc(ans, f[p ^ 1][u][last][x]);
          }
        }
      }
    }
  }
  return ans;
}

// My algo runs from low to high. So reverse everything.

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  int s;
  cin >> s; l.assign(s, 0);
  for(int i = 0; i < s; ++i) cin >> l[i];
  std::reverse(l.begin(), l.end());
  int i = 0;
  while(l[i] == 0) l[i++] = m - 1;
  l[i]--; if(l.back() == 0) l.pop_back(); // if l - 1 == 0 ?
  cin >> s; r.assign(s, 0);
  for(int i = 0; i < s; ++i) cin >> r[i];
  std::reverse(r.begin(), r.end());
  
  for(int i = 1; i <= n; ++i) {
    int s; cin >> s;
    vector<int> p(s);
    for(int j = 0; j < s; ++j) cin >> p[j];
    std::reverse(p.begin(), p.end());
    cin >> s;
    insert(p, s);
  }
  build();

  int ansR = solve(r);
  int ansL = l.size() ? solve(l) : 0;
  int ans = (ansR - ansL + P) % P;
  cout << ans << endl;
  return 0;
}