#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
//const int mod = 998244353;

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
  vector< pair< int, int > > P(8);
  cin >> P;
  vector< int > ord{0, 1, 2, 3, 4, 5, 6, 7};
  do {
    auto check = [&](vector< int > S) {
      vector< int > V;
      for(int i = 0; i < 4; i++) {
        for(int j = 0; j < i; j++) {
          int dx = P[S[i]].first - P[S[j]].first;
          int dy = P[S[i]].second - P[S[j]].second;
          V.emplace_back(dx * dx + dy * dy);
        }
      }
      sort(begin(V), end(V));
      for(int i = 0; i < 4; i++) {
        for(int j = 0; j < i; j++) {
          for(int k = 0; k < j; k++) {
            int x1 = P[S[i]].first, y1 = P[S[i]].second;
            int x2 = P[S[j]].first, y2 = P[S[j]].second;
            int x3 = P[S[k]].first, y3 = P[S[k]].second;
            x1-=x3;
            x2-=x3;
            y1-=y3;
            y2-=y3;
            if(x1*y2==x2*y1) return false;
          }
        }
      }
      return V[0] == V[3] and V[4] == V[5] and V[4] == V[0] + V[1];
    };
    auto check2 = [&](vector< int > S) {
      vector< int > V;
      for(int i = 0; i < 4; i++) {
        for(int j = 0; j < i; j++) {
          int dx = P[S[i]].first - P[S[j]].first;
          int dy = P[S[i]].second - P[S[j]].second;
          V.emplace_back(dx * dx + dy * dy);
        }
      }
      sort(begin(V), end(V));
      for(int i = 0; i < 4; i++) {
        for(int j = 0; j < i; j++) {
          for(int k = 0; k < j; k++) {
            int x1 = P[S[i]].first, y1 = P[S[i]].second;
            int x2 = P[S[j]].first, y2 = P[S[j]].second;
            int x3 = P[S[k]].first, y3 = P[S[k]].second;
            x1-=x3;
            x2-=x3;
            y1-=y3;
            y2-=y3;
            if(x1*y2==x2*y1) return false;
          }
        }
      }
      return V[0] == V[1] and V[2] == V[3] and V[4] == V[5] and V[5] == V[0] + V[2];
    };

    if(check({ord[0], ord[1], ord[2], ord[3]})) {
      if(check2({ord[4], ord[5], ord[6], ord[7]})) {
        for(auto &p : ord) ++p;
        cout << "YES\n";
        cout << ord[0] << " " << ord[1] << " " << ord[2] << " " << ord[3] << "\n";
        cout << ord[4] << " " << ord[5] << " " << ord[6] << " " << ord[7] << "\n";
        return 0;
      }
    }
  } while(next_permutation(begin(ord), end(ord)));
  cout << "NO\n";
}