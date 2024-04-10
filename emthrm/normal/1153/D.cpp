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
bool leaf[300000] = {};
vector<int> edge[300000];
int operation[300000], children[300000] = {}, ans = 1;

int calc(int ver) {
  if (leaf[ver]) return children[ver] = 1;
  if (operation[ver] == 0) {
    for (int e : edge[ver]) children[ver] += calc(e);
  } else {
    children[ver] = INF;
    for (int e : edge[ver]) children[ver] = min(children[ver], calc(e));
  }
  return children[ver];
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  REP(i, n) cin >> operation[i];
  FOR(i, 1, n) {
    int f; cin >> f; --f;
    edge[f].emplace_back(i);
  }
  int cnt = 0;
  REP(i, n) {
    if (edge[i].empty()) {
      leaf[i] = true;
      ++cnt;
    }
  }
  cout << cnt - calc(0) + 1 << '\n';
  return 0;
}