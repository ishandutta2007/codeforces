#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

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
  int N;
  cin >> N;
  auto A = make_v< int >(N, N);
  cin >> A;

  vector< int > X(N * N), Y(N * N);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      --A[i][j];
      Y[A[i][j]] = i;
      X[A[i][j]] = j;
    }
  }

  vector< vector< int > > vy, vx;
  vy.emplace_back(vector< int >{-2, -2, -1, -1, 1, 1, 2, 2});
  vx.emplace_back(vector< int >{-1, 1, -2, 2, -2, 2, -1, 1});

  vy.emplace_back(vector< int >{-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  vx.emplace_back(vector< int >{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

  vy.emplace_back(vector< int >{-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  vx.emplace_back(vector< int >{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

  auto dp = make_v< pair< int, int > >(3);

  for(int i = 1; i < N * N; i++) {
    auto nxtdp = make_v< pair< int, int > >(3);

    using pi = tuple< pair< int, int >, int, int, int >;
    priority_queue< pi, vector< pi >, greater<> > que;
    auto v = make_v< pair< int, int > >(3, N, N);
    for(int j = 0; j < 3; j++) {
      for(int k = 0; k < N; k++) {
        for(int l = 0; l < N; l++) v[j][k][l] = {inf, inf};
      }
    }
    for(int j = 0; j < 3; j++) {
      v[j][Y[i - 1]][X[i - 1]] = dp[j];
      que.emplace(dp[j], Y[i - 1], X[i - 1], j);
    }
    while(que.size()) {
      int y, x, t;
      pair< int, int > cost;
      tie(cost, y, x, t) = que.top();
      que.pop();
      for(int k = 0; k < vy[t].size(); k++) {
        int ny = y + vy[t][k];
        int nx = x + vx[t][k];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if(chmin(v[t][ny][nx], make_pair(v[t][y][x].first + 1, v[t][y][x].second))) {
          que.emplace(v[t][ny][nx], ny, nx, t);
        }
      }

      for(int k = 0; k < 3; k++) {
        if(chmin(v[k][y][x], make_pair(v[t][y][x].first + 1, v[t][y][x].second + 1))) {
          que.emplace(v[k][y][x], y, x, k);
        }
      }

    }
    for(int j = 0; j < 3; j++) {
      nxtdp[j] = v[j][Y[i]][X[i]];
    }
    dp.swap(nxtdp);
  }
  cout << *min_element(begin(dp), end(dp)) << endl;
}