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
int l;
string n;

string add(int idx) {
  string a = n.substr(0, idx), b = n.substr(idx);
  reverse(ALL(a));
  reverse(ALL(b));
  while ((int)a.length() < (int)b.length()) a += '0';
  while ((int)b.length() < (int)a.length()) b += '0';
  int len = a.length();
  for (int i = 0; i < len; ++i) {
    int aa = a[i] - '0', bb = b[i] - '0';
    if (aa + bb >= 10) {
      if (i == len - 1) {
        a += '0' + (aa + bb) / 10;
      } else {
        a[i + 1] += (aa + bb) / 10;
      }
      a[i] = '0' + ((aa + bb) % 10);
    } else {
      a[i] = '0' + (aa + bb);
    }
  }
  reverse(ALL(a));
  return a;
}

string chmin(const string &a, const string &b) {
  if ((int)a.length() < (int)b.length()) {
    return a;
  } else if ((int)a.length() > (int)b.length()) {
    return b;
  } else {
    int len = a.length();
    REP(i, len) {
      if (a[i] < b[i]) {
        return a;
      } else if (a[i] > b[i]) {
        return b;
      }
    }
    return a;
  }
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  cin >> l >> n;
  string ans = "";
  REP(i, l + 1) ans += '9';
  if (l & 1) {
    int idx = l / 2;
    if (n[idx] != '0') {
      ans = chmin(ans, add(idx));
    } else {
      for (int i = idx - 1; i >= 0; --i) {
        if (n[i] != '0') {
          ans = chmin(ans, add(i));
          break;
        }
      }
    }
    FOR(i, idx + 1, l) {
      if (n[i] != '0') {
        ans = chmin(ans, add(i));
        break;
      }
    }
  } else {
    int idx = l / 2;
    if (n[idx] == '0') {
      FOR(i, idx + 1, l) {
        if (n[i] != '0') {
          ans = chmin(ans, add(i));
          break;
        }
      }
      for (int i = idx - 1; i >= 0; --i) {
        if (n[i] != '0') {
          ans = chmin(ans, add(i));
          break;
        }
      }
    } else {
      ans = chmin(ans, add(idx));
    }
  }
  cout << ans << '\n';
  return 0;
}