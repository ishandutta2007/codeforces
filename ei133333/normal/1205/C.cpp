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
  auto ask = [&](int a, int b, int c, int d) {
    cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << endl;
    int t;
    cin >> t;
    return t;
  };
  auto mat = make_v< int >(N, N);
  mat[0][0] = 1;

  for(int i = 0; i < N; i++) {
    if(i % 2 == 0) {
      if(i > 0) {
        if(ask(i - 2, 0, i, 0)) {
          mat[i][0] = mat[i - 2][0];
        } else {
          mat[i][0] = 1 ^ mat[i - 2][0];
        }
      }
      for(int j = 0; j + 2 < N; j += 2) {
        if(i + 1 == N && j + 2 == N - 1) {
          continue;
        }
        if(ask(i, j, i, j + 2)) {
          mat[i][j + 2] = mat[i][j];
        } else {
          mat[i][j + 2] = 1 ^ mat[i][j];
        }
      }
    } else {
      if(ask(i - 1, 0, i, 1)) {
        mat[i][1] = mat[i - 1][0];
      } else {
        mat[i][1] = 1 ^ mat[i - 1][0];
      }
      for(int j = 1; j + 2 < N; j += 2) {
        if(ask(i, j, i, j + 2)) {
          mat[i][j + 2] = mat[i][j];
        } else {
          mat[i][j + 2] = 1 ^ mat[i][j];
        }
      }
    }
  }


  for(int i = N - 1; i >= 0; i--) {
    if(i % 2 == 1) {
      if(ask(i, 0, i + 1, 1)) {
        mat[i][0] = mat[i + 1][1];
      } else {
        mat[i][0] = 1 ^ mat[i + 1][1];
      }
      for(int j = 0; j + 2 < N; j += 2) {
        if(ask(i, j, i, j + 2)) {
          mat[i][j + 2] = mat[i][j];
        } else {
          mat[i][j + 2] = 1 ^ mat[i][j];
        }
      }
    } else {
      if(i + 1 < N) {
        if(ask(i, 1, i + 1, 2)) {
          mat[i][1] = mat[i + 1][2];
        } else {
          mat[i][1] = 1 ^ mat[i + 1][2];
        }
      }
      for(int j = 1; j + 2 < N; j += 2) {
        if(ask(i, j, i, j + 2)) {
          mat[i][j + 2] = mat[i][j];
        } else {
          mat[i][j + 2] = 1 ^ mat[i][j];
        }
      }
    }
  }


  {
    auto judge = MFP([&](auto judge, int a, int b, int c, int d, string p) {
      if(a == c && b == d) {
        p += mat[a][b];
        string q(p);
        reverse(begin(q), end(q));
        return p == q;
      }
      if(a + 1 <= c) {
        if(judge(a + 1, b, c, d, p + (char) mat[a][b])) return true;
      }
      if(b + 1 <= d) {
        if(judge(a, b + 1, c, d, p + (char) mat[a][b])) return true;
      }
      return false;
    });
    for(int x = 0; x + 2 < N; x++) {
      for(int y = 0; y + 2 < N; y++) {
        if((mat[x][y] != mat[x + 2][y + 2] || mat[x + 2][y] != mat[x][y + 2]) && (x + y) % 2 == 0) {

          for(int a = 0; a < 3; a++) {
            for(int b = 0; b < 3; b++) {
              for(int c = a; c < 3; c++) {
                for(int d = b; d < 3; d++) {
                  if(a + b + 2 > c + d) continue;
                  for(int e = 0; e < 3; e++) {
                    for(int f = 0; f < 3; f++) {
                      for(int g = e; g < 3; g++) {
                        for(int h = f; h < 3; h++) {
                          if(e + f + 2 > g + h) continue;

                          auto F1 = judge(a + x, b + y, c + x, d + y, "");
                          auto F2 = judge(e + x, f + y, g + x, h + y, "");
                          mat[0 + x][1 + y] ^= 1;
                          mat[1 + x][0 + y] ^= 1;
                          mat[1 + x][2 + y] ^= 1;
                          mat[2 + x][1 + y] ^= 1;
                          auto G1 = judge(a + x, b + y, c + x, d + y, "");
                          auto G2 = judge(e + x, f + y, g + x, h + y, "");
                          mat[0 + x][1 + y] ^= 1;
                          mat[1 + x][0 + y] ^= 1;
                          mat[1 + x][2 + y] ^= 1;
                          mat[2 + x][1 + y] ^= 1;
                          if(F1 != G1 || F2 != G2) {
                            auto f1 = ask(a + x, b + y, c + x, d + y);
                            auto f2 = ask(e + x, f + y, g + x, h + y);
                            cout << "!" << endl;
                            if((f1 == F1) && (f2 == F2)) {
                              for(int i = 0; i < N; i++) {
                                for(int j = 0; j < N; j++) {
                                  cout << mat[i][j];
                                }
                                cout << endl;
                              }
                            } else {
                              for(int i = 0; i < N; i++) {
                                for(int j = 0; j < N; j++) {
                                  if((i + j) & 1) mat[i][j] ^= 1;
                                  cout << mat[i][j];
                                }
                                cout << endl;
                              }
                            }

                            return 0;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }

      }
    }
  }


}