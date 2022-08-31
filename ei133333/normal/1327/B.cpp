#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
//const int mod = 998244353;

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
    int N;
    cin >> N;
    vector< vector< int > > g;
    for(int i = 0; i < N; i++) {
      int K;
      cin >> K;
      vector< int > G(K);
      cin >> G;
      for(auto &t : G) --t;
      g.emplace_back(G);
    }


    vector< int > used(N);
    vector< int > pend;
    vector< pair< int, int > > tap;
    for(int i = 0; i < N; i++) {
      bool f = false;
      for(auto &p : g[i]) {
        if(used[p]) continue;
        used[p] = true;
        f = true;
        break;
      }
      if(!f) pend.emplace_back(i);
    }
    int ptr = 0;
    for(int k = 0; k < used.size(); k++) {
      if(used[k]) continue;
      tap.emplace_back(pend[ptr++] + 1, k + 1);
    }

    if(tap.empty()) {
      cout << "OPTIMAL" << "\n";
    } else {
      cout << "IMPROVE" << "\n";
      for(auto& p : tap) {
        cout << p << "\n";
        break;
      }
    }
  }
}