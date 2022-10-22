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
/*-------------------------------------------------*/
template <typename T>
struct CHT {
  using Line = pair<T, T>;

  CHT(bool is_minimized = true) : is_minimized(is_minimized) {}

  void add(T a, T b) {
    Line now(a, b);
    if (deq.empty()) {
      deq.emplace_back(now);
    } else if (deq.back().first <= a) {
      if (deq.back().first == a) {
        if (is_minimized) {
          if (b >= deq.back().second) return;
          deq.pop_back();
        } else {
          if (b <= deq.back().second) return;
          deq.pop_back();
        }
      }
      while (deq.size() >= 2 && !is_necessary(deq[deq.size() - 2], deq.back(), now)) deq.pop_back();
      deq.emplace_back(now);
    } else {
      if (deq.front().first == a) {
        if (is_minimized) {
          if (b >= deq.front().second) return;
          deq.pop_front();
        } else {
          if (b <= deq.front().second) return;
          deq.pop_front();
        }
      }
      while (deq.size() >= 2 && !is_necessary(now, deq[0], deq[1])) deq.pop_front();
      deq.emplace_front(now);
    }
  }

  T query(T x) {
    int lb = -1, ub = deq.size() - 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) >> 1;
      if (is_minimized) {
        (f(deq[mid], x) < f(deq[mid + 1], x) ? ub : lb) = mid;
      } else {
        (f(deq[mid], x) > f(deq[mid + 1], x) ? ub : lb) = mid;
      }
    }
    return f(deq[ub], x);
  }

  T monotone_inc_query(T x) {
    if (is_minimized) {
      while (deq.size() >= 2 && f(deq[deq.size() - 2], x) <= f(deq.back(), x)) deq.pop_back();
      return f(deq.back(), x);
    } else {
      while (deq.size() >= 2 && f(deq[0], x) <= f(deq[1], x)) deq.pop_front();
      return f(deq.front(), x);
    }
  }

  T monotone_dec_query(T x) {
    if (is_minimized) {
      while (deq.size() >= 2 && f(deq[0], x) >= f(deq[1], x)) deq.pop_front();
      return f(deq.front(), x);
    } else {
      while (deq.size() >= 2 && f(deq[deq.size() - 2], x) >= f(deq.back(), x)) deq.pop_back();
      return f(deq.back(), x);
    }
  }

private:
  bool is_minimized;
  deque<Line> deq;

  using Real = long double;
  bool is_necessary(const Line &l1, const Line &l2, const Line &l3) {
    Real lhs = static_cast<Real>(l3.second - l2.second) / (l2.first - l3.first);
    Real rhs = static_cast<Real>(l2.second - l1.second) / (l1.first - l2.first);
    // T lhs = (l1.first - l2.first) * (l3.second - l2.second);
    // T rhs = (l2.first - l3.first) * (l2.second - l1.second);
    return is_minimized ? lhs < rhs : lhs > rhs;
  }

  T f(const Line &l, T x) { return l.first * x + l.second; }
};

long long n, dp[500000], ans = LINF;
vector<int> graph[500000];
int subtree[500000];

void dfs(int par, int ver) {
  subtree[ver] = 1;
  vector<pair<int, long long> > children;
  for (int e : graph[ver]) if (e != par) {
    dfs(ver, e);
    subtree[ver] += subtree[e];
    children.emplace_back(subtree[e], dp[e]);
  }
  dp[ver] = LINF;
  if (subtree[ver] == 1) {
    dp[ver] = 1;
  } else {
    for (int e : graph[ver]) if (e != par) {
      long long f = subtree[ver] - subtree[e];
      dp[ver] = min(dp[ver], dp[e] + f * f);
    }
  }
  if (children.size() <= 1) return;
  sort(ALL(children));
  CHT<long long> cht;
  REP(i, children.size()) {
    long long f = children[i].first, s = children[i].second;
    long long b = f * f - 2 * n * f + s;
    if (i >= 1) ans = min(ans, cht.monotone_inc_query(f) + n * n + b);
    cht.add(2 * f, b);
  }
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  cin >> n;
  if (n == 2) {
    cout << 2 << '\n';
    return 0;
  }
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  REP(i, n) {
    if (graph[i].size() >= 2) {
      dfs(-1, i);
      break;
    }
  }
  cout << n * (n - 1) - (ans - n) / 2 << '\n';
  return 0;
}