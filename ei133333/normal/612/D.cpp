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
  int N, K;
  scanf("%d %d", &N, &K);
  map< int, pair< int, int > > add;
  for(int i = 0; i < N; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    add[l].first++;
    add[r].second--;
  }
  vector< int > ans;
  int sum = 0;
  for(auto &p : add) {
    int presum = sum;
    sum += p.second.first;
    if(presum < K && sum >= K) {
      ans.emplace_back(p.first);
    }
    presum = sum;
    sum += p.second.second;
    if(presum >= K && sum < K) {
      ans.emplace_back(p.first);
    }
  }


  printf("%d\n", (int) ans.size() / 2);
  for(int i = 0; i < ans.size(); i += 2) printf("%d %d\n", ans[i], ans[i + 1]);
}