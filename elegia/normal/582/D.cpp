#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int P = 1000000007, N = 3400;

int norm(int x) { return x >= P ? x - P : x; }

void add(int& x, int y) {
  ((x += y) >= P) ? (x -= P) : 0;
}

int p, a;
char s[N];
int dp[N][2][2];
int digits[N];

int leq(int k) {
  if (k < 0) return 0;
  if (k > p * 2 - 2)
    return p * (ll)p % P;
  // #i + j <= k
  if (k < p)
    return (k + 1) * (k + 2LL) / 2 % P;
  k = p * 2 - 2 - k;
  return (p * (ll)p - k * (k + 1LL) / 2) % P;
}

int equ(int k) {
  return norm(leq(k) + P - leq(k - 1));
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> p >> a >> s;
  int m = 0;
  int len = strlen(s);
  reverse(s, s + len);
  for (int i = 0; i < len; ++i)
    s[i] -= '0';
  while (len) {
    ll r = 0;
    for (int i = len - 1; i >= 0; --i) {
      r = r * 10 + s[i];
      s[i] = r / p;
      r %= p;
    }
    digits[m++] = r;
    while (len && !s[len - 1]) --len;
  }

  // ups, is Leq, >=p
  dp[0][0][0] = 1;
  for (int i = m - 1; i >= 0; --i) {
    static int tmp[N][2][2];
    memset(tmp, 0, sizeof(tmp));
    for (int j = 0; j < m; ++j) {
      // not done

      // 0->1
      int x = digits[i];
      add(tmp[j][0][0], dp[j][0][0] * (ll)equ(x) % P);
      add(tmp[j][0][0], dp[j][0][1] * (ll)equ(x + p) % P);
      add(tmp[j + 1][0][1], dp[j][0][0] * (ll)equ(x - 1) % P);
      add(tmp[j + 1][0][1], dp[j][0][1] * (ll)equ(x + p - 1) % P);

      // 0->1
      if (x) {
        add(tmp[j][1][0], dp[j][0][0] * (ll) leq(x - 1) % P);
        add(tmp[j][1][0], dp[j][0][1] * (ll) norm(leq(x + p - 1) + P - leq(p - 1)) % P);
        add(tmp[j + 1][1][1], dp[j][0][0] * (ll) leq(x - 2) % P);
        add(tmp[j + 1][1][1], dp[j][0][1] * (ll) norm(leq(x + p - 2) + P - leq(p - 2)) % P);
      }

      // done
      add(tmp[j][1][0], dp[j][1][0] * (ll)leq(p - 1) % P);
      add(tmp[j][1][0], dp[j][1][1] * (ll)norm(leq(p * 2 - 1) + P - leq(p - 1)) % P);
      add(tmp[j + 1][1][1], dp[j][1][0] * (ll)leq(p - 2) % P);
      add(tmp[j + 1][1][1], dp[j][1][1] * (ll)norm(leq(p * 2 - 2) + P - leq(p - 2)) % P);
    }
    memcpy(dp, tmp, sizeof(dp));
  }
  int ans = 0;
  for (int i = a; i <= m; ++i) {
    add(ans, dp[i][0][0]);
    add(ans, dp[i][1][0]);
  }
  cout << ans;

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}