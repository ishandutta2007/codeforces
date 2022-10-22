#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  map<string, char> mp{
    {{"1 0 0 1 0"}, 'a'},
    {{"1 1 0 2 0"}, 'b'},
    {{"2 0 0 1 1"}, 'c'},
    {{"2 1 0 1 2"}, 'd'},
    {{"1 1 0 1 1"}, 'e'},
    {{"2 1 0 2 1"}, 'f'},
    {{"2 2 0 2 2"}, 'g'},
    {{"1 2 0 2 1"}, 'h'},
    {{"1 1 0 1 1"}, 'i'},
    {{"1 2 0 1 2"}, 'j'},
    {{"1 0 1 2 0"}, 'k'},
    {{"1 1 1 3 0"}, 'l'},
    {{"2 0 1 2 1"}, 'm'},
    {{"2 1 1 2 2"}, 'n'},
    {{"1 1 1 2 1"}, 'o'},
    {{"2 1 1 3 1"}, 'p'},
    {{"2 2 1 3 2"}, 'q'},
    {{"1 2 1 3 1"}, 'r'},
    {{"1 1 1 2 1"}, 's'},
    {{"1 2 1 2 2"}, 't'},
    {{"1 0 2 2 1"}, 'u'},
    {{"1 1 2 3 1"}, 'v'},
    {{"1 2 1 1 3"}, 'w'},
    {{"2 0 2 2 2"}, 'x'},
    {{"2 1 2 2 3"}, 'y'},
    {{"1 1 2 2 2"}, 'z'},
  };
  string s; getline(cin, s);
  int n = stoi(s);
  while (n--) {
    getline(cin, s);
    cout << mp[s];
  }
  cout << '\n';
  return 0;
}