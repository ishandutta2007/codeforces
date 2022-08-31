#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = (int) (1e9 + 7);

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

/*
struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;
*/

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
  int N;
  cin >> N;
  vector< int64 > A(N);
  cin >> A;

  vector< int > tap[61];
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 61; j++) {
      if((A[i] >> j) & 1) {
        tap[j].emplace_back(i);
      }
    }
  }
  auto bfs = [&](int s, int t) {
    queue< int > que;
    vector< int > v(N + 61, -1);
    v[s] = 0;
    que.emplace(s);
    while(que.size()) {
      auto p = que.front();
      que.pop();
      if(p < N) {
        for(int i = 0; i < 61; i++) {
          if((A[p] >> i) & 1) {
            if(v[N + i] == -1) {
              v[N + i] = v[p];
              que.emplace(N + i);
            }
          }
        }
      } else {
        for(auto &idx : tap[p - N]) {
          if(v[idx] == -1) {
            if(idx == t && v[p] + 1 == 1) {
              continue;
            }
            v[idx] = v[p] + 1;
            que.emplace(idx);
          }
        }
      }
    }
    return v[t];
  };
  int64 ret = infll;
  for(int bit = 0; bit < 61; bit++) {
    vector< int > be;
    for(int i = 0; i < N; i++) {
      if((A[i] >> bit) & 1) be.emplace_back(i);
    }
    if(be.size() >= 3) {
      chmin(ret, 3);
      continue;
    }
    if(be.size() <= 1) {
      continue;
    }
    auto d = bfs(be[0], be[1]);
    if(~d) chmin(ret, d + 1);
  }
  if(ret >= infll) ret = -1;
  cout << ret << endl;
}