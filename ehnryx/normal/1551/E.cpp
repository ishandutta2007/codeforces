%:include <bits/stdc++.h>
using namespace std;

// START #include "../../../lca/misc/fast_input.h"

template <int buf_size = 10000>
struct fast_input {
  char buf[buf_size], *S, *T, c;
  int positive;
  FILE* ifptr;
  fast_input(FILE* _in = stdin): S(buf), T(buf), ifptr(_in) {}

  inline char getc(void) {
    if (S == T) {
      T = (S = buf) + fread(buf, 1, buf_size, ifptr);
      if (S == T) return EOF;
    }
    return *S++;
  }

  inline void read(char& x) {
    while (isspace(x = getc()));
  }

  inline void read(string& x) {
    x.clear();
    while (isspace(c = getc()));
    for (; !isspace(c); c = getc()) {
      x.push_back(c);
    }
  }

  template <typename var_t, enable_if_t<is_integral_v<var_t>, bool> = true>
  inline void read(var_t& x) {
    x = 0;
    positive = 1;
    while (!isdigit(c = getc())) {
      positive = (c ^ '-');
    }
    for (; isdigit(c); c = getc()) {
      x = x * 10 + c - '0';
    }
    if (!positive) {
      x = -x;
    }
  }

  template <typename var_t, enable_if_t<is_floating_point_v<var_t>, bool> = true>
  inline void read(var_t& x) {
    x = 0;
    positive = 1;
    while (!isdigit(c = getc()) && c != '.') {
      positive = (c ^ '-');
    }
    if (c != '.') {
      for (; isdigit(c); c = getc()) {
        x = x * 10 + c - '0';
      }
    }
    if (c == '.') {
      static var_t div;
      div = 1;
      while (isdigit(c = getc())) {
        x = x * 10 + c - '0';
        div *= 10;
      }
      x /= div;
    }
    if (!positive) {
      x = -x;
    }
  }

  template <typename T>
  fast_input& operator >> (T& x) {
    read(x);
    return *this;
  }
};

// END #include "../../../lca/misc/fast_input.h"

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);

  fast_input cin;

  int T;
  cin >> T;
  while(T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) {
      cin >> a[i];
    }
    vector dp(n+1, 0);
    for(int i=1; i<=n; i++) {
      if(a[i] > i) continue;
      dp[i] = 1;
      for(int j=1; j<i; j++) {
        if(a[j] < a[i] && a[i] - a[j] <= i - j) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    int ans = n+1;
    for(int i=1; i<=n; i++) {
      if(dp[i] >= k) {
        ans = min(ans, i - a[i]);
      }
    }
    if(ans > n) {
      cout << -1 << nl;
    } else {
      cout << ans << nl;
    }
  }

  return 0;
}