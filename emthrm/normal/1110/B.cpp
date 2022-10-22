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

  int n, m, k; cin >> n >> m >> k;
  vector<int> b(n); REP(i, n) cin >> b[i];
  vector<int> sa;
  REP(i, n-1) sa.emplace_back(b[i+1]-b[i]-1);
  sort(ALL(sa));
  long long ans = n;
  for (int i = 0; i < sa.size()-k+1; ++i) ans += sa[i];
  cout << ans << '\n';
  return 0;
}