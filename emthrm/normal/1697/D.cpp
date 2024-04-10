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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

char query1(int i) {
  cout << "? 1 " << i + 1 << endl;
  char c; cin >> c;
  return c;
}

int query2(int l, int r) {
  cout << "? 2 " << l + 1 << ' ' << r + 1 << endl;
  int res; cin >> res;
  return res;
}

int main() {
  constexpr int C = 26;
  int n; cin >> n;
  int right[C]{};
  fill(right, right + C, -1);
  string s = "";
  for (int i = 0; i < n;) {
    vector<pair<int, int>> p;
    REP(c, C) {
      if (right[c] != -1) p.emplace_back(right[c], c);
    }
    sort(ALL(p));
    const int l = p.size();
    int lb = -1, ub = l - 1;
    while (ub - lb > 1) {
      const int mid = (lb + ub) / 2;
      (query2(p[mid].first, i) == l - mid + 1 ? ub : lb) = mid;
    }
    if (lb == -1) {
      s += query1(i);
    } else {
      s += 'a' + p[lb].second;
    }
    right[s.back() - 'a'] = i;
    int j = i + 1;
    for (; j < n && query2(i, j) == 1; ++j) s += s[i];
    i = j;
  }
  cout << "! " << s << endl;
  return 0;
}