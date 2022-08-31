#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

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


int main() {
  int N, M;
  cin >> N >> M;
  vector< int > X(M);
  cin >> X;
  for(auto &p : X) --p;
  X.erase(unique(begin(X), end(X)), end(X));


  M = X.size();
  int64 ret = 0;
  vector< int > uku[200000];
  vector< int > add(N + 1);
  for(int i = 1; i < M; i++) {
    ret += abs(X[i] - X[i - 1]);
    uku[X[i]].emplace_back(i);
    uku[X[i - 1]].emplace_back(i);

    int p = min(X[i], X[i - 1]);
    int q = max(X[i], X[i - 1]);
    add[p]++;
    add[q - 1]--;
  }

  vector< int64 > ans{ret};
  int64 cur = add[0];
  for(int i = 1; i < N; i++) {
    //i
    //i

    int64 ret2 = 0;
    for(auto &p : uku[i]) {
      ret2 -= abs(X[p] - X[p - 1]);
      int now = X[p] ^X[p - 1] ^i;
      if(now < i) ret2 += now + 1;
      else ret2 += now;
    }
    ans.emplace_back(ret2 - cur + ret);


    cur += add[i];


  }
  cout << ans << endl;
}