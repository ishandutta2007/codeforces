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

  int n, m, q; cin >> n >> m >> q;
  vector<pair<int, int> > cnt(m, {0, -1});
  REP(i, m) cnt[i].second = i;
  REP(i, n) {
    int a; cin >> a; --a;
    ++cnt[a].first;
  }
  sort(ALL(cnt));
  vector<long long> ruiseki(m + 1, 0), start(n + 1);
  REP(i, m) ruiseki[i + 1] = ruiseki[i] + cnt[i].first;
  REP(i, n) {
    int idx = lower_bound(ALL(cnt), make_pair(i + 1, 0)) - cnt.begin();
    start[i] = ruiseki[m] - ruiseki[idx] + (long long)idx * i + 1;
  }
  start[n] = (long long)m * n + 1;
  vector<long long> k(q); REP(i, q) cin >> k[i];
  vector<vector<int> > query(n + 1);
  REP(i, q) {
    int idx = upper_bound(ALL(start), k[i]) - start.begin();
    query[idx - 1].emplace_back(i);
  }
  int right = 0;
  BIT<int> bit(m);
  vector<long long> ans(q);
  REP(i, n) {
    while (right < m && cnt[right].first <= i) {
      bit.add(cnt[right].second, 1);
      ++right;
    }
    for (int e : query[i]) {
      long long nokori = k[e] - start[i] + 1;
      ans[e] = bit.lower_bound(nokori) + 1;
    }
  }
  for (int e : query[n]) ans[e] = (k[e] % m == 0 ? m : k[e] % m);
  REP(i, q) cout << ans[i] << '\n';
  return 0;
}