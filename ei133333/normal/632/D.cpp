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

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  vector< int > A[1000001];
  for(int i = 0; i < N; i++) {
    int x;
    scanf("%d", &x);
    if(x <= M) A[x].emplace_back(i);
  }

  int ret = 0, pos = 1;

  vector< int > dp(1000001);
  for(int i = M; i >= 1; i--) {
    dp[i] = (int) A[i].size();
    for(int j = i + i; j <= M; j += i) dp[j] += dp[i];
  }
  for(int i = 1; i <= M; i++) {
    if(chmax(ret, dp[i])) pos = i;
  }

  vector< int > ans;
  for(int i = M; i >= 1; i--) {
    if(pos % i == 0) for(auto &p : A[i]) ans.emplace_back(p);
  }


  printf("%d %d\n", pos, ret);
  sort(begin(ans), end(ans));
  for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i] + 1);
  puts("");
}