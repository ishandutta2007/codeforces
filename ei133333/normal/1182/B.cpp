#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

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
  int H, W;
  cin >> H >> W;
  vector< string > S(H);
  cin >> S;
  for(int i = 1; i + 1 < S.size(); i++) {
    for(int j = 1; j + 1 < S[i].size(); j++) {
      if(S[i - 1][j] == '*' && S[i + 1][j] == '*' && S[i][j - 1] == '*' && S[i][j + 1] == '*' && S[i][j] == '*') {
        S[i][j] = '.';
        for(int k = j-1; k >= 0 && S[i][k] == '*'; k--) S[i][k] = '.';
        for(int k = j+1; k < S[i].size() && S[i][k] == '*'; k++) S[i][k] = '.';
        for(int k = i-1; k >= 0 && S[k][j] == '*'; k--) S[k][j] = '.';
        for(int k = i+1; k < S.size() && S[k][j] == '*'; k++) S[k][j] = '.';


        for(int k = 0; k < S.size(); k++) {
          if(count(S[k].begin(), S[k].end(), '*') > 0) {
            cout << "NO" << endl;
            return 0;
          }
        }
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}