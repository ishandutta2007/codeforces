#pragma GCC optimize("O3")
#pragma target("sse4")

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// START %:include "utility/fast_input.h"

// START #include "member_function_checker.h"

#define MEMBER_FUNCTION_CHECKER(FUNCTION) \
  template <typename __class_t, typename... __args_t> \
  struct _has_##FUNCTION { \
    template <typename __class> \
    static constexpr auto check(__class*) -> \
      typename std::is_void<std::void_t< \
        decltype(std::declval<__class&>().FUNCTION(std::declval<__args_t>()...))>>::type; \
    template <typename __dummy> \
    static constexpr auto check(...) -> std::false_type; \
    using type = decltype(check<__class_t>(0)); \
    static constexpr bool value = type::value; \
  }

// END #include "member_function_checker.h"

#include <complex>
#include <string>
#include <tuple>
#include <vector>

#define USING_FAST_INPUT

template <size_t buf_size = 10000>
struct fast_input {
  char buf[buf_size], *S, *T, c = 0;
  int positive;
  FILE* ifptr;
  fast_input(FILE* _in = stdin): S(buf), T(buf), ifptr(_in) {}

  explicit operator bool() const { return c != EOF; }

  inline char getc(void) {
    if (c == EOF) return EOF;
    if (S == T) {
      T = (S = buf) + fread(buf, 1, buf_size, ifptr);
      if (S == T) return c = EOF;
    }
    return *S++;
  }

  inline void get(char& x) {
    while (isspace(x = getc()) && x != EOF);
  }

  inline void get(std::string& x) {
    x.clear();
    while (isspace(c = getc()) && c != EOF);
    for (; !isspace(c) && c != EOF; c = getc()) {
      x.push_back(c);
    }
  }

  inline void get(decltype(std::ignore)) {
    while (isspace(c = getc()) && c != EOF);
    for (; !isspace(c) && c != EOF; c = getc());
  }

  template <typename var_t, std::enable_if_t<std::is_integral_v<var_t>, bool> = true>
  inline void get(var_t& x) {
    x = 0;
    positive = 1;
    while (!isdigit(c = getc()) && c != EOF) {
      positive = (c ^ '-');
    }
    for (; isdigit(c) && c != EOF; c = getc()) {
      x = x * 10 + c - '0';
    }
    if (!positive) {
      x = -x;
    }
  }

  template <typename var_t, std::enable_if_t<std::is_floating_point_v<var_t>, bool> = true>
  inline void get(var_t& x) {
    x = 0;
    positive = 1;
    while (!isdigit(c = getc()) && c != '.' && c != EOF) {
      positive = (c ^ '-');
    }
    if (c != '.') {
      for (; isdigit(c) && c != EOF; c = getc()) {
        x = x * 10 + c - '0';
      }
    }
    if (c == '.') {
      static var_t div;
      div = 1;
      while (isdigit(c = getc()) && c != EOF) {
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
  inline void get(std::complex<T>& x) {
    x.real(getv<T>());
    x.imag(getv<T>());
  }

  template <typename T, typename U>
  inline void get(std::pair<T, U>& x) {
    *this >> x.first >> x.second;
  }

  template <size_t index = 0, typename... T>
  inline void get(std::tuple<T...>& x) {
    if constexpr (index < sizeof...(T)) {
      *this >> (std::get<index>(x));
      get<index + 1>(x);
    }
  }

  MEMBER_FUNCTION_CHECKER(get);

  template <typename T>
  inline fast_input& operator >> (T& x) {
    if constexpr (_has_get<fast_input, T&>::value) {
      get(x);
    } else {
      x.fast_read(*this);
    }
    return *this;
  }

  std::string getline() {
    std::string out;
    while ((c = getc()) != '\n' && c != EOF) {
      out.push_back(c);
    }
    return out;
  }

  std::vector<std::string> readlines(int n) {
    std::vector<std::string> out;
    out.reserve(n);
    for (int i = 0; i < n; i++) {
      out.push_back(getline());
    }
    return out;
  }

  template <typename T>
  T getv() {
    T x;
    *this >> x;
    return x;
  }

  template <typename... T, std::enable_if_t<sizeof...(T) != 1, bool> = true>
  std::tuple<T...> getv() {
    return getv<std::tuple<T...>>();
  }

  template <typename T, int pad_n = 0>
  std::vector<T> read(int n) {
    return readinit<T, pad_n>(n, T());
  }

  template <typename T, int pad_n = 0, int pad_m = 0>
  std::vector<std::vector<T>> read(int n, int m) {
    return readinit<T, pad_n, pad_m>(n, m, T());
  }

  template <typename T, int pad_n = 0, int pad_m = 0, int pad_h = 0>
  std::vector<std::vector<std::vector<T>>> read(int n, int m, int h) {
    return readinit<T, pad_n, pad_m, pad_h>(n, m, h, T());
  }

  template <typename T, int pad_n = 0>
  std::vector<T> readinit(int n, T init) {
    std::vector<T> out(n + 2 * pad_n, init);
    for (int i = 0; i < n; i++) {
      *this >> out[pad_n + i];
    }
    return out;
  }

  template <typename T, int pad_n = 0, int pad_m = 0>
  std::vector<std::vector<T>> readinit(int n, int m, T init) {
    std::vector out(n + 2 * pad_n, std::vector<T>(m + 2 * pad_m, init));
    for (int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        *this >> out[pad_n + i][pad_m + j];
      }
    }
    return out;
  }

  template <typename T, int pad_n = 0, int pad_m = 0, int pad_h = 0>
  std::vector<std::vector<std::vector<T>>> readinit(int n, int m, int h, T init) {
    std::vector out(n + 2 * pad_n, std::vector(m + 2 * pad_m,
          std::vector<T>(h + 2 * pad_h, init)));
    for (int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        for (int k = 0; k < h; k++) {
          *this >> out[pad_n + i][pad_m + j][pad_h + k];
        }
      }
    }
    return out;
  }
};

// END %:include "utility/fast_input.h"

using ll = long long;
using ld = long double;

constexpr char nl = '\n';

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#ifdef USING_FAST_INPUT
  fast_input cin;
#endif

  int T;
  cin >> T;
  vector<pair<ll, int>> ev;
  ev.reserve(2 * T + 1);
  for(int i=1; i<=T; i++) {
    ll a, b;
    cin >> a >> b;
    ev.emplace_back(a-1, -i);
    ev.emplace_back(b, i);
  }
  sort(begin(ev), end(ev));

  vector<unsigned> ans(T);
  {
    static constexpr int M = 1e9;
    ev.emplace_back((ll)(M+1) * (M+1), 0);
    unsigned cur = 0;
    ll v = 0;
    for(int x=1, i=0; x<=M; x+=4) {
      const ll vs[] = {
        v + 2*x   - 1 , v + 3ll*x - 1  , v +  4ll*x - 1,
        v + 4ll*x     , v + 5ll*x + 1  , v +  6ll*x + 2,
        v + 6ll*x + 3 , v + 7ll*x + 5  , v +  8ll*x + 7,
        v + 8ll*x + 8 , v + 9ll*x + 11 , v + 10ll*x + 14,
      };
      while (vs[11] > ev[i].first) {
        const int id = ev[i].second;
        const unsigned good = (vs[0] <= ev[i].first) + (vs[1] <= ev[i].first) + (vs[2] <= ev[i].first)
          + (vs[3] <= ev[i].first) + (vs[4] <= ev[i].first) + (vs[5] <= ev[i].first)
          + (vs[6] <= ev[i].first) + (vs[7] <= ev[i].first) + (vs[8] <= ev[i].first)
          + (vs[9] <= ev[i].first) + (vs[10] <= ev[i].first) + (vs[11] <= ev[i].first);
        const int sgn = (id < 0 ? -1 : 1);
        ans[sgn * id - 1] += sgn * (cur + good);
        i++;
      }
      v = vs[9];
      cur += 12;
    }
  }

  for(int i=0; i<T; i++) {
    cout << ans[i] << nl;
  }

  return 0;
}