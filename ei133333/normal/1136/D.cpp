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

vector< int > g[300000];
list< int > undef;
int rev[300000];

void dfs(int idx) {
  sort(begin(g[idx]), end(g[idx]));
  auto it = undef.begin();
  vector< int > add;
  for(auto &to : g[idx]) {
    while(it != undef.end() && *it < to) {
      if(*it < idx) {
        add.emplace_back(*it);
        it = undef.erase(it);
      } else {
        break;
      }
    }
    if(it != undef.end() && *it == to) ++it;
  }
  while(it != undef.end()) {
    if(*it < idx) {
      add.emplace_back(*it);
      it = undef.erase(it);
    } else {
      break;
    }
  }
  for(auto &to : add) dfs(to);
}


int main() {

  int N, M;
  scanf("%d %d", &N, &M);
  vector< int > P(N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &P[i]);
    --P[i];
    rev[P[i]] = i;
  }
  for(int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    g[rev[b]].emplace_back(rev[a]);
  }
  for(int i = 0; i < N; i++) {
    if(i != rev[P[N - 1]]) undef.emplace_back(i);
  }
  dfs(rev[P[N - 1]]);
  printf("%d", (int) undef.size());
}