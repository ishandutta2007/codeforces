#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const int64 infll = (1LL << 61) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;

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


int to[20][200000];
vector< pair< int, int > > qs[200000];

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  vector< int > A(N), B(M);

  vector< int > rev(N);
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    --x;
    rev[x] = i;
  }
  for(int i = 0; i < M; i++) {
    int x;
    cin >> x;
    --x;
    B[i] = rev[x];
  }
  for(int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    --l;
    qs[l].emplace_back(r, i);
  }

  vector< int > nxt(N, -1);
  memset(to, -1, sizeof(to));
  for(int i = M - 1; i >= 0; i--) {
    to[0][i] = nxt[(B[i] + 1) % N];
    nxt[B[i]] = i;
  }
  for(int i = 0; i < 19; i++) {
    for(int j = 0; j < M; j++) {
      if(to[i][j] == -1) to[i + 1][j] = -1;
      else to[i + 1][j] = to[i][to[i][j]];
    }
  }
  vector< int > range[200000];
  for(int i = 0; i < M; i++) {
    int bit = N - 1, now = i;
    for(int j = 19; j >= 0; j--) {
      if(now == -1) continue;
      if((bit >> j) & 1) now = to[j][now];
    }
    if(~now) range[i].emplace_back(now);
  }

  int k = inf;
  vector< int > ans(Q);
  for(int i = M - 1; i >= 0; i--) {
    for(auto &p : range[i]) chmin(k, p);
    for(auto &p : qs[i]) ans[p.second] = k < p.first;
  }
  for(auto& p : ans) cout << p;
  cout << endl;
}