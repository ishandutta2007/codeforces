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

  int x, y, z, a, b, c; cin >> x >> y >> z >> a >> b >> c;
  if (x > a) {
    cout << "NO\n";
    return 0;
  }
  a -= x;
  if (y > a + b) {
    cout << "NO\n";
    return 0;
  }
  a -= y;
  if (z > a + b + c) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  return 0;
}