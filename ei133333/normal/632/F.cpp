#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const int64 infll = (1LL << 61) - 1;


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

void fail() {
  puts("NOT MAGIC");
  exit(0);
}

using pi = pair< int, int >;

int N, A[2500][2500];
vector< pi > belong[6250000];
bitset< 2500 > uku[2500];

int main() {
  scanf("%d", &N);

  vector< int > v(N * N);

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      scanf("%d", &A[i][j]);
      v[i * N + j] = A[i][j];
    }
  }

  for(int i = 0; i < N; i++) {
    if(A[i][i]) fail();
    for(int j = 0; j < i; j++) {
      if(A[i][j] != A[j][i]) fail();
    }
  }

  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), end(v));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      belong[lower_bound(begin(v), end(v), A[i][j]) - begin(v)].emplace_back(i, j);
    }
  }


  for(int z = 6249999; z >= 0; z--) {
    for(auto &p : belong[z]) uku[p.first][p.second] = true;
    for(auto &p : belong[z]) {
      if((uku[p.first] | uku[p.second]).count() < N) fail();
    }
  }

  puts("MAGIC");
}