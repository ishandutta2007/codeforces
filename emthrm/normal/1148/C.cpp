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
int p[300000];
map<int, int> mp;
vector<int> ansa, ansb;
void myswap(int a, int b) {
  ansa.emplace_back(a + 1);
  ansb.emplace_back(b + 1);
  int tmp = p[a];
  p[a] = p[b];
  mp[p[b]] = a;
  p[b] = tmp;
  mp[tmp] = b;
  // REP(i, 6) cout << p[i] + 1 << ' ';
  // cout << '~';
  // REP(i, 6) cout << mp[i] + 1 << ' ';
  // cout << '\n';
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  REP(i, n) {
    cin >> p[i]; --p[i];
    mp[p[i]] = i;
  }
  int l = n / 2 - 1, r = n / 2;
  for (; l > 0; --l, ++r) {
    if (p[l] != l) {
      if (abs(l - mp[l]) < n / 2) {
        if (l < mp[l]) myswap(0, mp[l]);
        myswap(mp[l], n - 1);
      }
      myswap(l, mp[l]);
    }
    if (p[r] != r) {
      if (abs(r - mp[r]) < n / 2) {
        if (mp[r] < r) myswap(mp[r], n - 1);
        myswap(0, mp[r]);
      }
      myswap(mp[r], r);
    }
  }
  if (p[0] != 0) myswap(0, n - 1);
  cout << ansa.size() << '\n';
  REP(i, ansa.size()) cout << ansa[i] << ' ' << ansb[i] << '\n';
  return 0;
}