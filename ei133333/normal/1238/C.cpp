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
  int T;
  cin >> T;
  while(T--) {
    int H, N;
    cin >> H >> N;
    vector< int > P(N);
    cin >> P;
    vector< int > xs;
    for(int i = 0; i < N; i++) {
      for(int j = -2; j <= 2; j++) {
        xs.emplace_back(P[i] + j);
        if(xs.back() < 0 || xs.back() > H) xs.pop_back();
      }
    }
    xs.emplace_back(0);
    if(H >= 1) xs.emplace_back(1);
    if(H >= 2) xs.emplace_back(2);
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
    vector< int > exist(xs.size());
    for(int i = 0; i < N; i++) {
      P[i] = lower_bound(begin(xs), end(xs), P[i]) - begin(xs);
      exist[P[i]] = true;
    }
    int cur = 0;

    for(int i = (int) xs.size() - 1; i > 0; i--) {
      if(xs[i] - xs[i - 1] > 2) {
        exist[i - 1] = true;
      } else {
        exist[i - 1] ^= 1;
        if(!exist[i - 1]) {
          if(i == 2 || (i >= 2 && exist[i - 2])) {
            i--;
          } else {
            ++cur;
          }
        }
      }
    }
    cout << cur << endl;
  }
}