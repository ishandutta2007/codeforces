#include<bits/stdc++.h>

using namespace std;
using int64 = long long;
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
  int N, K;
  cin >> N >> K;
  map< int, int > latte, malta;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    latte[i] = x;
    malta[x] = i;
  }
  vector< int > ans(N);
  bool f = false;
  while(latte.size()) {
    auto p = *prev(malta.end());
    malta.erase(p.first);
    vector< int > add{p.second};
    latte.erase(p.second);
    for(int j = 0; j < K; j++) {
      auto it = latte.lower_bound(p.second);
      if(it == latte.begin()) break;
      --it;
      add.emplace_back(it->first);
      malta.erase(it->second);
      latte.erase(it->first);
    }

    for(int j = 0; j < K; j++) {
      auto it = latte.lower_bound(p.second);
      if(it == latte.end()) break;
      add.emplace_back(it->first);
      malta.erase(it->second);
      latte.erase(it->first);
    }
    for(auto& v : add) ans[v] = f;
    f ^= 1;
  }
  for(auto &t : ans) cout << t + 1;
  cout << endl;
}