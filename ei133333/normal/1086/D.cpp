#include <bits/stdc++.h>

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

const string conv = "RSP";

template< class T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};


int main() {
  int N, Q;
  string S;
  cin >> N >> Q;
  cin >> S;
  for(auto &t : S) t = conv.find(t);

  vector< BinaryIndexedTree< int > > bit;
  for(int i = 0; i < 3; i++) bit.push_back(BinaryIndexedTree< int >(N));
  set< int > P[3];
  for(int i = 0; i < N; i++) {
    P[S[i]].emplace(i);
    bit[S[i]].add(i, 1);
  }

  auto modify = [&](int idx) {
    int good = (idx + 1) % 3;
    int dame = (idx + 2) % 3;
    if(P[dame].empty()) return bit[idx].sum(N - 1);
    if(P[good].empty()) return 0;
    int add = bit[idx].sum(N - 1);
    add -= max(0, bit[idx].sum(*P[good].begin()) - bit[idx].sum(*P[dame].begin()));
    add -= max(0, bit[idx].sum(*prev(P[dame].end())) - bit[idx].sum(*prev(P[good].end())));
    return add;
  };
  cout << modify(0) + modify(1) + modify(2) << endl;
  while(Q--) {
    int idx;
    char c;
    cin >> idx >> c;
    --idx;
    c = conv.find(c);
    bit[S[idx]].add(idx, -1);
    P[S[idx]].erase(idx);
    S[idx] = c;
    bit[S[idx]].add(idx, 1);
    P[S[idx]].emplace(idx);
    cout << modify(0) + modify(1) + modify(2) << endl;
  }
}