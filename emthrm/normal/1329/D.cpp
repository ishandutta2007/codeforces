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

void solve() {
  string s; cin >> s;
  int n = s.length();
  set<int> rem, st[26];
  REP(i, n) rem.emplace(i);
  REP(i, n - 1) {
    if (s[i] == s[i + 1]) st[s[i] - 'a'].emplace(i);
  }
  BIT0based<int> bit(n);
  REP(i, n) bit.add(i, 1);
  vector<int> l, r;
  while (true) {
    vector<pair<int, int>> idx, fro;
    REP(i, 26) {
      if (!st[i].empty()) {
        idx.emplace_back(st[i].size(), i);
        fro.emplace_back(*st[i].begin(), i);
      }
    }
    sort(ALL(idx));
    sort(ALL(fro));
    if (idx.empty()) {
      l.emplace_back(bit.sum(*rem.begin()));
      r.emplace_back(bit.sum(*rem.rbegin()));
      break;
    }
    int left, right;
    if (idx.size() == 1) {
      int id = idx[0].second;
      left = *rem.lower_bound(*st[id].begin() + 1);
      if (st[id].size() == 1) {
        right = *rem.rbegin();
        st[id].erase(st[id].begin());
      } else {
        right = *next(st[id].begin());
        st[id].erase(next(st[id].begin()));
      }
    } else {
      int id = idx.back().second;
      if (fro[0].second == id) {
        int id2 = fro[1].second;
        right = *st[id2].begin();
        st[id2].erase(right);
        left = *prev(st[id].lower_bound(right));
        st[id].erase(left);
        left = *rem.lower_bound(left + 1);
      } else {
        right = *st[id].begin();
        st[id].erase(right);
        int mx = -1, id2;
        REP(i, 26) {
          if (i == id || st[i].empty() || *st[i].begin() > right) continue;
          int l = *prev(st[i].lower_bound(right));
          if (l > mx) {
            mx = l;
            id2 = i;
          }
        }
        left = *rem.lower_bound(mx + 1);
        st[id2].erase(mx);
      }
    }
    l.emplace_back(bit.sum(left));
    r.emplace_back(bit.sum(right));
    vector<int> era;
    for (auto it = rem.lower_bound(left); *it != right; ++it) era.emplace_back(*it);
    assert(rem.count(right) == 1);
    era.emplace_back(right);
    for (int e : era) {
      rem.erase(e);
      bit.add(e, -1);
    }
    // REP(i, n) cout << bit[i] << " \n"[i + 1 == n];
  }
  int m = l.size();
  cout << m << '\n';
  REP(i, m) cout << l[i] + 1 << ' ' << r[i] + 1 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}