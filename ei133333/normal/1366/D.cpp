#include <bits/stdc++.h>

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

vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}


int main() {
  const int MAX_A = 10000000;
  vector< int > fact(MAX_A + 1, -1);
  for(int i = 2; i <= MAX_A; i++) {
    if(fact[i] == -1) {
      for(int j = i; j <= MAX_A; j += i) fact[j] = i;
    }
  }
  int N;
  vector< int > buf{9, 15, 21, 35};
  cin >> N;
  vector< int > A(N);
  cin >> A;

  vector< int > D(N, -1), E(N, -1);

  for(int i = 0; i < N; i++) {
    int base = A[i];
    vector< int > st;
    while(A[i] > 1) {
      if(st.empty() || st.back() != fact[A[i]]) {
        st.emplace_back(fact[A[i]]);
      }
      A[i] /= fact[A[i]];
    }
    for(auto &p : buf) {
      if(base % p == 0) st.emplace_back(p);
    }
    
    for(int j = 0; j < st.size(); j++) {
      for(int k = 0; k < j; k++) {
        if(__gcd(st[j] + st[k], base) == 1) {
          D[i] = st[j];
          E[i] = st[k];
          goto ok;
        }
      }
    }
    ok:;
  }
  cout << D << "\n" << E << "\n";
}