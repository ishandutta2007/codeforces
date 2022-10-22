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
#include <iomanip>
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
  int n; cin >> n;
  vector<int> f(n);
  vector<bool> in(n, false);
  REP(i, n) {
    cin >> f[i]; --f[i];
    if (f[i] != -1) in[f[i]] = true;
  }
  vector<int> give, take;
  REP(i, n) {
    if (f[i] == -1) give.emplace_back(i);
    if (!in[i]) take.emplace_back(i);
  }
  vector<int> idx;
  REP(i, give.size()) {
    if (give[i] == take[i]) idx.emplace_back(i);
  }
  for (int i = 1; i < idx.size(); i += 2) {
    swap(take[idx[i - 1]], take[idx[i]]);
  }
  if (idx.size() & 1) {
    if (idx.back() == 0) {
      swap(take[1], take[idx.back()]);
    } else {
      swap(take[0], take[idx.back()]);
    }
  }
  REP(i, give.size()) f[give[i]] = take[i];
  REP(i, n) cout << f[i] + 1 << " \n"[i + 1 == n];
  return 0;
}