#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
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

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
template <typename Abelian>
struct BIT {
  BIT(int n, const Abelian &UNITY = 0) : n(n), UNITY(UNITY), dat(n, UNITY) {}

  void add(int idx, const Abelian &value) {
    while (idx < n) {
      dat[idx] += value;
      idx |= idx + 1;
    }
  }

  Abelian sum(int idx) {
    Abelian res = UNITY;
    while (idx >= 0) {
      res += dat[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return res;
  }

  Abelian sum(int left, int right) { return sum(right) - sum(left - 1); }

  Abelian operator[](const int idx) { return sum(idx, idx); }

  int lower_bound(Abelian value) {
    if (value <= UNITY) return 0;
    int res = 0, exponent = 1;
    while (exponent <= n) exponent <<= 1;
    for (int mask = exponent >> 1; mask > 0; mask >>= 1) {
      if (res + mask - 1 < n && dat[res + mask - 1] < value) {
        value -= dat[res + mask - 1];
        res += mask;
      }
    }
    return res;
  }

private:
  int n;
  const Abelian UNITY;
  vector<Abelian> dat;
};

template <typename T>
long long inversion_number(const vector<T> &a) {
  int n = a.size();
  vector<T> cp(a);
  sort(ALL(cp));
  cp.erase(unique(ALL(cp)), cp.end());
  BIT<int> bit(cp.size());
  long long res = 0;
  REP(i, n) {
    int idx = lower_bound(ALL(cp), a[i]) - cp.begin();
    res += i - bit.sum(idx);
    bit.add(idx, 1);
  }
  return res;
}

void solve() {
  int n; cin >> n;
  vector<char> s(n), t(n);
  REP(i, n) cin >> s[i];
  REP(i, n) cin >> t[i];
  REP(i, 26) {
    if (count(ALL(s), 'a' + i) != count(ALL(t), 'a' + i)) {
      cout << "NO\n";
      return;
    }
  }
  REP(i, 26) {
    if (count(ALL(s), 'a' + i) >= 2) {
      cout << "YES\n";
      return;
    }
  }
  cout << (inversion_number(s) % 2 == inversion_number(t) % 2 ? "YES\n": "NO\n");
}

int main() {
  int q; cin >> q;
  while (q--) solve();
  return 0;
}