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

template <typename T = std::string>
struct RollingHash {
  T str;

  RollingHash(const T &s, const int base = 10007, const int md = 1000000007) : str(s), base(base), md(md) {
    int n = str.size();
    hash_val.resize(n + 1);
    hash_val[0] = 0;
    power.resize(n + 1);
    power[0] = 1;
    for (int i = 0; i < n; ++i) {
      hash_val[i + 1] = (hash_val[i] * base % md + str[i]) % md;
      power[i + 1] = power[i] * base % md;
    }
  }

  long long get(int left, int right) const {
    long long res = hash_val[right] - hash_val[left] * power[right - left] % md;
    return res < 0 ? res + md : res;
  }

  void add(const T &t) {
    for (auto c : t) {
      hash_val.emplace_back((hash_val.back() * base % md + c) % md);
      power.emplace_back(power.back() * base % md);
    }
  }

  int lcp(int i, int j) const {
    int n = str.size(), lb = 0, ub = n + 1 - std::max(i, j);
    while (ub - lb > 1) {
      int mid = (lb + ub) >> 1;
      (get(i, i + mid) == get(j, j + mid) ? lb : ub) = mid;
    }
    return lb;
  }

  template <typename U>
  int lcp(const RollingHash<U> &t, int i, int j) const {
    int lb = 0, ub = std::min(static_cast<int>(str.size()) - i, static_cast<int>(t.str.size()) - j) + 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) >> 1;
      (get(i, i + mid) == t.get(j, j + mid) ? lb : ub) = mid;
    }
    return lb;
  }

private:
  int base, md;
  std::vector<long long> hash_val, power;
};

int main() {
  constexpr int C = 26, I337 = 1337, B1 = 10007, B2 = 10009;
  int n; cin >> n;
  vector<string> s(n); REP(i, n) cin >> s[i];
  vector<RollingHash<>> hash1, hash2;
  REP(i, n) hash1.emplace_back(s[i], B1);
  REP(i, n) hash2.emplace_back(s[i], B2);
  map<array<int, C>, vector<int>> imp;
  REP(i, n) {
    array<int, C> a{};
    for (char c : s[i]) ++a[c - 'a'];
    imp[a].emplace_back(i);
  }
  ll ans = n * (n - 1LL) / 2 * I337;
  const int l = s.front().length();
  bool flag = n < C * l * 10;
  int fr[C]{}, fr_inc[C]{};
  for (auto [_, ids] : imp) {
    const int m = ids.size();
    ans -= m * (m - 1LL) / 2 * I337;
    if (flag) {
      REP(i, m) FOR(j, i + 1, m) {
        const string &si = s[ids[i]], &sj = s[ids[j]];
        int left = 0, right = l;
        while (si[left] == sj[left]) ++left;
        while (si[right - 1] == sj[right - 1]) --right;
        bool i_is_inc = true, j_is_inc = true;
        FOR(k, left + 1, right) {
          if (si[k - 1] > si[k]) {
            i_is_inc = false;
            break;
          }
        }
        FOR(k, left + 1, right) {
          if (sj[k - 1] > sj[k]) {
            j_is_inc = false;
            break;
          }
        }
        ans += (i_is_inc || j_is_inc ? 1 : 2);
      }
    } else {
      ans += m * (m - 1LL) / 2 * 2;
      REP(i, l) FOR(j, i + 1, l) {
        map<pair<ll, ll>, vector<int>> pre_suf;
        REP(k, m) {
          ll fi = (static_cast<ll>(hash1[ids[k]].get(0, i)) << 32) | hash1[ids[k]].get(j + 1, l);
          ll se = (static_cast<ll>(hash2[ids[k]].get(0, i)) << 32) | hash2[ids[k]].get(j + 1, l);
          pre_suf[{fi, se}].emplace_back(ids[k]);
        }
        for (auto [_, v] : pre_suf) {
          const int x = v.size();
          if (x == 1) continue;
          vector<int> is_inc(x, true);
          REP(k, x) {
            const string &sk = s[v[k]];
            FOR(a, i + 1, j + 1) {
              if (sk[a - 1] > sk[a]) {
                is_inc[k] = false;
                break;
              }
            }
          }
          const int inc = count(ALL(is_inc), true);
          if (inc == 0 || inc == x) continue;
          ans -= 1LL * inc * (x - inc);
          unordered_set<int> chs;
          REP(k, x) {
            const int c = s[v[k]][i] - 'a';
            chs.emplace(c);
            ++(is_inc[k] ? fr_inc : fr)[c];
          }
          for (int c : chs) {
            ans += 1LL * fr[c] * fr_inc[c];
            fr[c] = fr_inc[c] = 0;
          }
          chs.clear();
          REP(k, x) {
            const int c = s[v[k]][j] - 'a';
            chs.emplace(c);
            ++(is_inc[k] ? fr_inc : fr)[c];
          }
          for (int c : chs) {
            ans += 1LL * fr[c] * fr_inc[c];
            fr[c] = fr_inc[c] = 0;
          }
          unordered_map<int, int> fr_ba, fr_ba_inc;
          REP(k, x) ++(is_inc[k] ? fr_ba_inc : fr_ba)[((s[v[k]][i] - 'a') << 6) | (s[v[k]][j] - 'a')];
          for (auto [key, num] : fr_ba_inc) {
            if (fr_ba.count(key) == 1) ans -= 1LL * num * fr_ba[key];
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}