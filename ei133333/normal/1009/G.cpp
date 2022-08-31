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
  string S;
  cin >> S;
  vector< int > zan(6);
  for(auto &p : S) zan[p - 'a']++;
  int M;
  cin >> M;
  int N = (int) S.size();
  vector< int > allow(N, (1 << 6) - 1);
  for(int i = 0; i < M; i++) {
    int idx;
    string s;
    cin >> idx >> s;
    --idx;
    allow[idx] = 0;
    for(auto &p : s) {
      allow[idx] |= 1 << (p - 'a');
    }
  }

  // 
  //  |A| <= 

  auto mask = make_v< int >(N + 1, 1 << 6);
  for(int i = N - 1; i >= 0; i--) {
    for(int j = 0; j < (1 << 6); j++) mask[i][j] += mask[i + 1][j];
    mask[i][allow[i]]++;
  }
  for(int i = N - 1; i >= 0; i--) {
    for(int j = 0; j < 6; j++) {
      for(int k = 0; k < (1 << 6); k++) {
        if(k & (1 << j)) mask[i][k] += mask[i][k ^ (1 << j)];
      }
    }
  }


  auto dp = make_v< int >(1 << 6);
  for(int i = 0; i < (1 << 6); i++) {
    for(int j = 0; j < 6; j++) {
      if((i >> j) & 1) dp[i] += zan[j];
    }
  }

  string T;
  for(int i = 0; i < N; i++) {
    bool ok = false;
    for(int j = 0; j < 6; j++) {
      if((~allow[i] >> j) & 1) continue;

      bool latte = true;
      for(int k = 0; k < (1 << 6); k++) {
        int v = dp[k];
        if((k >> j) & 1) v--;
        latte &= v >= mask[i + 1][k];
      }
      if(latte) {
        ok = true;
        T += (char) (j + 'a');
        for(int k = 0; k < (1 << 6); k++) {
          if((k >> j) & 1) {
            dp[k]--;
          }
        }
        break;
      }
    }


    if(!ok) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << T << endl;
}