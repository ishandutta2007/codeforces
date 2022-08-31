#include<bits/stdc++.h>

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

/**
 * @brief Largest-Rectangle()
 * @docs docs/largest-rectangle.md
 */
template< typename T >
int64_t largest_rectangle(vector< T > height, int pos) {
  stack< int > st;
  height.push_back(0);
  vector< int > left(height.size());
  int64_t ret = 0;
  for(int i = 0; i < height.size(); i++) {
    while(!st.empty() && height[st.top()] >= height[i]) {
      int R = i;
      int L = left[st.top()];
      if(L+1 <= pos and pos < R) {
        ret = max(ret, (int64_t) (R - L - 1) * height[st.top()]);
      }
      st.pop();
    }
    left[i] = st.empty() ? -1 : st.top();
    st.emplace(i);
  }

  return (ret);
}

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  auto A = make_v< int >(N, M);
  cin >> A;
  auto board = make_v< int >(4, N, M);

  auto TatteMalta = [&](int x) {
    for(int i = 0, j = 0; i < N; i++) {
      if(A[i][x]) j++;
      else j = 0;
      board[0][i][x] = j;
    }
    for(int i = N - 1, j = 0; i >= 0; i--) {
      if(A[i][x]) j++;
      else j = 0;
      board[1][i][x] = j;
    }
  };
  auto YokkoMalta = [&](int y) {
    for(int i = 0, j = 0; i < M; i++) {
      if(A[y][i]) j++;
      else j = 0;
      board[2][y][i] = j;
    }
    for(int i = M - 1, j = 0; i >= 0; i--) {
      if(A[y][i]) j++;
      else j = 0;
      board[3][y][i] = j;
    }
  };
  for(int i = 0; i < M; i++) TatteMalta(i);
  for(int i = 0; i < N; i++) YokkoMalta(i);

  while(Q--) {
    int op, y, x;
    cin >> op >> y >> x;
    --y, --x;
    if(op == 1) {
      A[y][x] ^= 1;
      TatteMalta(x);
      YokkoMalta(y);
    } else {
      // ...
      int best = 0;

      {
        vector< int > F(M);
        for(int i = 0; i < M; i++) {
          F[i] = board[0][y][i];
        }
        chmax(best, largest_rectangle(F, x));
      }

      {
        vector< int > F(M);
        for(int i = 0; i < M; i++) {
          F[i] = board[1][y][i];
        }
        chmax(best, largest_rectangle(F, x));
      }

      {
        vector< int > F(N);
        for(int i = 0; i < N; i++) {
          F[i] = board[2][i][x];
        }
        chmax(best, largest_rectangle(F, y));
      }


      {
        vector< int > F(N);
        for(int i = 0; i < N; i++) {
          F[i] = board[3][i][x];
        }
        chmax(best, largest_rectangle(F, y));
      }
      cout << best << "\n";
    }
  }
}