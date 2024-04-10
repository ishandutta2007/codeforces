#include <algorithm>
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
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f, MOD = 1000000007;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*-----------------------------------------*/
int main() {
  cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, k; cin >> n >> k;
  vector<long long> a(n); REP(i, n) cin >> a[i];
  vector<int> b(n); REP(i, n) cin >> b[i];
  long long lb = -1, ub = 2000000000000;
  while (ub - lb > 1) {
    long long mid = (lb + ub) / 2;
    bool ok = true;
    vector<long long> charge = a;
    vector<vector<int> > idx(k);
    REP(i, n) {
      long long tmp = 1 + charge[i] / b[i];
      if (tmp < k) idx[tmp].emplace_back(i);
      charge[i] %= b[i];
    }
    int now = 1;
    FOR(t, 1, k) {
      while (now < k && idx[now].empty()) ++now;
      if (now < t) {
        ok = false;
        break;
      }
      if (now == k) break;
      int i = idx[now].back(); idx[now].pop_back();
      charge[i] += mid;
      long long tmp = now + charge[i] / b[i];
      if (tmp < k) idx[tmp].emplace_back(i);
      charge[i] %= b[i];
    }
    if (ok) {
      while (now < k && idx[now].empty()) ++now;
      if (now < k) ok = false;
    }
    (ok ? ub : lb) = mid;
  }
  long long mid = ub;
  bool ok = true;
  vector<long long> charge = a;
  vector<vector<int> > idx(k);
  REP(i, n) {
    long long tmp = 1 + charge[i] / b[i];
    if (tmp < k) idx[tmp].emplace_back(i);
    charge[i] %= b[i];
  }
  int now = 1;
  FOR(t, 1, k) {
    while (now < k && idx[now].empty()) ++now;
    if (now < t) {
      ok = false;
      break;
    }
    if (now == k) break;
    int i = idx[now].back(); idx[now].pop_back();
    charge[i] += mid;
    long long tmp = now + charge[i] / b[i];
    if (tmp < k) idx[tmp].emplace_back(i);
    charge[i] %= b[i];
  }
  if (ok) {
    while (now < k && idx[now].empty()) ++now;
    if (now < k) ok = false;
  }
  cout << (ok ? ub : -1) << '\n';
  return 0;
}