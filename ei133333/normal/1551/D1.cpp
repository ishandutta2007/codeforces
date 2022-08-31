#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
// const int mod = 1e9 + 7;
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

const int vy[] = {1, 0, -1, 0};
const int vx[] = {0, 1, 0, -1};

int main() {
  int T;
  cin >> T;
  while(T--) {
    int64 N, M, K;
    cin >> N >> M >> K;
    int L = N * M / 2 - K;
    auto S = make_v< char >(N, M);
    auto mex = [&](int y1, int x1, int y2, int x2) {
      set< char > st;
      for(int k = 0; k < 4; k++) {
        int ny = vy[k] + y1;
        int nx = vx[k] + x1;
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) {
          continue;
        }
        st.emplace(S[ny][nx]);
      }
      for(int k = 0; k < 4; k++) {
        int ny = vy[k] + y2;
        int nx = vx[k] + x2;
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) {
          continue;
        }
        st.emplace(S[ny][nx]);
      }
      char a = 'a';
      while(st.count(a)) ++a;
      return a;
    };
    if(N % 2 == 1) {
      for(int i : {0}) {
        for(int j = 0; j + 1 < M; j += 2) {
          if(K > 0) {
            S[i][j] = S[i][j + 1] = mex(i, j, i, j + 1);
            --K;
          }
        }
      }
      for(int i = 1; i + 1 < N; i += 2) {
        for(int j = 0; j + 1 < M; j += 2) {
          if(K >= 2) {
            S[i][j] = S[i][j + 1] = mex(i, j, i, j + 1);
            S[i + 1][j] = S[i + 1][j + 1] = mex(i + 1, j, i + 1, j + 1);
            K -= 2;
          }
        }
      }
    } else {
      for(int i = 0; i + 1 < N; i += 2) {
        for(int j = 0; j + 1 < M; j += 2) {
          if(K >= 2) {
            S[i][j] = S[i][j + 1] = mex(i, j, i, j + 1);
            S[i + 1][j] = S[i + 1][j + 1] = mex(i + 1, j, i + 1, j + 1);
            K -= 2;
          }
        }
      }
    }


    for(int i = 0; i + 1 < N; i++) {
      for(int j = 0; j < M; j++) {
        if(not S[i][j] and not S[i + 1][j]) {
          if(L > 0) {
            S[i][j] = S[i + 1][j] = mex(i, j, i + 1, j);
            --L;
          }
        }
      }
    }
    if(K == 0 and L == 0) {
      cout << "YES\n";
      /*
      for(auto &ss : S) {
        for(auto &s : ss) cout << s;
        cout << "\n";
      }*/
    } else {
      cout << "NO\n";
    }
  }
}