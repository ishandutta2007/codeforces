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

template <typename Abelian>
struct BIT0based {
  BIT0based(int n, const Abelian UNITY = 0) : n(n), UNITY(UNITY), dat(n, UNITY) {}

  void add(int idx, Abelian val) {
    while (idx < n) {
      dat[idx] += val;
      idx |= idx + 1;
    }
  }

  Abelian sum(int idx) const {
    Abelian res = UNITY;
    --idx;
    while (idx >= 0) {
      res += dat[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return res;
  }

  Abelian sum(int left, int right) const {
    return left < right ? sum(right) - sum(left) : UNITY;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

  int lower_bound(Abelian val) const {
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
  int n; cin >> n;
  vector<int> tp(n), d(n), powers;
  REP(i, n) {
    cin >> tp[i] >> d[i];
    if (d[i] > 0) powers.emplace_back(d[i]);
  }
  sort(ALL(powers));
  powers.erase(unique(ALL(powers)), powers.end());
  int m = powers.size();
  BIT0based<int> bit1(m);
  BIT0based<ll> bit2(m);
  int lightning = 0;
  multiset<int> st;
  ll sum = 0;
  REP(i, n) {
    int idx = lower_bound(ALL(powers), abs(d[i])) - powers.begin();
    sum += d[i];
    bit2.add(m - 1 - idx, d[i]);
    if (d[i] > 0) {
      if (tp[i] == 1) {
        ++lightning;
        st.emplace(d[i]);
      }
      bit1.add(m - 1 - idx, 1);
    } else {
      if (tp[i] == 1) {
        --lightning;
        st.erase(st.lower_bound(-d[i]));
      }
      bit1.add(m - 1 - idx, -1);
    }
    if (!st.empty()) {
      int mn = *st.begin(), p = lower_bound(ALL(powers), mn) - powers.begin();
      bit1.add(m - 1 - p, -1);
      bit2.add(m - 1 - p, -mn);
    }
    ll ans = sum;
    int r = bit1.lower_bound(lightning);
    ans += bit2.sum(r);
    if (r < m) ans += 1LL * powers[m - 1 - r] * (lightning - bit1.sum(r));
    cout << ans << '\n';
    if (!st.empty()) {
      int mn = *st.begin(), p = lower_bound(ALL(powers), mn) - powers.begin();
      bit1.add(m - 1 - p, 1);
      bit2.add(m - 1 - p, mn);
    }
  }
  return 0;
}