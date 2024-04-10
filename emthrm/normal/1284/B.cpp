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

template <typename Abelian>
struct BIT0based {
  BIT0based(int n, const Abelian UNITY = 0) : n(n), UNITY(UNITY), dat(n, UNITY) {}

  void add(int idx, Abelian val) {
    while (idx < n) {
      dat[idx] += val;
      idx |= idx + 1;
    }
  }

  Abelian sum(int idx) {
    Abelian res = UNITY;
    --idx;
    while (idx >= 0) {
      res += dat[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return res;
  }

  Abelian sum(int left, int right) {
    if (right <= left) return UNITY;
    return sum(right) - sum(left);
  }

  Abelian operator[](const int idx) { return sum(idx, idx + 1); }

  int lower_bound(Abelian val) {
    if (val <= UNITY) return 0;
    int res = 0, exponent = 1;
    while (exponent <= n) exponent <<= 1;
    for (int mask = exponent >> 1; mask > 0; mask >>= 1) {
      if (res + mask - 1 < n && dat[res + mask - 1] < val) {
        val -= dat[res + mask - 1];
        res += mask;
      }
    }
    return res;
  }

private:
  int n;
  const Abelian UNITY;
  vector<Abelian> dat;
};

int main() {
  const int M = 1000000;
  int n; cin >> n;
  int a = 0;
  BIT0based<int> bit(M + 1);
  vector<vector<int> > s;
  REP(i, n) {
    vector<int> si;
    int l; cin >> l;
    while (l--) {
      int sij; cin >> sij;
      si.emplace_back(sij);
    }
    int mx = si.back();
    bool ok = false;
    for (int j = int(si.size()) - 2; j >= 0; --j) {
      if (si[j] < mx) {
        ok = true;
        break;
      }
      mx = si[j];
    }
    if (ok) {
      ++a;
      continue;
    }
    s.emplace_back(si);
    bit.add(*max_element(ALL(si)), 1);
  }
  ll ans = 1LL * a * n + 1LL * a * (n - a);
  n = n - a;
  REP(i, n) ans += bit.sum(*min_element(ALL(s[i])) + 1, M + 1);
  cout << ans << '\n';
  return 0;
}