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
int main() {
  int w, h, n; cin >> w >> h >> n;
  set<int> st_h{0, h}, st_w{0, w};
  map<long long, int> mp_h, mp_w;
  mp_h[h] = mp_w[w] = 1;
  while (n--) {
    char cut; int z; cin >> cut >> z;
    if (cut == 'H') {
      st_h.emplace(z);
      auto it = st_h.lower_bound(z);
      --mp_h[*next(it) - *prev(it)];
      ++mp_h[*next(it) - z];
      ++mp_h[z - *prev(it)];
    } else {
      st_w.emplace(z);
      auto it = st_w.lower_bound(z);
      --mp_w[*next(it) - *prev(it)];
      ++mp_w[*next(it) - z];
      ++mp_w[z - *prev(it)];
    }
    while ((*mp_h.rbegin()).second == 0) mp_h.erase(prev(mp_h.end()));
    while ((*mp_w.rbegin()).second == 0) mp_w.erase(prev(mp_w.end()));
    cout << (*mp_h.rbegin()).first * (*mp_w.rbegin()).first << '\n';
  }
  return 0;
}