#include <bits/stdc++.h>

using namespace std;

//fast IO by yosupo
struct Scanner {
  FILE *fp = nullptr;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;

  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += fread(line + ed, 1, (1 << 15) - ed, fp);
    line[ed] = '\0';
  }

  bool succ() {
    while(true) {
      if(st == ed) {
        reread();
        if(st == ed) return false;
      }
      while(st != ed && isspace(line[st])) st++;
      if(st != ed) break;
    }
    if(ed - st <= 50) reread();
    return true;
  }

  template< class T, enable_if_t< is_same< T, string >::value, int > = 0 >
  bool read_single(T &ref) {
    if(!succ()) return false;
    while(true) {
      size_t sz = 0;
      while(st + sz < ed && !isspace(line[st + sz])) sz++;
      ref.append(line + st, sz);
      st += sz;
      if(!sz || st != ed) break;
      reread();
    }
    return true;
  }

  template< class T, enable_if_t< is_integral< T >::value, int > = 0 >
  bool read_single(T &ref) {
    if(!succ()) return false;
    bool neg = false;
    if(line[st] == '-') {
      neg = true;
      st++;
    }
    ref = T(0);
    while(isdigit(line[st])) {
      ref = 10 * ref + (line[st++] - '0');
    }
    if(neg) ref = -ref;
    return true;
  }

  template< class T >
  bool read_single(vector< T > &ref) {
    for(auto &d : ref) {
      if(!read_single(d)) return false;
    }
    return true;
  }

  void read() {}

  template< class H, class... T >
  void read(H &h, T &... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }

  Scanner(FILE *_fp) : fp(_fp) {}
};

struct Printer {
public:
  template< bool F = false >
  void write() {}

  template< bool F = false, class H, class... T >
  void write(const H &h, const T &... t) {
    if(F) write_single(' ');
    write_single(h);
    write< true >(t...);
  }

  template< class... T >
  void writeln(const T &... t) {
    write(t...);
    write_single('\n');
  }

  Printer(FILE *_fp) : fp(_fp) {}

  ~Printer() { flush(); }

private:
  static constexpr size_t SIZE = 1 << 15;
  FILE *fp;
  char line[SIZE], small[50];
  size_t pos = 0;

  void flush() {
    fwrite(line, 1, pos, fp);
    pos = 0;
  }

  void write_single(const char &val) {
    if(pos == SIZE) flush();
    line[pos++] = val;
  }

  template< class T, enable_if_t< is_integral< T >::value, int > = 0 >
  void write_single(T val) {
    if(pos > (1 << 15) - 50) flush();
    if(val == 0) {
      write_single('0');
      return;
    }
    if(val < 0) {
      write_single('-');
      val = -val;  // todo min
    }
    size_t len = 0;
    while(val) {
      small[len++] = char('0' + (val % 10));
      val /= 10;
    }
    reverse(small, small + len);
    memcpy(line + pos, small, len);
    pos += len;
  }

  void write_single(const string &s) {
    for(char c : s) write_single(c);
  }

  void write_single(const char *s) {
    size_t len = strlen(s);
    for(size_t i = 0; i < len; i++) write_single(s[i]);
  }

  template< class T >
  void write_single(const vector< T > &val) {
    auto n = val.size();
    for(size_t i = 0; i < n; i++) {
      if(i) write_single(' ');
      write_single(val[i]);
    }
  }
};

using ll=long long;
//#define int ll

#define rng(i, a, b) for(int i=int(a);i<int(b);i++)
#define rep(i, b) rng(i,0,b)
#define gnr(i, a, b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i, b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template< class t, class u >
void chmax(t &a, u b) { if(a < b)a = b; }

template< class t, class u >
void chmin(t &a, u b) { if(b < a)a = b; }

template< class t > using vc=vector< t >;
template< class t > using vvc=vc< vc< t>>;

using pi=pair< int, int >;
using vi=vc< int >;

template< class t, class u >
ostream &operator<<(ostream &os, const pair< t, u > &p) {
  return os << "{" << p.a << "," << p.b << "}";
}

template< class t >
ostream &operator<<(ostream &os, const vc< t > &v) {
  os << "{";
  for(auto e:v)os << e << ",";
  return os << "}";
}

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
  os<<t<<" ";
  dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

using uint=unsigned;
using ull=unsigned long long;

template< class t, size_t n >
ostream &operator<<(ostream &os, const array< t, n > &a) {
  return os << vc< t >(all(a));
}

template< int i, class T >
void print_tuple(ostream &, const T &) {
}

template< int i, class T, class H, class ...Args >
void print_tuple(ostream &os, const T &t) {
  if(i)os << ",";
  os << get< i >(t);
  print_tuple< i + 1, T, Args... >(os, t);
}

template< class ...Args >
ostream &operator<<(ostream &os, const tuple< Args... > &t) {
  os << "{";
  print_tuple< 0, tuple< Args... >, Args... >(os, t);
  return os << "}";
}

template< class t >
void print(t x, int suc = 1) {
  cout << x;
  if(suc == 1)
    cout << "\n";
  if(suc == 2)
    cout << " ";
}

ll read() {
  ll i;
  cin >> i;
  return i;
}

vi readvi(int n, int off = 0) {
  vi v(n);
  rep(i, n)v[i] = read() + off;
  return v;
}

template< class T >
void print(const vector< T > &v, int suc = 1) {
  rep(i, v.size())print(v[i], i == int(v.size()) - 1 ? suc : 2);
}

string readString() {
  string s;
  cin >> s;
  return s;
}

template< class T >
T sq(const T &t) {
  return t * t;
}

//#define CAPITAL
void yes(bool ex = true) {
#ifdef CAPITAL
  cout<<"YES"<<"\n";
#else
  cout << "Yes" << "\n";
#endif
  if(ex)exit(0);
}

void no(bool ex = true) {
#ifdef CAPITAL
  cout<<"NO"<<"\n";
#else
  cout << "No" << "\n";
#endif
  if(ex)exit(0);
}

void possible(bool ex = true) {
#ifdef CAPITAL
  cout<<"POSSIBLE"<<"\n";
#else
  cout << "Possible" << "\n";
#endif
  if(ex)exit(0);
}

void impossible(bool ex = true) {
#ifdef CAPITAL
  cout<<"IMPOSSIBLE"<<"\n";
#else
  cout << "Impossible" << "\n";
#endif
  if(ex)exit(0);
}

constexpr ll ten(int n) {
  return n == 0 ? 1 : ten(n - 1) * 10;
}

const ll infLL = LLONG_MAX / 3;

#ifdef int
const int inf=infLL;
#else
const int inf = INT_MAX / 2 - 100;
#endif

int topbit(signed t) {
  return t == 0 ? -1 : 31 - __builtin_clz(t);
}

int topbit(ll t) {
  return t == 0 ? -1 : 63 - __builtin_clzll(t);
}

int botbit(signed a) {
  return a == 0 ? 32 : __builtin_ctz(a);
}

int botbit(ll a) {
  return a == 0 ? 64 : __builtin_ctzll(a);
}

int popcount(signed t) {
  return __builtin_popcount(t);
}

int popcount(ll t) {
  return __builtin_popcountll(t);
}

bool ispow2(int i) {
  return i && (i & -i) == i;
}

int mask(int i) {
  return (int(1) << i) - 1;
}

bool inc(int a, int b, int c) {
  return a <= b && b <= c;
}

template< class t >
void mkuni(vc< t > &v) {
  sort(all(v));
  v.erase(unique(all(v)), v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
#ifdef LOCAL
  static mt19937_64 gen;
#else
  static random_device rd;
  static mt19937_64 gen(rd());
#endif
  return uniform_int_distribution< ll >(l, r)(gen);
}

template< class t >
int lwb(const vc< t > &v, const t &a) {
  return lower_bound(all(v), a) - v.bg;
}

using uint=unsigned;
using ull=unsigned long long;

struct modinfo {
  uint mod, root;
};

template< modinfo const &ref >
struct modular {
  static constexpr uint const &mod = ref.mod;

  static modular root() { return modular(ref.root); }

  uint v;

  //modular(initializer_list<uint>ls):v(*ls.bg){}
  modular(ll vv = 0) { s(vv % mod + mod); }

  modular &s(uint vv) {
    v = vv < mod ? vv : vv - mod;
    return *this;
  }

  modular operator-() const { return modular() - *this; }

  modular &operator+=(const modular &rhs) { return s(v + rhs.v); }

  modular &operator-=(const modular &rhs) { return s(v + mod - rhs.v); }

  modular &operator*=(const modular &rhs) {
    v = ull(v) * rhs.v % mod;
    return *this;
  }

  modular &operator/=(const modular &rhs) { return *this *= rhs.inv(); }

  modular operator+(const modular &rhs) const { return modular(*this) += rhs; }

  modular operator-(const modular &rhs) const { return modular(*this) -= rhs; }

  modular operator*(const modular &rhs) const { return modular(*this) *= rhs; }

  modular operator/(const modular &rhs) const { return modular(*this) /= rhs; }

  modular pow(int n) const {
    modular res(1), x(*this);
    while(n) {
      if(n & 1)res *= x;
      x *= x;
      n >>= 1;
    }
    return res;
  }

  modular inv() const { return pow(mod - 2); }

  /*modular inv()const{
    int x,y;
    int g=extgcd(v,mod,x,y);
    assert(g==1);
    if(x<0)x+=mod;
    return modular(x);
  }*/
  friend modular operator+(int x, const modular &y) {
    return modular(x) + y;
  }

  friend modular operator-(int x, const modular &y) {
    return modular(x) - y;
  }

  friend modular operator*(int x, const modular &y) {
    return modular(x) * y;
  }

  friend modular operator/(int x, const modular &y) {
    return modular(x) / y;
  }

  friend ostream &operator<<(ostream &os, const modular &m) {
    return os << m.v;
  }

  friend istream &operator>>(istream &is, modular &m) {
    ll x;
    is >> x;
    m = modular(x);
    return is;
  }

  bool operator<(const modular &r) const { return v < r.v; }

  bool operator==(const modular &r) const { return v == r.v; }

  bool operator!=(const modular &r) const { return v != r.v; }

  explicit operator bool() const {
    return v;
  }
};

#define USE_FMT

/*
//998244353
const mint prim_root=3;
//in-place fft
//size of input must be a power of 2
void inplace_fmt(vector<mint>&f,const bool inv){
	const int n=f.size();
	const mint root=inv?prim_root.inv():prim_root;
	vc<mint> g(n);
	for(int b=n/2;b>=1;b/=2){
		mint w=root.pow((mint::base-1)/(n/b)),p=1;
		for(int i=0;i<n;i+=b*2){
			rep(j,b){
				f[i+j+b]*=p;
				g[i/2+j]=f[i+j]+f[i+b+j];
				g[n/2+i/2+j]=f[i+j]-f[i+b+j];
			}
			p*=w;
		}
		swap(f,g);
	}
	if(inv)rep(i,n)
		f[i]*=inv[n];
}*/

//size of input must be a power of 2
//output of forward fmt is bit-reversed
//output elements are in the range [0,mod*4)
//input of inverse fmt should be bit-reversed
template< class mint >
void inplace_fmt(vector< mint > &f, bool inv) {
  const int n = si(f);
  static const int L = 30;
  static mint g[L], ig[L], p2[L];
  if(g[0].v == 0) {
    rep(i, L) {
      mint w = -mint::root().pow(((mint::mod - 1) >> (i + 2)) * 3);
      g[i] = w;
      ig[i] = w.inv();
      p2[i] = mint(1 << i).inv();
    }
  }
  static constexpr uint mod2 = mint::mod * 2;
  if(!inv) {
    int b = n;
    if(b >>= 1) {//input:[0,mod)
      rep(i, b) {
        uint x = f[i + b].v;
        f[i + b].v = f[i].v + mint::mod - x;
        f[i].v += x;
      }
    }
    if(b >>= 1) {//input:[0,mod*2)
      mint p = 1;
      for(int i = 0, k = 0; i < n; i += b * 2) {
        rng(j, i, i + b) {
          uint x = (f[j + b] * p).v;
          //f[j].v=(f[j].v<mint::mod?f[j].v:f[j].v-mint::mod);
          f[j + b].v = f[j].v + mint::mod - x;
          f[j].v += x;
        }
        p *= g[__builtin_ctz(++k)];
      }
    }
    while(b) {
      if(b >>= 1) {//input:[0,mod*3)
        mint p = 1;
        for(int i = 0, k = 0; i < n; i += b * 2) {
          rng(j, i, i + b) {
            uint x = (f[j + b] * p).v;
            //f[j].v=(f[j].v<mint::mod?f[j].v:f[j].v-mint::mod);
            f[j + b].v = f[j].v + mint::mod - x;
            f[j].v += x;
          }
          p *= g[__builtin_ctz(++k)];
        }
      }
      if(b >>= 1) {//input:[0,mod*4)
        mint p = 1;
        for(int i = 0, k = 0; i < n; i += b * 2) {
          rng(j, i, i + b) {
            uint x = (f[j + b] * p).v;
            f[j].v = (f[j].v < mod2 ? f[j].v : f[j].v - mod2);
            f[j + b].v = f[j].v + mint::mod - x;
            f[j].v += x;
          }
          p *= g[__builtin_ctz(++k)];
        }
      }
    }
  } else {
    int b = 1;
    if(b < n / 2) {//input:[0,mod)
      mint p = 1;
      for(int i = 0, k = 0; i < n; i += b * 2) {
        rng(j, i, i + b) {
          ull x = f[j].v + mint::mod - f[j + b].v;
          f[j].v += f[j + b].v;
          f[j + b].v = x * p.v % mint::mod;
        }
        p *= ig[__builtin_ctz(++k)];
      }
      b <<= 1;
    }
    for(; b < n / 2; b <<= 1) {
      mint p = 1;
      for(int i = 0, k = 0; i < n; i += b * 2) {
        rng(j, i, i + b / 2) {//input:[0,mod*2)
          ull x = f[j].v + mod2 - f[j + b].v;
          f[j].v += f[j + b].v;
          f[j].v = (f[j].v) < mod2 ? f[j].v : f[j].v - mod2;
          f[j + b].v = x * p.v % mint::mod;
        }
        rng(j, i + b / 2, i + b) {//input:[0,mod)
          ull x = f[j].v + mint::mod - f[j + b].v;
          f[j].v += f[j + b].v;
          //f[j].v=(f[j].v)<mod2?f[j].v:f[j].v-mod2;
          f[j + b].v = x * p.v % mint::mod;
        }
        p *= ig[__builtin_ctz(++k)];
      }
    }
    if(b < n) {//input:[0,mod*2)
      rep(i, b) {
        uint x = f[i + b].v;
        f[i + b].v = f[i].v + mod2 - x;
        f[i].v += x;
      }
    }
    mint z = p2[__lg(n)];
    rep(i, n)f[i] *= z;
  }
}

/*
template<class mint>
vc<mint> multiply(vc<mint> x,const vc<mint>&y,bool same=false){
	int n=si(x)+si(y)-1;
	int s=1;
	while(s<n)s*=2;
	x.resize(s);inplace_fmt(x,false);
	if(!same){
		vc<mint> z(s);
		rep(i,si(y))z[i]=y[i];
		inplace_fmt(z,false);
		rep(i,s)x[i]*=z[i];
	}else{
		rep(i,s)x[i]*=x[i];
	}
	inplace_fmt(x,true);x.resize(n);
	return x;
}
*/

//59501818244292734739283969=5.95*10^25 
// 2^24 
// 2^20  3 
//VERIFY: yosupo
namespace arbitrary_convolution {
  constexpr modinfo base0{167772161,3};//2^25 * 5 + 1
  constexpr modinfo base1{469762049,3};//2^26 * 7 + 1
  constexpr modinfo base2{754974721,11};//2^24 * 45 + 1
  //constexpr modinfo base0{1045430273, 3};//2^20 * 997 + 1
  //constexpr modinfo base1{1051721729, 6};//2^20 * 1003 + 1
  //constexpr modinfo base2{1053818881, 7};//2^20 * 1005 + 1
  using mint0=modular< base0 >;
  using mint1=modular< base1 >;
  using mint2=modular< base2 >;

  template< class t, class mint >
  vc< t > sub(const vc< mint > &x, const vc< mint > &y, bool same = false) {
    int n = si(x) + si(y) - 1;
    int s = 1;
    while(s < n)s *= 2;
    vc< t > z(s);
    rep(i, si(x))z[i] = x[i].x;
    inplace_fmt(z, false);
    if(!same) {
      vc< t > w(s);
      rep(i, si(y))w[i] = y[i].x;
      inplace_fmt(w, false);
      rep(i, s)z[i] *= w[i];
    } else {
      rep(i, s)z[i] *= z[i];
    }
    inplace_fmt(z, true);
    z.resize(n);
    return z;
  }

  template< class mint >
  vc< mint > multiply(const vc< mint > &x, const vc< mint > &y, bool same = false) {
    auto d0 = sub< mint0 >(x, y, same);
    auto d1 = sub< mint1 >(x, y, same);
    auto d2 = sub< mint2 >(x, y, same);
    int n = si(d0);
    vc< mint > res(n);
    static const mint1 r01 = mint1(mint0::mod).inv();
    static const mint2 r02 = mint2(mint0::mod).inv();
    static const mint2 r12 = mint2(mint1::mod).inv();
    static const mint2 r02r12 = r02 * r12;
    static const mint w1 = mint(mint0::mod);
    static const mint w2 = w1 * mint(mint1::mod);
    rep(i, n) {
      ull a = d0[i].v;
      ull b = (d1[i].v + mint1::mod - a) * r01.v % mint1::mod;
      ull c = ((d2[i].v + mint2::mod - a) * r02r12.v + (mint2::mod - b) * r12.v) % mint2::mod;
      res[i].x = (a + b * w1.x + c * w2.x) % mint::get_mod();
    }
    return res;
  }
}
using arbitrary_convolution::multiply;

struct ArbitraryModInt {

  int x;

  ArbitraryModInt() : x(0) {}

  ArbitraryModInt(int64_t y) : x(y >= 0 ? y % get_mod() : (get_mod() - (-y) % get_mod()) % get_mod()) {}

  static int &get_mod() {
    static int mod = 0;
    return mod;
  }

  static void set_mod(int md) {
    get_mod() = md;
  }

  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {
    if((x += p.x) >= get_mod()) x -= get_mod();
    return *this;
  }

  ArbitraryModInt &operator-=(const ArbitraryModInt &p) {
    if((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
    return *this;
  }

  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {
    unsigned long long a = (unsigned long long) x * p.x;
    unsigned xh = (unsigned) (a >> 32), xl = (unsigned) a, d, m;
    asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (get_mod()));
    x = m;
    return *this;
  }

  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ArbitraryModInt operator-() const { return ArbitraryModInt(-x); }

  ArbitraryModInt operator+(const ArbitraryModInt &p) const { return ArbitraryModInt(*this) += p; }

  ArbitraryModInt operator-(const ArbitraryModInt &p) const { return ArbitraryModInt(*this) -= p; }

  ArbitraryModInt operator*(const ArbitraryModInt &p) const { return ArbitraryModInt(*this) *= p; }

  ArbitraryModInt operator/(const ArbitraryModInt &p) const { return ArbitraryModInt(*this) /= p; }

  bool operator==(const ArbitraryModInt &p) const { return x == p.x; }

  bool operator!=(const ArbitraryModInt &p) const { return x != p.x; }

  ArbitraryModInt inverse() const {
    int a = x, b = get_mod(), u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ArbitraryModInt(u);
  }

  ArbitraryModInt pow(int64_t n) const {
    ArbitraryModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ArbitraryModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ArbitraryModInt &a) {
    int64_t t;
    is >> t;
    a = ArbitraryModInt(t);
    return (is);
  }
};


signed main() {
  //cin.tie(0);
  //ios::sync_with_stdio(0);
  //cout<<fixed<<setprecision(20);

  Scanner sc(stdin);
  Printer pr(stdout);

  int n, m, p;
  sc.read(n, m, p);
  ArbitraryModInt::set_mod(p);
  vc< ArbitraryModInt > a(n), b(m);
  rep(i, n){
    sc.read(a[i].x);
    a[i].x%=p;
  }
  rep(i, m){
    sc.read(b[i].x);
    b[i].x%=p;
  }
  auto c = multiply(a, b);
  rep(i, c.size()) {
    if(c[i] != 0) {
      pr.writeln(i);
      break;
    }
  }
}