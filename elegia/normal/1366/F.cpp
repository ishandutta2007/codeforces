#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

#define fir first
#define sec second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<ll, ll> pii;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

ostream &operator<<(ostream &os, const pair<int, int> &unit) {
  return os << "y = " << unit.first << "x + " << unit.second;
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

const int P = 1000000007;

int norm(int x) { return x >= P ? x - P : x; }

void add(int &x, int y) {
  if ((x += y) >= P)
    x -= P;
}

pii operator+(const pii& lhs, const pii& rhs) { return pii(lhs.fir + rhs.fir, lhs.sec + rhs.sec); }
pii operator-(const pii& lhs) { return pii(-lhs.fir, -lhs.sec); }
pii operator-(const pii& lhs, const pii& rhs) { return lhs + (-rhs); }
ll operator^(const pii& lhs, const pii& rhs) { return lhs.fir * rhs.fir + lhs.sec * rhs.sec; }
ll operator*(const pii& lhs, const pii& rhs) { return lhs.fir * rhs.sec - lhs.sec * rhs.fir; }

ll dfrac(ll x, ll y) {
  if (x < 0)
    return (x - y + 1) / y;
  return x / y;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;
  vi u(m), v(m), w(m);
  for (int i = 0; i < m; ++i) {
    cin >> u[i] >> v[i] >> w[i];
    --u[i];
    --v[i];
  }
  vector<int> dp(n, numeric_limits<int>::min());
  dp[0] = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    add(ans, *max_element(dp.begin(), dp.end()) % P);
    vi ndp(n, numeric_limits<int>::min());
    for (int j = 0; j < m; ++j) {
      ndp[u[j]] = max(ndp[u[j]], dp[v[j]] + w[j]);
      ndp[v[j]] = max(ndp[v[j]], dp[u[j]] + w[j]);
    }
    swap(dp, ndp);
  }
  //cerr << dp << '\n';
  vector<pii> pts;
  for (int i = 0; i < m; ++i) {
    int val = max(dp[u[i]], dp[v[i]]);
    //cerr << pii(w[i], val - w[i] * n) << '\n';
    pts.emplace_back(w[i], val - w[i] * n);
  }
  //cerr << "BEF " << ans << '\n';
  sort(pts.begin(), pts.end());
  vector<pii> stk;
  // (t, 1) * point
  for (const auto& pt : pts) {
    if (!stk.empty() && stk.back().fir == pt.fir) stk.pop_back();
    while (stk.size() > 1 && ((stk[stk.size() - 1] - stk[stk.size() - 2]) * (pt - stk[stk.size() - 1])) >= 0) {
      //cerr << "POP  " << stk[stk.size() - 2] << ' '<< stk[stk.size() - 1] << ' ' << pt << '\n';
      stk.pop_back();
    }
    stk.push_back(pt);
  }
  auto contrib = [&](ll l, ll r, const pii& lne) {
    l = max(l, (ll)n);
    r = min(r, (ll)q);
    //cerr << "RES " << l << ' ' << r << '\n';
    if (l <= r)
      ans = (ans + (r - l + 1) * lne.sec % P + (l + r) * (r - l + 1LL) / 2 % P * lne.fir) % P;
    if (ans < 0) ans += P;
  };
  //cerr << stk << '\n';
  ll cur = numeric_limits<ll>::min();
  for (int i = 0; i + 1 < stk.size(); ++i) {
    // b1-b2 >= (k2-k1) * t
    ll nxt = dfrac( stk[i].sec - stk[i + 1].sec, stk[i + 1].fir - stk[i].fir);
    //cerr << "DEAL " << cur + 1 << " --- " << nxt << '\n';
    contrib(cur + 1, nxt, stk[i]);
    cur = nxt;
  }
  contrib(cur + 1, numeric_limits<ll>::max(), stk.back());
  cout << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}