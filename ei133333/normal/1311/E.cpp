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

  //,,
  set< tuple< int, int, int > > state;
  state.emplace(1, 0, 1);
  auto depth = make_v< int >(5001, 5001);
  auto size = make_v< int >(5001, 5001);
  fill_v(depth, -1);
  depth[1][0] = 0;
  size[1][0] = 1;
  for(int k = 1; k <= 105; k++) {
    set< tuple< int, int, int > > nxt_state;
    for(auto &p : state) {
      int a, b, c;
      tie(a, b, c) = p;
      const int limit = c * 2;
      for(int i = 1; i <= limit && a + i <= 5000 && b + k * i <= 5000; i++) {
        if(depth[a + i][b + k * i] == -1) {
          depth[a + i][b + k * i] = k;
          size[a + i][b + k * i] = i;
          nxt_state.emplace(a + i, b + k * i, i);
        }
      }
    }
    swap(state, nxt_state);
  }

  int T;
  cin >> T;
  while(T--) {
    int N, D;
    cin >> N >> D;
    if(depth[N][D] == -1) {
      cout << "NO\n";
    } else {
      vector< vector< int > > depths(depth[N][D] + 1);
      vector< int > p(N);
      for(int k = depth[N][D]; k >= 0; k--) {
        depths[k].resize(size[N][D]);
        int next_n = N - size[N][D];
        int next_d = D - k * size[N][D];
        N = next_n;
        D = next_d;
      }
      int ptr = 0;
      for(int k = 0; k < depths.size(); k++) {
        for(auto &p : depths[k]) p = ptr++;
      }
      MFP([&](auto dfs, int depth, int idx, int par) -> void {
        p[depths[depth][idx]] = par;
        if(depth + 1 >= depths.size()) return;
        if(idx * 2 < depths[depth + 1].size()) dfs(depth + 1, idx * 2, depths[depth][idx]);
        if(idx * 2 + 1 < depths[depth + 1].size()) dfs(depth + 1, idx * 2 + 1, depths[depth][idx]);
        return;
      })(0, 0, -1);
      cout << "YES\n";
      for(int k = 1; k < p.size(); k++) cout << p[k] + 1 << " ";
      cout << "\n";
    }
  }
}