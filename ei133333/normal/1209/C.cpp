#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

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
inline bool chmax(T1 &a, T2 b) {
  return a < b && (a = b, true);
}

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) {
  return a > b && (a = b, true);
}

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
    int N;
    cin >> N;
    string D;
    cin >> D;

    bool ok = false;
    for(int stop = 0; stop <= 9; stop++) {
      vector< int > be[10];
      for(int i = 0; i < N; i++) {
        be[D[i] - '0'].emplace_back(i);
      }
      int last = -1;
      vector< int > used(N, 2);
      vector< int > latte;
      for(int i = 0; i <= stop; i++) {
        auto pos = lower_bound(begin(be[i]), end(be[i]), last) - begin(be[i]);
        for(int j = pos; j < be[i].size(); j++) {
          used[be[i][j]] = 1;
          latte.emplace_back(i);
          last = be[i][j];
        }
      }
      for(int i = 0; i < N; i++) {
        if(used[i] == 2) latte.emplace_back(D[i] - '0');
      }

      if(is_sorted(begin(latte), end(latte))) {
        for(auto &p : used) cout << p;
        cout << endl;
        ok = true;
        break;
      }
    }
    if(!ok) cout << "-" << endl;

  }

}