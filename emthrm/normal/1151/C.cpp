#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  long long l, r; cin >> l >> r;
  int danl = 0, danr = 0;
  long long tmp = l;
  while (tmp > 0) {
    tmp /= 2;
    ++danl;
  }
  tmp = r;
  while (tmp > 0) {
    tmp /= 2;
    ++danr;
  }
  long long ans = 0;
  for (int i = danl; i < danr; ++i) {
    if (i & 1) {
      long long shoko = 0;
      for (int j = 1; j < i; j += 2) {
        long long add = 1LL << (j - 1);
        (shoko += add) %= MOD;
      }
      (shoko *= 2) %= MOD;
      (shoko += 1) %= MOD;
      long long ko = (1LL << (i - 1)) % MOD;
      long long tasu = (shoko + ko - 1 + MOD) % MOD;
      (tasu *= ko) %= MOD;
      (ans += tasu) %= MOD;
    } else {
      long long shoko = 1;
      for (int j = 2; j < i; j += 2) {
        long long add = 1LL << (j - 1);
        shoko += add;
        shoko %= MOD;
      }
      (shoko *= 2) %= MOD;
      long long ko = (1LL << (i - 1)) % MOD;
      long long tasu = (shoko + ko - 1 + MOD) % MOD;
      (tasu *= ko) %= MOD;
      (ans += tasu) %= MOD;
    }
  }
  long long shoko_idx = 1;
  for (int j = 1; j < danl; ++j) {
    long long add = 1LL << (j - 1);
    (shoko_idx += add) %= MOD;
  }
  long long ko = ((l - shoko_idx) % MOD + MOD) % MOD;
  if (danl & 1) {
    long long shoko = 0;
    for (int j = 1; j < danl; j += 2) {
      long long add = 1LL << (j - 1);
      (shoko += add) %= MOD;
    }
    (shoko *= 2) %= MOD;
    (shoko += 1) %= MOD;
    long long tasu = (shoko + ko - 1 + MOD) % MOD;
    (tasu *= ko) %= MOD;
    (ans -= tasu) %= MOD;
    if (ans < 0) ans += MOD;
  } else {
    long long shoko = 1;
    for (int j = 2; j < danl; j += 2) {
      long long add = 1LL << (j - 1);
      shoko += add;
      shoko %= MOD;
    }
    (shoko *= 2) %= MOD;
    long long tasu = (shoko + ko - 1 + MOD) % MOD;
    (tasu *= ko) %= MOD;
    (ans -= tasu) %= MOD;
    if (ans < 0) ans += MOD;
  }
  shoko_idx = 1;
  for (int j = 1; j < danr; ++j) {
    long long add = 1LL << (j - 1);
    (shoko_idx += add) %= MOD;
  }
  ko = ((r - shoko_idx + 1) % MOD + MOD) % MOD;
  if (danr & 1) {
    long long shoko = 0;
    for (int j = 1; j < danr; j += 2) {
      long long add = 1LL << (j - 1);
      (shoko += add) %= MOD;
    }
    (shoko *= 2) %= MOD;
    (shoko += 1) %= MOD;
    long long tasu = (shoko + ko - 1 + MOD) % MOD;
    (tasu *= ko) %= MOD;
    (ans += tasu) %= MOD;
  } else {
    long long shoko = 1;
    for (int j = 2; j < danr; j += 2) {
      long long add = 1LL << (j - 1);
      shoko += add;
      shoko %= MOD;
    }
    (shoko *= 2) %= MOD;
    long long tasu = (shoko + ko - 1 + MOD) % MOD;
    (tasu *= ko) %= MOD;
    (ans += tasu) %= MOD;
  }
  cout << ans << '\n';
  return 0;
}