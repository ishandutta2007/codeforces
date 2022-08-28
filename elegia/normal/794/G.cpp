#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>

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

const int P = 1000000007;

int norm(int x) { return x >= P ? (x - P) : x; }

void add(int& x, int y) { if ((x += y) >= P) x -= P; }

void sub(int& x, int y) { if ((x -= y) < 0) x += P; }

void exGcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exGcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(int a) {
  int x, y;
  exGcd(a, P, x, y);
  return norm(x + P);
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

const int N = 300010;

int ns, nt;
int fac[N * 2], ifac[N * 2], pw[N * 2], ways[N * 2];
char s[N], t[N];
int n;

int sq(int x) { return x * (ll)x % P; }

// return 2^r + 2^2r + ... + 2^kr = (2^r - 2^(k+1)r)/ (1 - 2^r)
int geo(int r, int k) {
  return norm(P + pw[r] - pw[(k + 1) * r]) * (ll)inv(P + 1 - pw[r]) % P;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> (s + 1) >> (t + 1);
  ns = strlen(s + 1);
  nt = strlen(t + 1);
  for (int i = 1; i <= ns; ++i) if (isupper(s[i])) s[i] = tolower(s[i]);
  for (int i = 1; i <= nt; ++i) if (isupper(t[i])) t[i] = tolower(t[i]);
  cin >> n;

  int tot = ns + nt;
  fac[0] = 1;
  for (int i = 1; i <= tot; ++i) fac[i] = fac[i - 1] * (ll)i % P;
  ifac[tot] = inv(fac[tot]);
  for (int i = tot; i; --i) ifac[i - 1] = ifac[i] * (ll)i % P;
  pw[0] = 1;
  for (int i = 1; i <= max(n, ns) * 2; ++i) pw[i] = pw[i - 1] * 2LL % P;

  int cnt = 0, low = 0;
  for (int i = 1; i <= ns; ++i)
    if (s[i] != 'b') {
      if (s[i] == 'a') ++low;
      else ++cnt;
    }
  for (int i = 1; i <= nt; ++i)
    if (t[i] != 'b') {
      --low;
      if (t[i] == '?')
        ++cnt;
    }

  for (int i = 0; i <= cnt; ++i) ways[i] = fac[cnt] * (ll)ifac[i] % P * ifac[cnt - i] % P;

  int ans = 0;
  if (ns == nt) {
    bool f = true;
    int dim = 0;
    for (int i = 1; i <= ns; ++i) {
      if (s[i] == '?' && t[i] == '?')
        ++dim;
      else if (s[i] != '?' && t[i] != '?' && s[i] != t[i]) {
        f = false;
        break;
      }
    }
    if (f) {
      sub(ways[-low], pw[dim]);
      ans = sq(geo(1, n)) * (ll)pw[dim] % P;
    }
  }

  for (int i = 0; i <= cnt; ++i) {
    int ca = i + low, cb = (ns - nt) - ca;
    if (ca == 0 && cb == 0) {
      static int ex[N];
      for (int j = 1; j <= n; ++j) ex[j] = sq(n / j);
      for (int j = n; j; --j)
        for (int k = j + j; k <= n; k += j)
          sub(ex[j], ex[k]);
      int good = 0;
      for (int j = 1; j <= n; ++j)
        good = (good + ex[j] * (ll)pw[j]) % P;
      ans = (ans + good * (ll) ways[i]) % P;
    }
    if (ca == 0 || cb == 0) continue;
    if (ca < 0) {
      ca *= -1;
      cb *= -1;
    }
    if (cb > 0) continue;
    cb *= -1;
    int g = gcd(ca, cb);
    ca /= g;
    cb /= g;
    ans = (ans + geo(1, min(n / ca, n / cb)) * (ll)ways[i]) % P;
  }

  cout << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}