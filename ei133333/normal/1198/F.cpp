#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 62) - 1;
const int64 infll2 = infll / 10;
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

struct RandomNumberGenerator {
  mt19937 mt;

  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  int operator()(int a, int b) { // [a, b)
    uniform_int_distribution< int > dist(a, b - 1);
    return dist(mt);
  }

  int operator()(int b) { // [0, b)
    return (*this)(0, b);
  }
};


int main() {
  auto st = clock();
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;
  vector< int > xs(A);
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  vector< vector< int > > be(xs.size());
  for(int i = 0; i < N; i++) {
    A[i] = lower_bound(begin(xs), end(xs), A[i]) - begin(xs);
    be[A[i]].emplace_back(i);
  }
  vector< int > t;
  for(int i = 0; i < xs.size(); i++) {
    for(int j = 0; j < min((int) be[i].size(), 2); j++) {
      t.emplace_back(be[i][j]);
    }
  }

  RandomNumberGenerator rng;
  while((clock() - st) < 0.1 * CLOCKS_PER_SEC) {
    shuffle(begin(t), end(t), rng.mt);
    int x = 0, gcd = 0;
    while(x < t.size() && gcd != 1) {
      gcd = __gcd(gcd, xs[A[t[x]]]);
      ++x;
    }
    if(gcd != 1) continue;
    gcd = 0;
    while(x < t.size()) {
      gcd = __gcd(gcd, xs[A[t[x]]]);
      ++x;
    }
    if(gcd == 1) {
      x = 0, gcd = 0;
      vector< int > id(N, 1);
      while(x < t.size() && gcd != 1) {
        gcd = __gcd(gcd, xs[A[t[x]]]);
        id[t[x]] = 2;
        ++x;
      }
      cout << "YES" << endl;
      cout << id << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}