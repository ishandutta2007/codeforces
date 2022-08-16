#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
// const int mod = 1e9 + 7;
//const int mod = 998244353;

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
  for(T &in: v) is >> in;
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
  for(auto &e: t) fill_v(e, v);
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

bool beet() {
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;
  vector< int > B[2]; // B[0]-=1, B[1]+=1
  string s;
  cin >> s;
  for(int i = 0; i < N; i++) {
    char c = s[i];
    B[c == 'R'].emplace_back(A[i]);
  }
  sort(begin(B[0]), end(B[0]));
  sort(begin(B[1]), end(B[1]));
  set< int > v;
  for(int i = 1; i <= N; i++) v.emplace(i);
  for(int i = 0; i < B[0].size(); i++) {
    int val = B[0][i];
    auto it = *v.begin();
    if(it > val) return false;
    v.erase(it);
  }
  for(int i = 0; i < (int) B[1].size(); i++) {
    int val = B[1][i];
    auto it = v.lower_bound(val);
    if(it == end(v)) return false;
    v.erase(it);
  }
  return true;
}

int main() {
  int t = 1;
  cin >> t;
  while(t--) if(beet()) cout << "YES\n"; else cout << "NO\n";
}