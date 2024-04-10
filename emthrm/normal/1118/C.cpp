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

  int n; cin >> n;
  map<int, int> mp;
  REP(i, n*n) {
    int a; cin >> a;
    ++mp[a];
  }
  vector<vector<int> > res(n, vector<int>(n));
  if (n & 1) {
    int one = 0, two = 0, four = 0, flag = (n-1)/2;
    FOR(i, 1, 1001) if (mp[i] > 0) {
      if (mp[i] & 1) {
        if (one == 1) {
          cout << "NO\n";
          return 0;
        }
        res[n/2][n/2] = i;
        ++one;
        mp[i] -= 1;
      }
      if (mp[i] % 4 == 2) {
        if (two < flag) {
          res[two][n/2] = res[n-1-two][n/2] = i;
        } else if (two < n-1) {
          res[n/2][two-flag] = res[n/2][n-1-(two-flag)] = i;
        } else if (two == n-1) {
          cout << "NO\n";
          return 0;
        }
        ++two;
        mp[i] -= 2;
      }
      if (mp[i] % 4 != 0) {
        cout << "NO\n";
        return 0;
      }
      while (mp[i] > 0 && four < flag*flag) {
        int y = four / flag, x = four % flag;
        res[y][x] = res[y][n-1-x] = res[n-1-y][x] = res[n-1-y][n-1-x] = i;
        ++four;
        mp[i] -= 4;
      }
      while (mp[i] > 0 && two < n-1) {
        if (two < flag) {
          res[two][n/2] = res[n-1-two][n/2] = i;
        } else if (two < n-1) {
          res[n/2][two-flag] = res[n/2][n-1-(two-flag)] = i;
        }
        ++two;
        mp[i] -= 2;
      }
      while (mp[i] > 0 && one == 0) {
        res[n/2][n/2] = i;
        ++one;
        mp[i] -= 1;
      }
      if (mp[i] > 0) {
        cout << "NO\n";
        return 0;
      }
    }
  } else {
    int flag = 0, half = n/2;
    FOR(i, 1, 1001) if (mp[i] > 0) {
      if (mp[i] % 4 != 0) {
        cout << "NO\n";
        return 0;
      }
      while (mp[i] > 0) {
        int y = flag / half, x = flag % half;
        res[y][x] = res[y][n-1-x] = res[n-1-y][x] = res[n-1-y][n-1-x] = i;
        ++flag;
        mp[i] -= 4;
      }
    }
  }
  cout << "YES\n";
  REP(i, n) {
    REP(j, n-1) cout << res[i][j] << ' ';
    cout << res[i][n-1] << '\n';
  }
  return 0;
}