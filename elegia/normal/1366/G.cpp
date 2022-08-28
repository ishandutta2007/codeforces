#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

#define fir first
#define sec second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

ostream &operator<<(ostream &os, const pair<char, int> &unit) {
  return os << unit.first << "^" << unit.second;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int INF = 1e9;

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  cin >> s >> t;
  s = '$' + s + '#';
  t = '$' + t + '#';

  int n = s.length(), m = t.length();

  auto transfer = [&](const vi &x) {
    vi ret(n, -INF);
    vi cur, pre;
    cur.push_back(-INF);
    pre.push_back(-INF);
    int lazy = 0;
    for (int i = 0; i < n; ++i) {
      ret[i] = pre.back() + lazy;

      auto ins = [&]() {
        pre.back() = max(pre.back(), x[i] - lazy);
        cur.back() = max(cur.back(), x[i] - lazy);
      };

      if (s[i] == '.') {
        ins();
        if (cur.size() > 1) {
          int tak = pre.back();
          pre.pop_back();
          cur.pop_back();
          --tak;
          ++lazy;
          pre.back() = max(pre.back(), tak);
          cur.back() = max(cur.back(), tak);
        }
      } else {
        cur.push_back(-INF);
        pre.push_back(pre.back());
        ins();
      }
    }
    return ret;
  };

  vi dp(n, -INF);
  dp[0] = 0;
  for (int i = 1; i < m; ++i) {
    dp = transfer(dp);
    for (int j = 0; j < n; ++j)
      if (s[j] != t[i])
        dp[j] = -INF;
  }
  int ans = n - m - dp.back() * 2;
  cout << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}