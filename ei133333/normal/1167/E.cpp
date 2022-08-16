#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

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
  int N, X;
  cin >> N >> X;
  vector< int > A(N);
  cin >> A;
  vector< int > be[1000000];
  for(int i = 0; i < N; i++) {
    --A[i];
    be[A[i]].emplace_back(i);
  }
  vector< int > L(X, -1333), R(X, -1333);

  {
    int last = -1;
    bool ok = true;
    for(int i = 0; i < X; i++) {
      if(be[i].size()) {
        int F = be[i].front();
        if(last > F) {
          ok = false;
        } else {
          last = be[i].back();
        }
      }
      if(ok) {
        L[i] = last;
      }
    }
  }

  {
    int last = N;
    bool ok = true;
    for(int i = X - 1; i >= 0; i--) {
      if(be[i].size()) {
        int F = be[i].back();
        if(last < F) {
          ok = false;
        } else {
          last = be[i].front();
        }
      }
      if(ok) {
        R[i] = last;
      }
    }
  }


  int64 ret = 0;
  for(int i = 0; i < X; i++) { // [i
    int latte = i == 0 ? -1 : L[i - 1];
    if(latte == -1333) continue;

    int ok = X, ng = i-1;
    while(ok - ng > 1) {
      int j = (ok + ng) / 2;

      int malta = j + 1 == X ? N : R[j + 1];
      if(malta == -1333 || latte > malta) ng=j;
      else ok=j;
    }
    ret+=X-ok;
  }

  cout << ret << endl;
}