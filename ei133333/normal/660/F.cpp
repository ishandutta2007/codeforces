#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
// const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

/**
 * @brief Scanner()
 */
struct Scanner {
public:

  explicit Scanner(FILE *fp) : fp(fp) {}

  template< typename T, typename... E >
  void read(T &t, E &... e) {
    read_single(t);
    read(e...);
  }

private:
  static constexpr size_t line_size = 1 << 16;
  static constexpr size_t int_digits = 20;
  char line[line_size + 1] = {};
  FILE *fp = nullptr;
  char *st = line;
  char *ed = line;

  void read() {}

  static inline bool is_space(char c) {
    return c <= ' ';
  }

  void reread() {
    ptrdiff_t len = ed - st;
    memmove(line, st, len);
    char *tmp = line + len;
    ed = tmp + fread(tmp, 1, line_size - len, fp);
    *ed = 0;
    st = line;
  }

  void skip_space() {
    while(true) {
      if(st == ed) reread();
      while(*st && is_space(*st)) ++st;
      if(st != ed) return;
    }
  }

  template< typename T, enable_if_t< is_integral< T >::value, int > = 0 >
  void read_single(T &s) {
    skip_space();
    if(st + int_digits >= ed) reread();
    bool neg = false;
    if(is_signed< T >::value && *st == '-') {
      neg = true;
      ++st;
    }
    typename make_unsigned< T >::type y = *st++ - '0';
    while(*st >= '0') {
      y = 10 * y + *st++ - '0';
    }
    s = (neg ? -y : y);
  }

  template< typename T, enable_if_t< is_same< T, string >::value, int > = 0 >
  void read_single(T &s) {
    s = "";
    skip_space();
    while(true) {
      char *base = st;
      while(*st && !is_space(*st)) ++st;
      s += string(base, st);
      if(st != ed) return;
      reread();
    }
  }

  template< typename T >
  void read_single(vector< T > &s) {
    for(auto &d : s) read(d);
  }
};

/**
 * @brief Printer()
 */
struct Printer {
public:
  explicit Printer(FILE *fp) : fp(fp) {}

  ~Printer() { flush(); }

  template< bool f = false, typename T, typename... E >
  void write(const T &t, const E &... e) {
    if(f) write_single(' ');
    write_single(t);
    write< true >(e...);
  }

  template< typename... T >
  void writeln(const T &...t) {
    write(t...);
    write_single('\n');
  }

  void flush() {
    fwrite(line, 1, st - line, fp);
    st = line;
  }

private:
  FILE *fp = nullptr;
  static constexpr size_t line_size = 1 << 16;
  static constexpr size_t int_digits = 20;
  char line[line_size + 1] = {};
  char small[32] = {};
  char *st = line;

  template< bool f = false >
  void write() {}

  void write_single(const char &t) {
    if(st + 1 >= line + line_size) flush();
    *st++ = t;
  }

  template< typename T, enable_if_t< is_integral< T >::value, int > = 0 >
  void write_single(T s) {
    if(st + int_digits >= line + line_size) flush();
    if(s == 0) {
      write_single('0');
      return;
    }
    if(s < 0) {
      write_single('-');
      s = -s;
    }
    char *mp = small + sizeof(small);
    typename make_unsigned< T >::type y = s;
    size_t len = 0;
    while(y > 0) {
      *--mp = y % 10 + '0';
      y /= 10;
      ++len;
    }
    memmove(st, mp, len);
    st += len;
  }

  void write_single(const string &s) {
    for(auto &c : s) write_single(c);
  }

  void write_single(const char *s) {
    while(*s != 0) write_single(*s++);
  }

  template< typename T >
  void write_single(const vector< T > &s) {
    for(size_t i = 0; i < s.size(); i++) {
      if(i) write_single(' ');
      write_single(s[i]);
    }
  }
};

template< typename T, bool isMin >
struct ConvexHullTrickAddMonotone {
#define F first
#define S second
  using P = pair< T, T >;
  deque< P > H;

  ConvexHullTrickAddMonotone() = default;

  bool empty() const { return H.empty(); }

  void clear() { H.clear(); }

  inline int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }

  using D = long double;

  inline bool check(const P &a, const P &b, const P &c) {
    if(b.S == a.S || c.S == b.S)
      return sgn(b.F - a.F) * sgn(c.S - b.S) >= sgn(c.F - b.F) * sgn(b.S - a.S);

    //return (b.F-a.F)*(c.S-b.S) >= (b.S-a.S)*(c.F-b.F);
    return
        D(b.F - a.F) * sgn(c.S - b.S) / D(abs(b.S - a.S)) >=
        D(c.F - b.F) * sgn(b.S - a.S) / D(abs(c.S - b.S));
  }

  void add(T a, T b) {
    if(!isMin) a *= -1, b *= -1;
    P line(a, b);
    if(empty()) {
      H.emplace_front(line);
      return;
    }
    if(H.front().F <= a) {
      if(H.front().F == a) {
        if(H.front().S <= b) return;
        H.pop_front();
      }
      while(H.size() >= 2 && check(line, H.front(), H[1])) H.pop_front();
      H.emplace_front(line);
    } else {
      assert(a <= H.back().F);
      if(H.back().F == a) {
        if(H.back().S <= b) return;
        H.pop_back();
      }
      while(H.size() >= 2 && check(H[H.size() - 2], H.back(), line)) H.pop_back();
      H.emplace_back(line);
    }
  }

  inline T get_y(const P &a, const T &x) {
    return a.F * x + a.S;
  }

  T query(T x) {
    assert(!empty());
    int l = -1, r = H.size() - 1;
    while(l + 1 < r) {
      int m = (l + r) >> 1;
      if(get_y(H[m], x) >= get_y(H[m + 1], x)) l = m;
      else r = m;
    }
    if(isMin) return get_y(H[r], x);
    return -get_y(H[r], x);
  }

  T query_monotone_inc(T x) {
    assert(!empty());
    while(H.size() >= 2 && get_y(H.front(), x) >= get_y(H[1], x)) H.pop_front();
    if(isMin) return get_y(H.front(), x);
    return -get_y(H.front(), x);
  }

  T query_monotone_dec(T x) {
    assert(!empty());
    while(H.size() >= 2 && get_y(H.back(), x) >= get_y(H[H.size() - 2], x)) H.pop_back();
    if(isMin) return get_y(H.back(), x);
    return -get_y(H.back(), x);
  }

#undef F
#undef S
};

int main() {
  Scanner in(stdin);
  Printer out(stdout);
  int N;
  in.read(N);
  vector< int64 > A(N);
  in.read(A);
  int64 ret = 0;
  auto rec = MFP([&](auto rec, int l, int r) {
    if(l + 1 >= r) {
      chmax(ret, A[l]);
      return;
    }
    int m = (l + r) / 2;
    rec(l, m);
    rec(m, r);
    // [l, m) -> [m, r)

    //(x+0)*s[m]+(x+1)*s[m+1]+(x+2)*s[m+2]
    ConvexHullTrickAddMonotone< int64, false > cht;

    {
      int64 a = 0, b = 0;
      vector< pair< int64, int64 > > lines;
      for(int i = m; i < r; i++) {
        a += A[i];
        b += A[i] * (i - m);
        lines.emplace_back(a, b);
      }
      sort(begin(lines), end(lines));
      for(auto &p : lines) cht.add(p.first, p.second);
    }

    {
      // s[m-1]*1
      // s[m-2]*1+s[m-1]*2
      // s[m-3]*1+s[m-2]*2+s[m-1]*3
      int64 sum = 0, all = 0;
      for(int i = m - 1; i >= l; i--) {
        all += A[i];
        sum += all;
        chmax(ret, cht.query(m - i+1) + sum);
      }
    }
  });
  rec(0, N);
  cout << ret << "\n";
};