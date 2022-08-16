#include<bits/stdc++.h>

using namespace std;using int64 = long long;
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
  int N, Q;
  cin >> N >> Q;
  deque< int > A(N);
  for(auto &c : A) cin >> c;
  auto L = *max_element(begin(A), end(A));

  vector< int > X, Y;
  while(A.front() != L) {
    auto p = A.front();
    A.pop_front();
    auto q = A.front();
    A.pop_front();
    X.emplace_back(p);
    Y.emplace_back(q);
    if(p < q) {
      A.emplace_front(q);
      A.emplace_back(p);
    } else {
      A.emplace_front(p);
      A.emplace_back(q);
    }
  }

  while(Q--) {
    int64 M;
    cin >> M;
    --M;

    if(M < (int) X.size()) {
      cout << X[M] << " " << Y[M] << "\n";
    } else {
      M -= (int) X.size();
      cout << A[0] << " " << A[1 + M % (N - 1)] << "\n";
    }
  }


}