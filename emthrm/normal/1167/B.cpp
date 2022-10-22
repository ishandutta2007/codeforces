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

  vector<int> a{4, 8, 15, 16, 23, 42};
  map<int, pair<int, int> > mp;
  REP(i, 6) FOR(j, i + 1, 6) {
    mp[a[i] * a[j]] = {i, j};
  }
  vector<int> ans(6, -1);
  int res;
  cout << "? 1 2" << endl;
  cin >> res;
  pair<int, int> p1 = mp[res];
  cout << "? 1 3" << endl;
  cin >> res;
  pair<int, int> p2 = mp[res];
  if (p1.first == p2.first) {
    ans[0] = p1.first;
    ans[1] = p1.second;
    ans[2] = p2.second;
  } else if (p1.first == p2.second) {
    ans[0] = p1.first;
    ans[1] = p1.second;
    ans[2] = p2.first;
  } else if (p1.second == p2.first) {
    ans[0] = p1.second;
    ans[1] = p1.first;
    ans[2] = p2.second;
  } else {
    ans[0] = p1.second;
    ans[1] = p1.first;
    ans[2] = p2.first;
  }
  cout << "? 4 5" << endl;
  cin >> res;
  p1 = mp[res];
  cout << "? 4 6" << endl;
  cin >> res;
  p2 = mp[res];
  if (p1.first == p2.first) {
    ans[3] = p1.first;
    ans[4] = p1.second;
    ans[5] = p2.second;
  } else if (p1.first == p2.second) {
    ans[3] = p1.first;
    ans[4] = p1.second;
    ans[5] = p2.first;
  } else if (p1.second == p2.first) {
    ans[3] = p1.second;
    ans[4] = p1.first;
    ans[5] = p2.second;
  } else {
    ans[3] = p1.second;
    ans[4] = p1.first;
    ans[5] = p2.first;
  }
  cout << "! ";
  REP(i, 5) cout << a[ans[i]] << ' ';
  cout << a[ans[5]] << endl;
  return 0;
}