#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

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


int main() {
  int N, M;
  cin >> N >> M;
  auto A = make_v< int >(N, M);
  cin >> A;
  for(int i = 0; i < 2; i++) {

    auto check = [&](vector< int > &fliped, int op) {
      vector< int > latte(N), malta(M);

      auto G = [&](int x, int y) {
        return A[x][y] ^ latte[x] ^ malta[y];
      };

      latte[0] = i;
      for(int k = 0; k < M; k++) {
        if(G(0, k) != fliped[k]) malta[k] = true;
      }


      for(int k = 1; k < N; k++) {
        if(op == 0) {
          // 001
          bool ok1 = true, ok2 = true;
          for(int l = 0; l < M; l++) {
            if(G(k, l) == 1) ok1 = false;
            if(G(k, l) == 0) ok2 = false;
          }
          if(ok1) {

          } else if(ok2) {
            latte[k] = true;
          } else {
            int t = G(k, 0);
            if(t == 0) {
              for(int l = 0; l < M; l++) {
                if(op == 0) {
                  if(G(k, l) == 1) op = 1;
                } else {
                  if(G(k, l) == 0) return;
                }
              }
            } else {
              latte[k] ^= 1;
              for(int l = 0; l < M; l++) {
                if(op == 0) {
                  if(G(k, l) == 1) op = 1;
                } else {
                  if(G(k, l) == 0) return;
                }
              }
            }
          }
        } else if(op == 1) {
          int f = G(k, 0);
          if(f == 0) latte[k] = true;
          for(int l = 0; l < M; l++) {
            if(G(k, l) == 0) return;
          }
        }
      }
      cout << "YES" << endl;
      for(auto &p : latte) cout << p;
      cout << endl;
      for(auto &p : malta) cout << p;
      cout << endl;
      exit(0);
    };

    vector< int > T(M, 1);
    check(T, 1);
    for(int l = 0; l < M; l++) {
      T[l] = 0;
      check(T, l + 1 != M);
    }
  }
  cout << "NO" << endl;
}