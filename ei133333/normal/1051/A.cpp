#include <bits/stdc++.h>

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
  int T;
  cin >> T;
  while(T--) {
    string S;
    cin >> S;

    auto check = [&](char c) {
      if(islower(c)) return 1;
      if(isupper(c)) return 2;
      return 4;
    };
    string X = "aA1";

    int bit = 0;
    vector< int > pre;
    for(auto &c : S) {
      bit |= check(c);
      pre.emplace_back(bit);
    }
    vector< int > suf;
    bit = 0;
    reverse(begin(S), end(S));
    for(auto &c : S) {
      bit |= check(c);
      suf.emplace_back(bit);
    }
    reverse(begin(suf), end(suf));
    reverse(begin(S), end(S));
    if(bit == 7) {
      cout << S << endl;
      continue;
    }

    for(int i = 0; i < S.size(); i++) {
      int latte = 0;
      if(i > 0) latte |= pre[i - 1];
      if(i + 1 < S.size()) latte |= suf[i + 1];
      for(int j = 0; j < 3; j++) {
        if((latte | (1 << j)) == 7) {
          S[i] = X[j];
          bit = 7;
          break;
        }
      }
      if(bit == 7) break;
    }

    if(bit == 7) {
      cout << S << endl;
      continue;
    }



    int cur = suf.back();
    for(int j = 0; j < 3; j++) {
      for(int k = j + 1; k < 3; k++) {
        if((cur | (1 << j) | (1 << k)) == 7) {
          S[0] = X[j];
          S[1] = X[k];
          bit = 7;
          break;
        }
      }
      if(bit == 7) break;
    }
    cout << S << endl;
  }

}