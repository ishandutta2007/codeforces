#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;


using int64 = long long;
const int mod = 1e9 + 7;

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

int main() {
  int N, K;
  cin >> N >> K;

  auto D = make_v< int >(N, N);
  cin >> D;

  vector< vector< vector< pair< int, int > > > > min_dist(vector< vector< vector< pair< int, int > > > >(N, vector< vector< pair< int, int > > >(N)));
  for(int k = 0; k < N; k++) {
    for(int l = 0; l < N; l++) {
      for(int m = 0; m < N; m++) {
        if(k == m || l == m) continue;
        min_dist[k][l].emplace_back(D[k][m] + D[m][l], m);
      }
      sort(begin(min_dist[k][l]), end(min_dist[k][l]));
    }
  }

  vector< int > left(K / 2 + 1), used(N);
  used[0]++;

  int64 ret = infll;
  MFP([&](auto gen, int sz) -> void {
    if(sz * 2 == K) {
      int64 add = 0;
      for(int k = 1; k < left.size(); k++) {
        int64 top = inf;
        for(auto &p : min_dist[left[k - 1]][left[k]]) {
          if(used[p.second] > 0) continue;
          top = p.first;
          break;
        }
        add += top;
      }
      chmin(ret, add);
    } else {
      for(int k = 0; k < N; k++) {
        left[sz] = k;
        used[k]++;
        gen(sz + 1);
        used[k]--;
      }
    }
  })(1);
  cout << ret << endl;
}