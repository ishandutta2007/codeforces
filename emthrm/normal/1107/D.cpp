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
string memo[16];
string hexadecimal2binary(char c) {
  int i;
  if (c == 'A') i = 10;
  else if (c == 'B') i = 11;
  else if (c == 'C') i = 12;
  else if (c == 'D') i = 13;
  else if (c == 'E') i = 14;
  else if (c == 'F') i = 15;
  else i = stoi(to_string(c));
  if (memo[i] != "") return memo[i];
  string res = "";
  REP(digit, 4) {
    if (i & 1) res += '1';
    else res += '0';
    i >>= 1;
  }
  reverse(ALL(res));
  memo[i] = res;
  return res;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  REP(i, 16) memo[i] = "";
  int n; cin >> n;
  vector<vector<char> > a(n, vector<char>(n/4)); REP(i, n) REP(j, n/4) cin >> a[i][j];
  int ans = n;
  REP(i, n) {
    string s = "";
    REP(j, n/4) s += hexadecimal2binary(a[i][j]);
    int tamaru = 1;
    char now = s.front();
    FOR(j, 1, n) {
      if (now == s[j]) ++tamaru;
      else {
        ans = __gcd(ans, tamaru);
        tamaru = 1;
        now = s[j];
      }
    }
    ans = __gcd(ans, tamaru);
  }
  REP(j, n/4) {
    int tamaru = 1;
    char now = a[0][j];
    FOR(i, 1, n) {
      if (now == a[i][j]) ++tamaru;
      else {
        ans = __gcd(ans, tamaru);
        tamaru = 1;
        now = a[i][j];
      }
    }
    ans = __gcd(ans, tamaru);
  }
  cout << ans << '\n';
}