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
#define int long long

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
template <typename Abelian>
struct RAQ {
  RAQ(int sz_, const Abelian UNITY_ = 0) : UNITY(UNITY_) {
    sz = sz_ + 1;
    dat.assign(sz, UNITY);
  }

  void add(int left, int right, Abelian value) {
    while (left < sz) {
      dat[left] += value;
      left += left & -left;
    }
    ++right;
    while (right < sz) {
      dat[right] += -value;
      right += right & -right;
    }
  }

  Abelian query(int idx) {
    Abelian res = UNITY;
    while (idx > 0) {
      res += dat[idx];
      idx -= idx & -idx;
    }
    return res;
  }

private:
  int sz;
  const Abelian UNITY;
  vector<Abelian> dat;
};

signed main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, k; cin >> n >> k;
  RAQ<int> raq(k);
  FOR(i, 1, k + 1) {
    raq.add(i, i, i);
    n -= i;
  }
  if (n < 0) {
    cout << "NO\n";
    return 0;
  }
  if (n > 0) {
    if (n >= k) {
      raq.add(1, k, n / k);
      n %= k;
    }
  }
  int left = 2;
  while (n > 0) {
    if ((k + 1 - left) <= n) {
      int tashitai = n / (k + 1 - left), yuyo = raq.query(left - 1) * 2 - raq.query(left);
      // cout << tashitai << ' ' << yuyo << '|';
      tashitai = min(tashitai, yuyo);
      raq.add(left, k, tashitai);
      n -= tashitai * (k + 1 - left);
    }
    ++left;
    if (left == k + 1) {
      if (n > 0) {
        cout << "NO\n";
        return 0;
      }
      break;
    }
    // FOR(i, 1, k + 1) cout << raq.query(i) << (i == k ? '\n' : ' ');
  }
  cout << "YES\n";
  FOR(i, 1, k + 1) cout << raq.query(i) << (i == k ? '\n' : ' ');
  return 0;
}