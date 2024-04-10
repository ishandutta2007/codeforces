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
long long a, b;
long long search(long long left, long long right, const vector<int> &ar) {
  int hero = distance(ar.begin(), lower_bound(ALL(ar), right)) - distance(ar.begin(), lower_bound(ALL(ar), left));
  if (right - left == 1) return b * hero * 1;
  long long mid = (left + right) / 2;
  int hero_l = distance(ar.begin(), lower_bound(ALL(ar), mid)) - distance(ar.begin(), lower_bound(ALL(ar), left));
  int hero_r = distance(ar.begin(), lower_bound(ALL(ar), right)) - distance(ar.begin(), lower_bound(ALL(ar), mid));
  long long res_l, res_r;
  if (hero_l == 0) res_l = a;
  else res_l = search(left, mid, ar);
  if (hero_r == 0) res_r = a;
  else res_r = search(mid, right, ar);
  // cout << left << ' ' << right << ' ' << hero << '|' << min(res_l + res_r, b * hero * (right - left)) << '\n';
  return min(res_l + res_r, b * hero * (right - left));
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, k; cin >> n >> k;
  cin >> a >> b;
  vector<int> ichi(k); REP(i, k) cin >> ichi[i];
  sort(ALL(ichi));
  long long migi = 1;
  REP(i, n) migi <<= 1LL;
  cout << search(1, migi+1, ichi) << '\n';
  return 0;
}