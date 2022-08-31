#include<bits/stdc++.h>

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
  int T;
  cin >> T;
  while(T--) {
    string S;
    cin >> S;
    sort(begin(S), end(S));
    string X, Y;
    for(auto &p : S) {
      if(p & 1) X += p;
      else Y += p;
    }
    if(X.empty()) {
      cout << Y << endl;
    } else if(Y.empty()) {
      cout << X << endl;
    } else {
      map< char, int > x, y;
      for(int i = X.size() - 1; i >= 0; i--) x[X[i]] = i;
      for(int i = Y.size() - 1; i >= 0; i--) y[Y[i]] = i;

      bool ok = false;

      for(auto p : x) {
        for(auto &q : y) {
          if(abs(p.first - q.first) != 1) {
            string Z;
            for(int j = 0; j < X.size(); j++) {
              Z += X[(p.second + j) % X.size()];
            }
            reverse(begin(Z), end(Z));
            cout << Z;
            for(int j = 0; j < Y.size(); j++) {
              cout << Y[(q.second + j) % Y.size()];
            }
            cout << endl;
            ok = true;
            break;
          }
        }
        if(ok) break;
      }
      if(!ok) {
        cout << "No answer" << endl;
      }
    }
  }
}