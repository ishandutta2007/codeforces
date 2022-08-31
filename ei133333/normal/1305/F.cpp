#include <bits/stdc++.h>

using namespace std;


using int64 = long long;
const int mod = 1000003;

const int64 infll = (1LL << 58) - 1;
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

vector< bool > get_prime(int n) {
  vector< bool > prime(n + 1, true);

  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;

  for(int i = 2; i * i <= n; i++) {
    if(prime[i]) {
      for(int j = i + i; j <= n; j += i) prime[j] = false;
    }
  }

  return (prime);
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
  auto D = get_prime(1000001);
  vector< int > prime;
  for(int k = 2; k < D.size(); k++) {
    if(D[k]) prime.emplace_back(k);
  }

  int N;
  cin >> N;
  vector< int64 > A(N);
  cin >> A;

  int64 ret = inf;
  auto check = [&](int64 val) {
    vector< int64 > fact;
    for(int64 k = 0; k < prime.size() && prime[k] * prime[k] <= val; k++) {
      if(val % prime[k] == 0) {
        while(val % prime[k] == 0) val /= prime[k];
        fact.emplace_back(prime[k]);
      }
    }
    if(val != 1) fact.emplace_back(val);
    for(auto &t : fact) {
      int64 add = 0;
      for(auto &p : A) {
        int64 low = p / t * t;
        int64 high = (p + t - 1) / t * t;
        if(low == 0) add += high - p;
        else add += min(p - low, high - p);
        if(add >= ret) break;
      }
      chmin(ret, add);
    }
    return ret;
  };
  RandomNumberGenerator rng;
  for(int k = 0; k < 30; k++) {
    int pos = rng(N);
    if(A[pos] > 2) chmin(ret, check(A[pos] - 1));
    if(A[pos] > 1) chmin(ret, check(A[pos]));
    chmin(ret, check(A[pos] + 1));
  }
  cout << ret << endl;
}