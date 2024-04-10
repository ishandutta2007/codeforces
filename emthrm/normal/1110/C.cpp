#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
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
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int q; cin >> q;
  vector<pair<int, int>> vec;
  FOR(i, 2, 26) {
    int tmp = 1;
    REP(j, i) tmp <<= 1;
    vec.emplace_back(tmp-1, i);
  }
  REP(query, q) {
    int a; cin >> a;
    bool owari = false;
    for (auto v : vec) if (v.first == a) {
      owari = true;
      break;
    }
    if (owari) {
      bool deta = false;
      for (int i = 2; i <= (int)sqrt(a)+1; ++i) if (a % i == 0) {
        cout << a/i << '\n';
        deta = true;
        break;
      }
      if (!deta) cout << 1 << '\n';
    } else {
      int idx = lower_bound(ALL(vec), make_pair(a, 0)) - vec.begin();
      cout << vec[idx].first << '\n';
    }
  }
  return 0;
}