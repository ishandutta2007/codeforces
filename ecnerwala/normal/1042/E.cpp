#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
int inv(int a, int m=MOD) {
 a %= m; if (a < 0) a += m;
 return a == 1 ? a : int(m - ll(inv(m, a)) * ll(m) / a);
}
int sq(int a) {
 return ll(a)*ll(a)%MOD;
}
int N;
const int MAXN = 1.1e6;
int R,C;
pair<int, int> V[MAXN];
int dp[MAXN];
int main() {
 ios_base::sync_with_stdio(0), cin.tie(0);
 cin >> R >> C;
 N = R*C;
 for (int i = 0; i < N; i++) cin >> V[i].first, V[i].second = i;
 sort(V, V + N);
 for (int l = 0, sv = 0, sx = 0, sy = 0, r = 0; r < N; r++) {
  while (V[l].first < V[r].first) {
   sv += dp[V[l].second], sv %= MOD;
   sv += sq(V[l].second / C), sv %= MOD;
   sv += sq(V[l].second % C), sv %= MOD;
   sx += V[l].second / C, sx %= MOD;
   sy += V[l].second % C, sy %= MOD;
   l++;
  }
  if (!l) continue;
  ll v = sv;
  int x = V[r].second / C, y = V[r].second % C;
  v += ll(l) * ll(sq(x)); v %= MOD;
  v += ll(l) * ll(sq(y)); v %= MOD;
  v += ll(MOD - x * 2 % MOD) * ll(sx); v %= MOD;
  v += ll(MOD - y * 2 % MOD) * ll(sy); v %= MOD;
  dp[V[r].second] = v * ll(inv(l)) % MOD;
 }
 int x,y; cin >> x >> y; x--, y--;
 cout << dp[x*C+y] << '\n';
}