#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
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

  int n, k; cin >> n >> k;
  vector<int> a(n); REP(i, n) cin >> a[i];
  long long ans = 0;
  char now = 'A';
  vector<int> tmp(0);
  REP(i, n) {
    char c; cin >> c;
    if (now == c) tmp.push_back(a[i]);
    else {
      sort(ALL(tmp), greater<int>());
      for (int j = 0; j < k && j < tmp.size(); ++j) ans += tmp[j];
      tmp = {a[i]};
      now = c;
    }
  }
  sort(ALL(tmp), greater<int>());
  for (int j = 0; j < k && j < tmp.size(); ++j) ans += tmp[j];
  cout << ans << '\n';
  return 0;
}