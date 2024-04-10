#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

bool is_number(const string &s) {
  if (s.empty()) return false;
  if (count(ALL(s), '.') == 0) {
    if (s[0] == '0') return s.length() == 1;
    bool res = true;
    for (char c : s) res &= '0' <= c && c <= '9';
    return res;
  }
  return false;
}

int main() {
  string s; cin >> s;
  vector<string> numbers, words;
  string now = "";
  for (char c : s) {
    if (c == ',' || c == ';') {
      (is_number(now) ? numbers : words).emplace_back(now);
      now = "";
    } else {
      now += c;
    }
  }
  (is_number(now) ? numbers : words).emplace_back(now);
  if (numbers.empty()) {
    cout << "-\n";
  } else {
    cout << "\"";
    int n = numbers.size();
    REP(i, n) cout << numbers[i] << ",\""[i + 1 == n];
    cout << '\n';
  }
  if (words.empty()) {
    cout << "-\n";
  } else {
    cout << "\"";
    int n = words.size();
    REP(i, n) cout << words[i] << ",\""[i + 1 == n];
    cout << '\n';
  }
}