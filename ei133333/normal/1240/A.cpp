#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;

using int64 = long long;
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

void beet() {
  int64 N, X, A, Y, B, K;
  cin >> N;
  vector< int > P(N);
  cin >> P;
  cin >> X >> A >> Y >> B >> K;
  sort(P.rbegin(), P.rend());

  if(X < Y) {
    swap(X, Y);
    swap(A, B);
  }
  auto check = [&](int cnt) {
    int a = 0, b = 0, c = 0;
    for(int i = 1; i <= cnt; i++) {
      if(i % A == 0) {
        if(i % B == 0) ++c;
        else ++a;
      } else if(i % B == 0) {
        ++b;
      }
    }
    int64 ret = 0;
    for(int i = 0; i < N; i++) {
      if(c > 0) {
        ret += P[i] / 100 * (X + Y);
        --c;
      } else if(a > 0) {
        ret += P[i] / 100 * X;
        --a;
      } else if(b > 0) {
        ret += P[i] / 100 * Y;
        --b;
      }
      if(ret >= K) return true;
    }
    return false;
  };
  int ok = N, ng = 0;
  if(!check(ok)) {
    cout << -1 << endl;
    return;
  }
  while(ok - ng > 1) {
    int md = (ok + ng) / 2;
    if(check(md)) ok = md;
    else ng = md;
  }
  cout << ok << endl;
}

int main() {
  int Q;
  cin >> Q;
  while(Q--) beet();
}