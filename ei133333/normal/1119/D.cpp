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

template< class T >
struct CumulativeSum
{
  vector< T > data;

  CumulativeSum(int sz) : data(sz, 0) {};

  void add(int k, T x)
  {
    data[k] += x;
  }

  void build()
  {
    for(int i = 1; i < data.size(); i++) {
      data[i] += data[i - 1];
    }
  }

  T query(int k)
  {
    if(k < 0) return (0);
    return (data[min(k, (int) data.size() - 1)]);
  }
};


int main() {
  int N, Q;
  cin >> N;
  vector< int64 > S(N);
  cin >> S;
  sort(begin(S), end(S));
  S.erase(unique(begin(S), end(S)), end(S));
  N = (int) S.size();

  vector< int64 > nxt_sa(N - 1);
  for(int i = 0; i + 1 < N; i++) {
    nxt_sa[i] = S[i + 1] - S[i];
  }
  sort(begin(nxt_sa), end(nxt_sa));
  CumulativeSum< int64 > sum(N-1);
  for(int i = 0; i < N-1; i++) {
    sum.add(i, nxt_sa[i]);
  }
  sum.build();


  cin >> Q;
  while(Q--) {
    int64 L, R;
    cin >> L >> R;
    ++R;
    int sz = lower_bound(begin(nxt_sa), end(nxt_sa), R - L) - begin(nxt_sa);
    int64 add = sum.query(sz - 1);
    add += 1LL * (nxt_sa.size() - sz + 1) * (R - L);
    cout << add << " ";
  }
  cout << endl;
}