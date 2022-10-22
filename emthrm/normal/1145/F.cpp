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

  map<char, int> mp;
  mp['A'] = 1;
  mp['B'] = 0;
  mp['C'] = 0;
  mp['D'] = 0;
  mp['E'] = 1;
  mp['F'] = 1;
  mp['G'] = 0;
  mp['H'] = 1;
  mp['I'] = 1;
  mp['J'] = 0;
  mp['K'] = 1;
  mp['L'] = 1;
  mp['M'] = 1;
  mp['N'] = 1;
  mp['O'] = 0;
  mp['P'] = 0;
  mp['Q'] = 0;
  mp['R'] = 0;
  mp['S'] = 0;
  mp['T'] = 1;
  mp['U'] = 0;
  mp['V'] = 1;
  mp['W'] = 1;
  mp['X'] = 1;
  mp['Y'] = 1;
  mp['Z'] = 1;
  string s; cin >> s;
  int mul = 1, sum = 0;
  for (char c : s) {
    mul *= mp[c];
    sum += mp[c];
  }
  cout << (mul == 1 || sum == 0 ? "YES\n" : "NO\n");
  return 0;
}