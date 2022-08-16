#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
//const int mod = 1e9 + 7;
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


template< typename T >
struct edge {
  int to, id;

  edge(int to, T id) : to(to), id(id) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

vector< int > manacher(const string &s) {
  vector< int > radius(s.size());
  int i = 0, j = 0;
  while(i < s.size()) {
    while(i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) {
      ++j;
    }
    radius[i] = j;
    int k = 1;
    while(i - k >= 0 && i + k < s.size() && k + radius[i - k] < j) {
      radius[i + k] = radius[i - k];
      ++k;
    }
    i += k;
    j -= k;
  }
  return radius;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    string S;
    cin >> S;

    auto Solve = [](const string& S) {
      int N = (int) S.size();
      string X = "$";
      for(int i = 0; i < (int) S.size(); i++) {
        X += S[i];
        X += "$";
      }
      auto mana = manacher(X);

      vector< vector< int > > ev(mana.size());
      for(int i = 0; i < (int) mana.size(); i++) {
        int l = i - mana[i] + 1;
        ev[l].emplace_back(mana[i] + l);
      }
      bool flag = true;
      int len = 0, ret = 0;
      int suffix = -1;
      set< int > tap;
      for(int i = 0; i < (int) mana.size(); i++) {
        for(auto& t : ev[i]) {
          tap.emplace(- t);
        }
        if(flag && i % 2 == 1) {
          auto q = tap.lower_bound(len - N - i);
          if(q != tap.end()) {
            if(chmax(ret, len - *q - i)) {
              suffix = (int)mana.size() - i;
            }
          }
        }
        flag &= X[i] == X[(int)X.size() - 1 - i];
        if(i % 2 == 1) len += 2;
      }
      string uku;
      for(int k = suffix; k < X.size(); k++) {
        if(X[k] != '$') {
          uku += X[k];
          --ret;
        }
      }
      string aaa;
      for(int k = 0; k < X.size(); k++) {
        if(X[k] != '$') {
          if(ret > 0) {
            --ret;
            aaa += X[k];
          }
        }
      }
      return aaa + uku;
    };
    auto x = Solve(S);
    reverse(begin(S), end(S));
    auto y = Solve(S);
    reverse(begin(y), end(y));
    if(x.size() > y.size()) cout << x << endl;
    else cout << y << endl;
  }
}