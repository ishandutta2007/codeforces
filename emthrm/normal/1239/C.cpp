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
template <typename Monoid>
struct RMQ {
  RMQ(int sz, const Monoid &UNITY) : UNITY(UNITY) {
    init(sz);
    dat.assign((n << 1) - 1, UNITY);
  }

  RMQ(const vector<Monoid> &a, const Monoid &UNITY) : UNITY(UNITY) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize((n << 1) - 1);
    REP(i, a_sz) dat[n - 1 + i] = a[i];
    for (int i = n - 2; i >= 0; --i) dat[i] = min(dat[(i << 1) + 1], dat[(i << 1) + 2]);
  }

  void update(int node, const Monoid &value) {
    node += n - 1;
    dat[node] = value;
    while (node > 0) {
      node = (node - 1) >> 1;
      dat[node] = min(dat[(node << 1) + 1], dat[(node << 1) + 2]);
    }
  }

  Monoid query(int a, int b) { return query(a, b, 0, 0, n); }

  int find(int a, int b, const Monoid &value) { return find(a, b, value, 0, 0, n); }

  Monoid operator[](const int idx) const { return dat[idx + n - 1]; }

private:
  int n = 1;
  const Monoid UNITY;
  vector<Monoid> dat;

  void init(int sz) { while (n < sz) n <<= 1; }

  Monoid query(int a, int b, int node, int left, int right) {
    if (right <= a || b <= left) return UNITY;
    if (a <= left && right <= b) return dat[node];
    return min(query(a, b, (node << 1) + 1, left, (left + right) >> 1), query(a, b, (node << 1) + 2, (left + right) >> 1, right));
  }

  int find(int a, int b, const Monoid &value, int node, int left, int right) {
    if (dat[node] > value || right <= a || b <= left) return -1;
    if (right - left == 1) return node - (n - 1);
    int res_l = find(a, b, value, (node << 1) + 1, left, (left + right) >> 1);
    if (res_l != -1) return res_l;
    return find(a, b, value, (node << 1) + 2, (left + right) >> 1, right);
  }
};

int main() {
  int n; long long p; cin >> n >> p;
  map<long long, vector<int> > mp;
  REP(i, n) {
    int t; cin >> t;
    mp[t].emplace_back(i);
  }
  vector<long long> ans(n, -1);
  RMQ<int> rmq(n, INF);
  REP(i, n) rmq.update(i, 1);
  queue<int> que;
  set<int> st;
  long long now = 0;
  for (auto it = mp.begin(); it != mp.end(); ++it) {
    now = max(now, (*it).first);
    for (int e : (*it).second) {
      if (e < n) {
        rmq.update(e, 0);
      } else {
        rmq.update(e - n, 1);
      }
    }
    int idx = rmq.find(0, n, 0);
    if (idx != -1 && ans[idx] == -1 && st.count(idx) == 0) {
      que.emplace(idx);
      st.emplace(idx);
    }
    auto nx = next(it);
    if (nx == mp.end()) break;
    while (!que.empty() && now < (*nx).first) {
      int passenger = que.front();
      que.pop();
      st.erase(passenger);
      now += p;
      ans[passenger] = now;
      mp[now].emplace_back(n + passenger);
      if (now >= (*nx).first) break;
      idx = rmq.find(0, n, 0);
      if (idx != -1 && ans[idx] == -1 && st.count(idx) == 0) {
        que.emplace(idx);
        st.emplace(idx);
      }
    }
  }
  REP(i, n) {
    if (rmq[i] == 0 && st.count(i) == 0) que.emplace(i);
  }
  while (!que.empty()) {
    int passenger = que.front(); que.pop();
    now += p;
    ans[passenger] = now;
  }
  REP(i, n) cout << ans[i] << (i + 1 == n ? '\n' : ' ');
  return 0;
}