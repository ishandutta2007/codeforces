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
struct UnionFind {
  UnionFind(int n) : data(n, -1) {}

  int root(int ver) { return data[ver] < 0 ? ver : data[ver] = root(data[ver]); }

  void unite(int ver1, int ver2) {
    ver1 = root(ver1);
    ver2 = root(ver2);
    if (ver1 != ver2) {
      if (data[ver1] > data[ver2]) swap(ver1, ver2);
      data[ver1] += data[ver2];
      data[ver2] = ver1;
    }
  }

  bool same(int ver1, int ver2) { return root(ver1) == root(ver2); }

  int size(int ver) { return -data[root(ver)]; }

private:
  vector<int> data;
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, k; cin >> n >> k;
  vector<vector<int> > flavor(n);
  int ans = 0, cnt = 0;
  set<pair<int, int> > st;
  REP(i, k) {
    int x, y; cin >> x >> y; --x; --y;
    if (x > y) swap(x, y);
    if (st.count({x, y}) == 1) {
      ++ans;
      continue;
    }
    st.emplace(x, y);
    flavor[x].emplace_back(cnt);
    flavor[y].emplace_back(cnt);
    ++cnt;
  }
  k = cnt;
  UnionFind uf(k);
  REP(i, n) {
    int sz = flavor[i].size();
    REP(j, sz - 1) uf.unite(flavor[i][j], flavor[i][j + 1]);
  }
  vector<set<int> > hito(k);
  vector<int> aji(k, 0);
  REP(i, n) if (!flavor[i].empty()) {
    int root = uf.root(flavor[i][0]);
    for (int e : flavor[i]) hito[root].emplace(e);
    ++aji[root];
  }
  REP(i, k) if (!hito[i].empty()) {
    ans += max((int)hito[i].size() - (aji[i] - 1), 0);
  }
  cout << ans << '\n';
  return 0;
}