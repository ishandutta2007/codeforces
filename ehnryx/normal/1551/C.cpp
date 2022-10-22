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

  fast_input in;
  constexpr int M = 6;

  int T;
  in >> T;
  while(T--) {
    int n;
    in >> n;
    vector<array<int, M + 1>> arr;
    for(int i=0; i<n; i++) {
      string s;
      in >> s;
      array<int, M + 1> cnt;
      for(int j=0; j<M; j++) {
        cnt[j] = ranges::count(s, 'a' + j);
      }
      cnt.back() = size(s);
      arr.emplace_back(move(cnt));
    }
    int ans = 0;
    for(int j=0; j<M; j++) {
      ranges::sort(arr, [=](const auto& a, const auto& b) {
          return 2*a[j] - a.back() > 2*b[j] - b.back(); });
      int cnt = 0;
      int same = 0;
      int total = 0;
      for(const auto& it : arr) {
        same += it[j];
        total += it.back();
        if (2*same <= total) {
          break;
        }
        cnt++;
      }
      ans = max(ans, cnt);
    }
    cout << ans << nl;
  }

  return 0;
}