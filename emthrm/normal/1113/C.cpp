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
long long cnt_odd[1 << 20], cnt_even[1 << 20];

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<long long> a(n + 1, 0);
  REP(i, n) {
    int aa; cin >> aa;
    a[i + 1] = a[i] ^ aa;
  }
  long long ans = 0;
  REP(i, n + 1) {
    if (i & 1) {
      ans += cnt_odd[a[i]];
      ++cnt_odd[a[i]];
    } else {
      ans += cnt_even[a[i]];
      ++cnt_even[a[i]];
    }
  }
  cout << ans << '\n';
  return 0;
}