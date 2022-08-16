#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

struct INFTY {
  const int64 infll = (1LL << 62) - 1;
  const int inf = (1 << 30) - 1;

  operator int64() { return infll; }

  operator int() { return inf; }
} inf;

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

int main() {
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;
  map< int, int > mp;
  for(auto &t : A) mp[t]++;
  int ret = 0, pos = -1;
  for(auto &p : mp) {
    if(chmax(ret, p.second)) pos = p.first;
  }
  vector< int > used(N);

  vector< tuple< int, int, int > > op;

  function< void(int, int) > dfs = [&](int idx, int d) {
    if(d == -1) {
      if(idx == 0) return;
    } else {
      if(idx + 1 == N) return;
    }
    if(used[idx + d]) return;
    if(A[idx + d] == pos) return;

    used[idx + d] = true;

    if(A[idx + d] < pos) {
      op.emplace_back(1, idx + d, idx);
    } else {
      op.emplace_back(2, idx + d, idx);
    }
    dfs(idx + d, d);
  };

  for(int i = 0; i < N; i++) {
    if(pos == A[i]) {
      used[i] = true;
      dfs(i, -1);
      dfs(i, 1);
    }
  }
  cout << op.size() << endl;
  for(auto& p : op){
    int a, b, c;
    tie(a, b, c) = p;
    cout << a << " " << b + 1 << " " << c + 1 << endl;
  }
}