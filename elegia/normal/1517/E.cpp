/*
_/_/_/_/    _/_/_/_/_/  _/_/_/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/  _/  _/
_/      _/  _/  _/    _/    _/_/
_/_/_/_/      _/_/     _/_/_/_/_/

_/_/_/_/    _/    _/  _/      _/
_/      _/   _/  _/   _/_/  _/_/
_/      _/    _/_/    _/ _/_/ _/
_/      _/     _/     _/  _/  _/
_/      _/    _/_/    _/      _/
_/      _/   _/  _/   _/      _/
_/_/_/_/    _/    _/  _/      _/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/
*/
#include <cassert>
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
#include <iomanip>
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

const int P = 998244353;

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

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    vector<ll> s(n + 1);
    for (int i = 0; i != n; ++i) s[i + 1] = s[i] + a[i];
    ll ans = 0;
    if (n <= 3) {
      ll total = accumulate(a.begin(), a.end(), 0LL);
      for (int mask = 0; mask != 1 << n; ++mask) {
        vector<int> P, C;
        ll sum = 0;
        for (int i = 0; i != n; ++i) if ((mask >> i) & 1) {
            P.push_back(i);
            sum += a[i];
          } else {
            C.push_back(i);
          }
        if (total - sum < sum) {
          for (int& x : P) x *= -1;
          auto check = [&](const vector<int>& vec) {
            if (vec.size() <= 2) return true;
            for (int i = 2; i != vec.size(); ++i) if (vec[i] - vec[i - 1] < vec[i - 1] - vec[i - 2]) return false;
            return true;
          };
          if (check(P) && check(C)) {
            ++ans;
          }
        }
      }
    } else {
      vector<ll> t(n + 2);
      // 1 <= i <= j, i === j mod 2, total - 2*(t[i] + t[j - 1]) > 0
      // total - 2*s[i] > 2 * s[j - 1]
      for (int i = 0; i != n; ++i) {
        t[i + 2] = t[i] + a[i];
      }
      /*for (int i = 0; i < n + 2; i += 2)
        for (int j = 1; j < n + 2; j += 2) if (s[n] - 2 * (t[i] + t[j]) > 0) ++ans;
      */  //cerr << ans << ' ';
      auto solve = [&](int N, const vector<ll> &T, ll S) {
        int l = 0, r = 1;
        while (r < N) r += 2;
        for (; r >= 0; r -= 2) {
          while (l < N + 2 && S > 2 * (T[l] + T[r])) l += 2;
          ans += l / 2;
        }
      };
      solve(n, t, s[n]);
      if (n >= 3) {
        //cerr << ans << " -> ";
        solve(n - 3, t, s[n] - 2LL * a[n - 1]);
        //cerr << ans << '\n';
      }
      if (n >= 3) {
        vector<ll> tt(n + 2);
        for (int i = 0; i != n - 3; ++i) {
          tt[i + 2] = tt[i] + a[i + 3];
        }
        //cerr << ans << " -> ";
        solve(n - 3, tt, s[n] - 2LL * a[1] - 2LL * a[2]);
        //cerr << ans << '\n';
      }
      if (n >= 6) {
        vector<ll> tt(n + 2);
        for (int i = 0; i != n - 3; ++i) {
          tt[i + 2] = tt[i] + a[i + 3];
        }
        //cerr << ans << " -> ";
        solve(n - 6, tt, s[n] - 2LL * a[1] - 2LL * a[2] - 2LL * a[n - 1]);
        //cerr << ans << '\n';
      }

      for (int i = 1; i != n; ++i)
        if (s[i] > s[n] - s[i]) {
          ++ans;
          if (n > 3 && i == 1) --ans;
          if (n > 3 && i == n - 1) --ans;
        }
    }
    //cerr << ans << '\n';
    /*for (int i = 3; i < n; ++i) if (s[i] - s[1] < s[n] - (s[i] - s[1])) ++ans;
    for (int i = 1; i < n - 2; ++i) if (s[n - 1] - s[i] > s[n] - (s[n - 1] - s[i])) ++ans;
    if (n > 4 && s[n] - 2 * ((ll)a[2] + a[n]) > 0) ++ans;
    if (n > 4 && s[n] - 2 * ((ll)a[1] + a[n - 1]) < 0) ++ans;*/
    ans %= P;
    cout << ans << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}