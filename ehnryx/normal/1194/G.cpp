#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 100 + 1;
ll dp[N][10][10][2][2][1<<4][1<<4]; // i, (carry), (leq), (mask)

ll solve(const string& s, int x, int y) {
  //cerr<<"solving "<<x<<" "<<y<<nl;
  int n = s.size();
  int m = 0;
  vector<int> top(10, -1), bot(10, -1);
  for(int k=1; k*max(x,y)<=9; k++) {
    top[k*x] = bot[k*y] = m++;
  }

  memset(dp, 0, sizeof dp);
  dp[0][0][0][1][1][0][0] = 1;
  for(int i=0; i<n; i++) {
    for(int cx=0; cx<10; cx++) {
      for(int cy=0; cy<10; cy++) {
        for(int lx=0; lx<2; lx++) {
          for(int ly=0; ly<2; ly++) {
            for(int mx=0; mx<1<<m; mx++) {
              for(int my=0; my<1<<m; my++) {
                ll cur = dp[i][cx][cy][lx][ly][mx][my] % MOD;
                //if(cur == 0) continue;
                for(int d=0; d<10; d++) {
                  int dx = (d*x + cx) % 10;
                  int dy = (d*y + cy) % 10;
                  int ncx = (d*x + cx) / 10;
                  int ncy = (d*y + cy) / 10;
                  bool nlx = (dx == s[i]-'0' ? lx : dx < s[i]-'0');
                  bool nly = (dy == s[i]-'0' ? ly : dy < s[i]-'0');
                  int nmx = (top[dx] == -1 ? mx : mx | 1<<top[dx]);
                  int nmy = (bot[dy] == -1 ? my : my | 1<<bot[dy]);
                  dp[i+1][ncx][ncy][nlx][nly][nmx][nmy] += cur;
                }
              }
            }
          }
        }
      }
    }
  }

  ll ans = 0;
  for(int mx=0; mx<1<<m; mx++) {
    for(int my=0; my<1<<m; my++) {
      if(mx & my) {
        ans += dp[n][0][0][1][1][mx][my] % MOD;
      }
    }
  }
  return ans * 2 % MOD;
}

ll getnum(const string& s) {
  ll res = 0;
  for(char c:s) {
    res = (10*res + c-'0') % MOD;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);

  string s;
  cin >> s;

  ll ans = getnum(s);
  reverse(s.begin(), s.end());
  for(int i=1; i<=9; i++) {
    for(int j=1; j<i; j++) {
      if(__gcd(i,j) == 1) {
        ans += solve(s,i,j);
      }
    }
  }
  cout << ans % MOD << nl;

  return 0;
}