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
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<int> a(n), b(n); REP(i, n) cin >> a[i]; REP(i, n) cin >> b[i];
  map<int, int> mp;
  REP(i, n) mp[b[i]] = i;
  int idx = -1;
  REP(i, n) {
    if (b[i] == 1) {
      idx = i;
      break;
    }
  }
  if (idx != -1) {
    bool ok = true;
    FOR(i, idx, n) {
      if (b[i] != i - idx + 1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      set<int> st;
      REP(i, n) st.insert(a[i]);
      REP(i, idx) {
        if (st.count(b[n - 1] + i + 1) == 0) {
          ok = false;
          break;
        }
        st.insert(b[i]);
      }
      if (ok) {
        cout << n - b[n - 1] << '\n';
        return 0;
      }
    }
  }
  set<int> st;
  REP(i, n) st.insert(a[i]);
  int tmp = n;
  if (idx != -1) {
    REP(i, idx + 1) {
      st.insert(b[i]);
      ++tmp;
    }
  }
  ++idx;
  int uwanose = 0;
  FOR(i, idx, n) {
    if (st.count(i - idx + 1) == 0) {
      int doko = mp[i - idx + 1];
      uwanose = max(uwanose, doko - i + 1);
    }
    st.insert(b[i]);
  }
  cout << tmp + uwanose << '\n';
  return 0;
}