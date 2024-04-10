#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

vector<string> query(int l, int r) {
  cout << "? " << l + 1 << ' ' << r + 1 << endl;
  int sub = r - l + 1;
  sub = sub * (sub + 1) / 2;
  vector<string> res;
  while (sub--) {
    string s; cin >> s;
    assert(s != "-");
    sort(ALL(s));
    res.emplace_back(s);
  }
  sort(ALL(res));
  return res;
}

int main() {
  int n; cin >> n;
  if (n == 1) {
    vector<string> corner = query(0, 0);
    cout << "! " << corner[0] << endl;
    return 0;
  }
  if (n == 2) {
    vector<string> one = query(0, 0), two = query(1, 1);
    cout << "! " << one[0] << two[0] << endl;
    return 0;
  }
  vector<string> a = query(0, (n + 1) / 2 - 1), b = query(0, (n + 1) / 2 - 2);
  while (!b.empty()) {
    a.erase(lower_bound(ALL(a), b.back()));
    b.pop_back();
  }
  sort(ALL(a), [&](string l, string r) { return l.length() < r.length(); });
  vector<vector<char> > ans(n);
  REP(i, (n + 1) / 2) {
    for (char c : a[i]) ans[i].emplace_back(c);
  }
  FOR(i, (n + 1) / 2, n) ans[i].emplace_back('$');
  REP(i, (n + 1) / 2) FOR(j, i + 1, (n + 1) / 2) ans[j].erase(lower_bound(ALL(ans[j]), ans[i][0]));
  for (int i = 0; i < (n + 1) / 2 - 1 - i; ++i) swap(ans[i][0], ans[(n + 1) / 2 - 1 - i][0]);
  vector<string> d = query(0, n - 1);
  vector<vector<int> > cnt(n + 1, vector<int>(26, 0));
  for (string &s : d) for (char c : s) ++cnt[s.length()][c - 'a'];
  REP(i, n / 2) REP(j, 26) {
    int sum = (cnt[i + 1][j] - cnt[i][j]) - (cnt[i + 2][j] - cnt[i + 1][j]);
    if (sum == 2 || (sum == 1 && ans[i][0] != 'a' + j)) ans[n - 1 - i][0] = 'a' + j;
  }
  cout << "! ";
  REP(i, n) cout << ans[i][0];
  cout << endl;
  return 0;
}