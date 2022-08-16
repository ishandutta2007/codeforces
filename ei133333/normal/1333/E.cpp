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

int main() {
  int N;
  cin >> N;
  if(N <= 2) {
    cout << -1 << endl;
    return 0;
  }

  /*

  vector< int > A{1, 2, 3, 4, 5, 6, 7, 8, 9};
  do {
    auto B = make_v< int >(3, 3);
    for(int k = 0; k < 9; k++) B[k / 3][k % 3] = A[k];

    auto V = make_v< int >(3, 3);
    auto find_min = [&]() {
      int a, b, val = inf;
      for(int k = 0; k < 3; k++) {
        for(int l = 0; l < 3; l++) {
          if(V[k][l]) continue;
          if(chmin(val, B[k][l])) {
            a = k;
            b = l;
          }
        }
      }
      return make_pair(a, b);
    };
    int latte = 0;

    int y, x;
    tie(y, x) = find_min();
    V[y][x] = true;
    for(int k = 0; k < 8; k++) {
      int a, b, val = inf;
      for(int l = 0; l < 3; l++) {
        if(V[y][l]) continue;
        if(chmin(val, B[y][l])) {
          a = y;
          b = l;
        }
      }
      for(int l = 0; l < 3; l++) {
        if(V[l][x]) continue;
        if(chmin(val, B[l][x])) {
          a = l;
          b = x;
        }
      }
      if(val == inf) {
        ++latte;
        tie(y, x) = find_min();
      } else {
        tie(y, x) = make_pair(a, b);
      }
      V[y][x] = true;
    }


    fill_v(V, 0);
    tie(y, x) = find_min();
    V[y][x] = true;
    int malta = 0;
    for(int k = 0; k < 8; k++) {
      int a, b, val = inf;
      for(int l = 0; l < 3; l++) {
        if(V[y][l]) continue;
        if(chmin(val, B[y][l])) {
          a = y;
          b = l;
        }
      }
      for(int l = 0; l < 3; l++) {
        if(V[l][x]) continue;
        if(chmin(val, B[l][x])) {
          a = l;
          b = x;
        }
      }
      for(int l = -10; l <= 10; l++) {
        if(!(0 <= y + l && 0 <= x + l && y + l < 3 && x + l < 3) || V[y + l][x + l]) continue;
        if(chmin(val, B[y + l][x + l])) {
          a = y + l;
          b = x + l;
        }
      }
      for(int l = -10; l <= 10; l++) {
        if(!(0 <= y - l && 0 <= x + l && y - l < 3 && x + l < 3) || V[y - l][x + l]) continue;
        if(chmin(val, B[y - l][x + l])) {
          a = y - l;
          b = x + l;
        }
      }
      if(val == inf) {
        ++malta;
        tie(y, x) = find_min();
      } else {
        tie(y, x) = make_pair(a, b);
      }
      V[y][x] = true;
    }


    if(latte<malta) {
      for(auto& p : B) cout << p << endl;
      exit(0);
    }


  } while(next_permutation(begin(A), end(A)));

  */

  int remain = N * N - 9;
  auto A = make_v< int >(N, N);
  A[0][0] = 1;
  A[0][1] = 2;
  A[0][2] = 4;
  A[1][0] = 5;
  A[1][1] = 3;
  A[1][2] = 8;
  A[2][0] = 9;
  A[2][1] = 6;
  A[2][2] = 7;
  for(int k = 0; k < 3; k++) {
    for(int l = 0; l < 3; l++) A[k][l] += remain;
  }
  int ptr = 1;
  for(int x = 0; x < N; x++) {
    if(x % 2 == 0) {
      for(int y = 3; y < N; y++) {
        A[x][y] = ptr++;
      }
    } else {
      for(int y = N - 1; y >= 3; y--) {
        A[x][y] = ptr++;
      }
    }
  }
  for(int x = N - 1; x >= 3; x--) {
    if(x % 2 == 0) {
      for(int y = 0; y < 3; y++) {
        A[x][y] = ptr++;
      }
      if(x == 3) {
        swap(A[x][0], A[x][2]);
      }
    } else {
      for(int y = 2; y >= 0; y--) {
        A[x][y] = ptr++;
      }
    }
  }

  for(auto &p : A) cout << p << "\n";
}