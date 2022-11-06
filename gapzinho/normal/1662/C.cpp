#include <bits/stdc++.h>
using namespace std;

#define int long long

using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
using ld =  long double;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int ms = 500;

const int m = 101; // size of matrix

struct Matrix { 
  ll mat[m][m];
  Matrix operator + (const Matrix &p) {
    Matrix ans;
    for(int i = 0; i < m; i++)
      for(int j = 0; j < m; j++)
        ans.mat[i][j] = (mat[i][j] + p.mat[i][j])%mod;
    return ans;
  }
  Matrix operator * (const Matrix &p) {
    Matrix ans;
    for(int i = 0; i < m; i++)
      for(int j = 0; j < m; j++)
        for(int k = ans.mat[i][j] = 0; k < m; k++)
          ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * p.mat[k][j]) % mod;
    return ans;
  }
};

Matrix zero;
struct MMat { 
  Matrix mat[2][2];
  MMat operator * (const MMat &p) {
    MMat ans;
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++) {
        ans.mat[i][j] = zero;
        for(int k = 0; k < 2; k++)
          ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * p.mat[k][j]);
      }
    return ans;
  }
};

Matrix deg, degm1, adj, ident;

MMat fexp(MMat a, int b) {
  MMat ans;
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      ans.mat[i][j]  = i == j ? ident : zero;
    }
  }
  while(b) {
    if(b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}


int dg[ms];

void solve() {
  int n, eds, k;
  cin >> n >> eds >> k;
  for(int i = 0; i < m; i++) {
    for(int j =0 ; j < m; j++){
      adj.mat[i][j] = 0;
    }
  }
  while(eds--) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    dg[a]++; dg[b]++;
    adj.mat[a][b] = adj.mat[b][a] = 1;
  }
  for(int i = 0; i < m; i++) {
    for(int j =0 ; j < m; j++){
      zero.mat[i][j] = 0;
      deg.mat[i][j] = i == j ? mod-dg[i] : 0;
      degm1.mat[i][j] = i == j ? mod-max(0ll, dg[i] - 1) : 0;
      ident.mat[i][j] = i == j;
    }
  }
  MMat magic;
  magic.mat[1][1] = zero;
  magic.mat[1][0] = ident;
  magic.mat[0][0] = adj;
  magic.mat[0][1] = degm1;
  MMat hlp = fexp(magic, k-1);
  int resp = 0;
  MMat majud;
  majud.mat[0][0] = adj*adj + deg;
  majud.mat[1][0] = adj;
  MMat ans = hlp * majud;
  for(int i = 0; i < n; i++) {
    resp = (resp + ans.mat[1][0].mat[i][i]) % mod;
  }
  cout << resp << endl;
}



int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}