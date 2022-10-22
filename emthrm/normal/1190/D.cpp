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
template <typename Abelian>
struct BIT {
  BIT(int n, const Abelian UNITY_ = 0) : n(n), UNITY(UNITY_), dat(n, UNITY_) {}

  void add(int idx, Abelian value) {
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
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<int> x(n), y(n), comx(n), comy(n);
  REP(i, n) {
    cin >> x[i] >> y[i];
    comx[i] = x[i];
    comy[i] = y[i];
  }
  sort(ALL(comx));
  comx.erase(unique(ALL(comx)), comx.end());
  sort(ALL(comy));
  comy.erase(unique(ALL(comy)), comy.end());
  vector<vector<int> > yaxis(comy.size(), vector<int>(1, comx.size()));
  REP(i, n) {
    x[i] = lower_bound(ALL(comx), x[i]) - comx.begin();
    y[i] = lower_bound(ALL(comy), y[i]) - comy.begin();
    yaxis[y[i]].emplace_back(x[i]);
  }
  long long ans = 0;
  BIT<long long> bit(comx.size());
  for (int h = (int)comy.size() - 1; h >= 0; --h) if (yaxis[h].size() >= 2) {
    sort(ALL(yaxis[h]));
    REP(i, (int)yaxis[h].size() - 1) {
      if (bit.sum(yaxis[h][i]) - bit.sum(yaxis[h][i] - 1) == 0) bit.add(yaxis[h][i], 1);
      ans += bit.sum(yaxis[h][i]) * (bit.sum(yaxis[h][i + 1] - 1) - bit.sum(yaxis[h][i] - 1));
      // cout << h << ' ' << yaxis[h][i] << ' ' << ans << '\n';
    }
  }
  cout << ans << '\n';
  return 0;
}