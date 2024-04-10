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
void query(const vector<int> &x, int &pos, int &val) {
  cout << "? ";
  REP(i, x.size()) {
    cout << x[i] + 1;
    if (i + 1 == x.size()) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
  cin >> pos;
  assert(pos != -1);
  --pos;
  cin >> val;
}

int main() {
  int n, k; cin >> n >> k;
  vector<int> x(k);
  iota(ALL(x), 0);
  int pos1, val1;
  query(x, pos1, val1);
  x.erase(x.begin() + pos1);
  x.emplace_back(k);
  int pos2, val2;
  query(x, pos2, val2);
  x.emplace_back(pos1);
  sort(ALL(x));
  int low = 0, high = 0;
  REP(i, k) {
    if (i == pos1) continue;
    x.erase(x.begin() + i);
    int val3;
    query(x, pos2, val3);
    if (val1 < val2) {
      if (val1 == val3) {
        ++high;
      } else if (val1 < val3) {
        ++low;
      }
    } else if (val1 > val2) {
      if (val1 == val3) {
        ++low;
      } else if (val1 > val3) {
        ++high;
      }
    }
    x.emplace_back(i);
    sort(ALL(x));
  }
  assert(low + high == k - 1);
  cout << "! " << low + 1 << endl;
  return 0;
}