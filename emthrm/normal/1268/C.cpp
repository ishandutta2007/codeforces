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
#include <iomanip>
#include <iostream>
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
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1},
//           dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

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

  Abelian sum(int left, int right) {
    if (right < left) return UNITY;
    return sum(right) - sum(left - 1);
  }

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

int main() {
  int n; cin >> n;
  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  vector<int> idx(n);
  REP(i, n) {
    int p; cin >> p; --p;
    idx[p] = i;
  }
  BIT<int> bit(n);
  bit.add(idx[0], 1);
  cout << "0 ";
  long long ans = 0, dist = 0, minus = 0;
  int cen = idx[0];
  FOR(i, 1, n) {
    ans += bit.sum(idx[i], n - 1);
    bit.add(idx[i], 1);
    dist += abs(cen - idx[i]);
    int new_cen = bit.lower_bound(i / 2 + 1);
    if (new_cen < cen) {
      dist -= 1LL * bit.sum(new_cen) * (cen - new_cen);
      dist += 1LL * bit.sum(cen, n - 1) * (cen - new_cen);
    } else if (cen < new_cen) {
      dist += 1LL * bit.sum(cen) * (new_cen - cen);
      dist -= 1LL * bit.sum(new_cen, n - 1) * (new_cen - cen);
    }
    cen = new_cen;
    minus += (i + 1) / 2;
    cout << ans + dist - minus << " \n"[i + 1 == n];
  }
  return 0;
}