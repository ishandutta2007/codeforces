#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;

//need define int long long
namespace Stuff {
const int MOD = 998244353;
int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}   
int fp(int a, int p) {
    int ans = 1, c = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * c);
        c = mod(c * c);
    }   
    return ans;
}   
int dv(int a, int b) { return mod(a * fp(b, MOD - 2)); }
};
struct M {
ll x;
M (int x_) { x = Stuff::mod(x_); }   
M () { x = 0; }
M operator + (M y) {
    int ans = x + y.x;
    if (ans >= Stuff::MOD)
        ans -= Stuff::MOD;
    return M(ans);
}
M operator - (M y) {
    int ans = x - y.x;
    if (ans < 0)
        ans += Stuff::MOD;
    return M(ans);            
}   
M operator * (M y) { return M(x * y.x % Stuff::MOD); }   
M operator / (M y) { return M(x * Stuff::fp(y.x, Stuff::MOD - 2) % Stuff::MOD); }   
M operator + (int y) { return (*this) + M(y); }
M operator - (int y) { return (*this) - M(y); }   
M operator * (int y) { return (*this) * M(y); }   
M operator / (int y) { return (*this) / M(y); }   
M operator ^ (int p) { return M(Stuff::fp(x, p)); }   
void operator += (M y) { *this = *this + y; }   
void operator -= (M y) { *this = *this - y; }   
void operator *= (M y) { *this = *this * y; }
void operator /= (M y) { *this = *this / y; }   
void operator += (int y) { *this = *this + y; }   
void operator -= (int y) { *this = *this - y; }   
void operator *= (int y) { *this = *this * y; }
void operator /= (int y) { *this = *this / y; }   
void operator ^= (int p) { *this = *this ^ p; }
bool operator == (M y) { return x == y.x; }
};  
std::ostream& operator << (std::ostream& o, const M& a)
{
    cout << a.x;
    return o;
}

const int N = 1007;

M dp[N][N][2];
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  string x, y;
  cin >> x >> y;
  int n = x.size(), m = y.size();
  for (int i = 0; i < n; ++i) {
    int len = 1;
    for (int j = i - 1; j >= 0; --j) {
      if (x[j] != x[j + 1]) {
        ++len;
      } else {
        break;
      }
    }
    for (int j = 0; j < m; ++j) {
      if (x[i] == y[j]) continue;
      dp[i][j][1] = len;
    }
  }
  for (int j = 0; j < m; ++j) {
    int len = 1;
    for (int i = j - 1; i >= 0; --i) {
      if (y[i] != y[i + 1]) {
        ++len;
      } else {
        break;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (x[i] == y[j]) continue;
      dp[i][j][0] = len;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int t = 0; t < 2; ++t) {
        for (int nt = 0; nt < 2; ++nt) {
          if (nt == 0 && i + 1 < n) {
            char pr = (t == 0 ? x[i] : y[j]);
            char cr = (nt == 0 ? x[i + 1] : y[j + 1]);
            if (pr != cr) dp[i + 1][j][nt] += dp[i][j][t];
          }
          if (nt == 1 && j + 1 < m) {
            char pr = (t == 0 ? x[i] : y[j]);
            char cr = (nt == 0 ? x[i + 1] : y[j + 1]);
            if (pr != cr) dp[i][j + 1][nt] += dp[i][j][t];
          }
        }
      }
    }
  }
  M ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int t = 0; t < 2; ++t) {
        ans += dp[i][j][t];
      }
    }
  }
  cout << ans << '\n';
}