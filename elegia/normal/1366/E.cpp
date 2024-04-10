#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

#define fir first
#define sec second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

ostream& operator<<(ostream& os, const pair<char, int>& unit) {
  return os << unit.first << "^" << unit.second;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int P = 998244353;

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vi a(n), b(m);
  cin >> a >> b;
  vi dp(m + 1);
  dp[m] = 1;
  map<int, int> pos;
  for (int i = 0; i < m; ++i)
    pos.insert(make_pair(b[i], i));
  int pre = numeric_limits<int>::max();
  for (int i = n - 1; i >= 0; --i) {
    pre = min(a[i], pre);
    if (pos.count(pre)) {
      int j = pos[pre];
      dp[j] = (dp[j + 1] + dp[j]) % P;
    }
  }
  if (pre != b[0]) dp[1] = 0;
  cout << dp[1] << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}