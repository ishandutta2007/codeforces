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
int query(const string &s) {
  assert(!s.empty() && s.length() <= 300);
  cout << s << endl;
  int dist; cin >> dist;
  assert(dist != -1);
  if (dist == 0) exit(0);
  return dist;
}

int main() {
  string a_str = "", b_str = "";
  REP(_, 300) a_str += 'a';
  REP(_, 300) b_str += 'b';
  int a = 300 - query(a_str), b = 300 - query(b_str);
  string spell = "";
  REP(_, a) spell += 'a';
  int dist = b;
  REP(i, spell.length()) {
    if ((i - 1 < 0 || spell[i - 1] == 'a') && spell[i] == 'a') {
      while (b > 0) {
        string cp = spell;
        cp.insert(cp.begin() + i, 'b');
        int now = query(cp);
        if (now >= dist) break;
        --dist;
        --b;
        spell.insert(spell.begin() + i, 'b');
      }
    }
  }
  while (b--) spell += 'b';
  query(spell);
  assert(false);
}