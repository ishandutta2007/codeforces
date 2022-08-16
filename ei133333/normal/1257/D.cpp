#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
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

void beet() {

  int N, M;
  cin >> N;
  vector< int > A(N);
  cin >> A;
  cin >> M;
  vector< int > P(M), S(M), ord(M);
  for(int i = 0; i < M; i++) {
    cin >> P[i] >> S[i];
    ord[i] = i;
  }
  sort(begin(ord), end(ord), [&](int a, int b) {
    return P[a] < P[b];
  });
  vector< pair< int, int > > st;
  for(int i : ord) {
    while(st.size() && st.back().second <= S[i]) {
      st.pop_back();
    }
    st.emplace_back(P[i], S[i]);
  }
  int used = 0;
  for(int day = 1;; day++) {

    auto pos = upper_bound(begin(st), end(st), make_pair(A[used], -1)) - begin(st);
    if(st.size() == pos) {
      cout << -1 << endl;
      return;
    }
    ++used;

    if(used == N) {
      cout << day << endl;
      return;
    }

    for(int uku = 2;; uku++) {
      auto pos2 = upper_bound(begin(st), end(st), make_pair(A[used], -1)) - begin(st);
      if(st.size() == pos2) break;

      chmax(pos, pos2);

      if(st[pos].second < uku) break;
      ++used;
      if(used == N) {
        cout << day << endl;
        return;
      }
    }

  }
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    beet();
  }
}